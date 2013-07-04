#include <machine.h>



machine::machine(QObject *parent):
    QObject(parent)
{
    qDebug()<<"Constructing New Instance of Machine";
    remove("Python/cpp2py.txt");
    connectionon = false;
    //machine::eye = track();
    PID = PID_Control();
    //cnct = new QProcess();
    connectionon = false;
    tracktype = false;
    trackon = false;
}


machine::~machine(void)
{
    qDebug()<<"Destroying Instance of Machine";
    machine::DisconnectBot();
    cv::waitKey(10);
    remove("Python/cpp2py.txt");
}


// Move machine Forward By parameter q.  Negative Values of q cause machine to move backward.
int machine::moveforward(double q)
{
	char str [30];
    sprintf(str,"hexy.moveforward(%3.3f)",q);
    machine::topomoco(std::string(str));
	return 0;
}

// Rotate Neck By Parameter q, where q is in degrees counterclockwise.
int machine::rotateneck(double q)
{
	char str [30];
	sprintf(str,"hexy.neck.set(%3.3f)",q);
    machine::topomoco(std::string(str));
	return 0;
}

// rotate left by parameter q, where q is in degrees.  Negative values of q will cause the machine to rotate right
int machine::rotateleft(double q)
{
	char str [30];
    sprintf(str,"hexy.rotateleft(%f)",q);
    machine::topomoco(std::string(str));
	return 0;
}

void machine::getup()
{

    topomoco(std::string("hexy.getup()"));
}

void machine::killall()\
{
    topomoco(std::string("hexy.killall()"));
}

void machine::reset()
{
    topomoco(std::string("hexy.reset()"));
}

void machine::wave()
{
    topomoco(std::string("hexy.wave()"));
}

void machine::bellyflop()
{
    topomoco(std::string("hexy.bellyflop()"));\
}

void machine::tiltleft()
{
    topomoco(std::string("hexy.tiltleft()"));
}

void machine::tiltright()
{
    topomoco(std::string("hexy.tiltright()"));

}

void machine::tiltnone()
{
    topomoco(std::string("hexy.none()"));

}

void machine::dance()
{
    machine::topomoco(std::string("hexy.dance()"));
}

int machine::topomoco(std::string str)

{
    qDebug()<< "Sending Command To PoMoCo" << QString(str.c_str());

	remove("Python/cpp2py.txt");
    FILE* fw = fopen("Python/cpp2py.txt","wt");
    fprintf(fw, "%s",  str.c_str());
	fclose(fw);
    //cv::waitKey(10);

	return 0;
}

void machine::ConnectBot(void)
{
    qDebug()<< "Connecting To Robot";
    remove("Python/cpp2py.txt");
    QString cnctstr = "python -i Python/hexyvision2.py";
    cnct.start(cnctstr);
    connectionon = true;
}

void machine::ConnectBot(QString cmd)
{
    qDebug()<<"Connecting To Robot and Prepending Command" << cmd;
    remove("Python/cpp2py.txt");
    QString cnctstr = "python -i Python/hexyvision2.py";
    cnctstr.prepend(cmd);
    cnct.start(cnctstr);
    connectionon = true;
}


int machine::DisconnectBot(void)
{
    qDebug()<<"Disconnecting Robot";
    topomoco(std::string("q"));
    connectionon = false;
    cnct.terminate();
	return 0;
}



int machine::machinetrack()
{

    eye.DisconnectVision();
    double posX = 0;
    double posY = 0;
    double dt = 0;
    double output = 0;
    double neckposition = 0;
    char outstring[200];
    int imgwidth;
    int imgheight;
    int targetX;\
    int targetY;
    int error;
    PID.reset();
    time_t lastisawyou;
    int dtmissedyou;
    time_t lastimissedyou;
    int dtsawyou;
    time_t wavetime;
    double PIDthresh = 2;
    char outtext [50];


    if (gettrackon())
    {
        // If The Robot Will Be Tracking, Do A Warmup to say hi.
        qDebug()<<"Beginning Tracking";
        machine::rotateneck(20);
        machine::rotateneck(-20);
        machine::rotateneck(0);
        getup();
        killall();
        waitKey(20);
        qDebug()<<"Entering Tracking Loop";
    }
    eye.vcam();
    eye.setvisionon(true);

    switch (tracktype)
    {
    case (0):

        // Any Loop Priming For Thresholding Can Go Here.
        break;

    case (1):

        // Face Detection Loop Priming
        //Load the cascades
        if (!eye.startfacedetector()) return -1;
        break;
    }





    while (eye.getvisionon() && eye.GetVCamCaptured())
    {
        if (tracktype == 0) eye.step();
        else if (tracktype == 1) eye.facestep();

        if (gettrackon())
        {
            //If Tracking is on, move the robot

            if (eye.GetImageFound())
            {

                //imgsize = eye.buf.frame.size();
;
                imgwidth = eye.buf.getwidth();
                imgheight = eye.buf.getheight();
                targetX = std::floor(imgwidth*0.5);
                targetY = std::floor(imgheight*0.5);
                posX = eye.getposX();
                posY = eye.getposY();
                error = posX - targetX;
                qDebug()<<"PosX = "<<QString().number(posX);
                dt = eye.getdt();
                output = PID.step(dt,0,error);


                if (output > PIDthresh)
                {
                    output = PIDthresh;
                    qDebug()<< "Warning: PID output Truncated";
                }
                if (output < -PIDthresh)
                {
                    output = -PIDthresh;
                    qDebug()<< "Warning: PID output Truncated";
                }

                neckposition = neckposition + output;
                if (neckposition >= 180) neckposition = neckposition - 360;
                if (neckposition < (-180)) neckposition = neckposition + 360;
                sprintf(outstring,"PID Output = %3.4f deg Neck Output = %3.4f deg", output, neckposition);

                eye.SetOutputString(outstring);
                rotateneck(neckposition);

                // Update time of last image found
                time(&lastisawyou);

                dtsawyou = difftime(lastisawyou,lastimissedyou);

                // If I have been looking at you for a while but I have not waved recently, lets say Hi
                if (dtsawyou>2 && difftime(lastisawyou,wavetime)>10 && abs(neckposition)<=30)
                {

                    wave();
                    getup();

                    time(&wavetime);

                }

                // Correct With Body if angle is getting large
                if (abs(neckposition)>30 && dtsawyou > 3)
                {
                    if (abs(neckposition) <= 30)
                    {
                        rotateleft(neckposition);
                        rotateneck(-neckposition);
                        neckposition = 0;
                    }
                    else if (neckposition<(-30))
                    {
                        rotateleft(-30);
                        neckposition = neckposition + 30;
                    }
                    else if (neckposition > (50))
                    {
                        rotateleft(30);
                        neckposition = neckposition - 30;
                    }
                }
                rotateneck(neckposition);
            }

            else
            {
                // Update the time since I last couldn't find you
                time(&lastimissedyou);


                dtmissedyou = difftime(lastimissedyou,lastisawyou);
                if (dtmissedyou >= 3 && dtmissedyou < 6)
                {
                    if (error<0) neckposition += -0.3;
                    else neckposition += 0.3;
                    rotateneck(neckposition);
                }
                else if (dtmissedyou >= 6 && dtmissedyou < 10)
                {
                    if (error<0) neckposition += -2;
                    else neckposition += 2;


                }
                // Make it go the other way if it is looking back and forth and hits an extreame.
                if (abs(neckposition) > 45 ) error = -error;
                rotateneck(neckposition);

            }
            if (neckposition >= 120) neckposition = 120;
            if (neckposition < (-120)) neckposition = -120;
            rotateneck(neckposition);

        }


        sprintf(outtext,"Pos X = %f  Pos Y = %f",  posX, posY);
        cv::putText(eye.buf.frame,"Hexy Vision",cvPoint(10,10),FONT_HERSHEY_SIMPLEX,0.5,0.5);
        cv::putText(eye.buf.frame,outtext,cvPoint(10,20),FONT_HERSHEY_SIMPLEX,0.5,0.5);
        if (eye.GetImageFound()) cv::putText(eye.buf.frame,"Object Detected",cvPoint(10,30),FONT_HERSHEY_SIMPLEX,0.5,0.5);

        // Add Crosshairs In Image

        cv::circle(eye.buf.frame,cvPoint(targetX,targetY),10,cvScalar(0,255,0));
        cv::line(eye.buf.frame,cvPoint(targetX,targetY + 20),cvPoint(targetX,targetY-20),cvScalar(0,255,0));
        cv::line(eye.buf.frame,cvPoint(targetX + 20,targetY),cvPoint(targetX - 20,targetY),cvScalar(0,255,0));

        imshow("Vision",eye.buf.frame);

        waitKey(10);
    }
    eye.releasevcam();

    //Turn Of Vision Signal.  It Should Already Be Off By Now.
    eye.setvisionon(false);
    //    }
    //    }
    qDebug()<<"Vision Exiting";
    return 0;
}


// determine if connection is on
bool machine::getconnectionon(void)
{

    return machine::connectionon;
}

void machine::settracktype(int type)
{
    tracktype = type;
}

int machine::gettracktype()
{

    return tracktype;
}

void machine::settrackon(bool ton)
{
    trackon = ton;
    qDebug()<<"Track on set to ";
    if (trackon) qDebug()<<"True";
    else qDebug()<<"False";
}

bool machine::gettrackon()
{
    return trackon;
}






