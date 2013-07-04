#include "vision.h"


using namespace cv;




//Initialization Function
vision::vision(QObject *parent) :
    QObject(parent)
  , posX(0)
  , posY(0)
  , visionon(false)
  , int_cam(0)
  , dt(0)
  , imagefound(false)
{
    qDebug() << "Constructing Instance of vision";
	//Set Default Threshold As Ugly Bright Green.  The Threshold Can Be Reset Using The SetThresh Function
    qDebug() << "Initializing Threshold Values";
    SetThresh(53, 100, 100, 83, 255, 255);
	//time(&timer);
	//time(&lasttimer);
	dt = 0;
	OutputString = new char [200];
    OutputString = " ";
    camcaptured = false;
    noise = 1;
    rawfrm = Mat();

    // Change To Private Later
    face_cascade_name = "haarcascade_frontalface_alt.xml";
    eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
    face_cascade;
    eyes_cascade;
    window_name = "Capture - Face detection";
    rng = RNG(12345);
    visionon = false;
    camcaptured = false;
    vcamcaptured = false;
    // Current Position
    posX = 0;
    posY = 0;
    dt = 1;
    // Last Position
    lastX = 0;
    lastY = 0;

    // Last 20 Positions
    position[20][2] = 0;
    // Integer For Camera Number
    int_cam = 0;
    SetThresh(0,0,0,255,255,255);

    bool imagefound = false;
    double noise = 1;
}

//Destruction Function
//vision::~vision(void)
//{
//    qDebug() << "Destroying Instance Of vision" ;
//    releasecam();

//}

// Set HSV Threshold Parameters
int vision::SetThresh(double Hmin, double Smin, double Vmin, double Hmax, double Smax, double Vmax)
{
	HSVmin = cvScalar(Hmin,Smin,Vmin);
	HSVmax = cvScalar(Hmax,Smax,Vmax);

	return 0;
}

int vision::GetThresh(double * buffer)
{
	for (int i=0;i<3;++i) 
	{
		buffer[i] = HSVmin.val[i];
		buffer[3 + i] = HSVmax.val[i];
	}
	*buffer;
	return 0;
}



// Turn On Vision
int vision::track(void)
{
    qDebug() << "Running vision::vision(void)";


    vcam();
    setvisionon(true);
    cvNamedWindow("video");
	cvNamedWindow("thresh");
	int i = 0;
    while(visionon && camcaptured)
    {
		int st = step();
		if (st != 0)
            setvisionon(false);
    }

	// We're done using the camera. Other applications can now use it
    releasevcam();
	cvDestroyAllWindows();
    qDebug()<<"Exiting Vision()";
	return 0;
	
}

//Turn On Vision and Specify Camera
int vision::track(int camera)
{
	int_cam = camera;
	vision();

	return 0;
}

int vision::track(bool loop)
{
	if (loop) 
		vision();
	else
		//Initialise Vision, but wait for outside control using step
		cam();

		// Couldn't get a device? Throw an error and quit
		if(!capture)
        {
            printf("Could not initialize capturing...\n");
			return -1;
        
		}
		cvNamedWindow("video");
		cvNamedWindow("thresh");
        setvisionon(true);
		//Vision Is Initialised, but an outside will 
        //now execute the visioning opperation using the step() function
	return 0;
}

// Aquire Thresholded Image Using HSVmin and HSVmax
IplImage* vision::GetThresholdedImage(IplImage* img)
{
	// Convert the image into an HSV image
    // Currently Optimized to vision a green batteries without shape.  Vertex identification is not added.
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

	
	cvInRangeS(imgHSV, HSVmin, HSVmax, imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

// Turn Off Vision (Redundant Function To setvisionon())
int vision::DisconnectVision(void)
{
    setvisionon(false);
	return 0;
}

// Get visionon
bool vision::getvisionon(void)
{
	return visionon;
}

// Set visionon
void vision::setvisionon(bool vo)
{
    visionon = vo;
    if (vo) qDebug()<<"Setting Vision On To True";
    else qDebug()<<"Setting Vision On To False";
}

//Get position
int* vision::getposition(void)
{
	return *position;
}

long double vision::getdt(void)
{
	return dt;
}

// sets camera number
int vision::setcamera(int camera)
{
    vision::DisconnectVision();
	int_cam = camera;

	return 0;
}



// // Execute Single Time Step of Step Function
int vision::step(void)
{
        grabframe();
        // Will hold a frame captured from the camera
        threshdetector();


	return 0;
}

void vision::threshdetector()
{
    // Holding the last and current ball positions
    double moment10;
    double moment01;
    double area;

    int imagewidth = buf.getwidth();
    int imageheight = buf.getheight();
    int TargetX = imagewidth/2;
    int TargetY = imageheight/2;

    Mat f;
    buf.frame.copyTo(f);
    IplImage iplframe0 = f;
    IplImage * iplframe = &iplframe0;

    // Get Thresholded Image
    IplImage* imgYellowThresh = GetThresholdedImage(iplframe);
    CvMoments *moments = (CvMoments*)malloc(sizeof(CvMoments));
    cvMoments(imgYellowThresh, moments, 1);
    moment10 = cvGetSpatialMoment(moments, 1, 0);
    moment01 = cvGetSpatialMoment(moments, 0, 1);
    area = cvGetCentralMoment(moments, 0, 0);
    lastX = posX;
    lastY = posY;
    lasttimer = timer;
    ftime(&timer);
    dt = difftime(timer.time,lasttimer.time)*1000 + timer.millitm - lasttimer.millitm;

    CvScalar brightness;
    brightness = cv::mean(cv::Mat(imgYellowThresh));
    SetImageFound(brightness.val[0] > noise);
    if (GetImageFound())
    {
        posX = moment10/area;
        posY = moment01/area;
        int n = 20;
        for (int i=0;i<=(n-1);i++)
        {
            position[i][0] = position[i-1][0];
            position[i][1] = position[i-1][1];
        }

        position[0][0] = posX;
        position[0][1] = posY;
    }



    // Add Moving Crosshairs In Image
    // Add Crosshairs For Moving Target
    cvCircle(iplframe,cvPoint(posX,posY),10,cvScalar(0,255,0));
    cvLine(iplframe,cvPoint(posX,posY + 50),cvPoint(posX,posY-50),cvScalar(0,255,255));
    cvLine(iplframe,cvPoint(posX + 50,posY),cvPoint(posX - 50,posY),cvScalar(0,255,255));

    // Temporary Method
    rawfrm = Mat(iplframe);
    buf.updatebuffer(rawfrm);

    cvShowImage("thresh", imgYellowThresh);

    // Release the thresholded image
    cvReleaseImage(&imgYellowThresh);
 \

    delete moments;

}


// // Turn On Camera And Start Capturing Images
int vision::cam(int camera)
{
	int_cam = camera;
	cam();
		
	return 0;
}

int vision::cam(void)
{


    if (camcaptured)
    {
        // Turn Off Vision
        setvisionon(false);
        // Let Anything using the Camera Exit
        waitKey(10);
        // Release Camera
        releasecam();
        capture = 0;
    }
    qDebug()<<"Capturing From Camera " << QString::number(int_cam);
    capture = cvCaptureFromCAM(int_cam);


    // Checking If Capture was successful
    if(!capture)
    {
        setvisionon(false);
        printf("Could not initialize capturing...\n");
        camcaptured = false;
        return 1;

    }
    else
    {
        qDebug()<<"Capture From Camera Successful";
        camcaptured = true;
    }
	return 0;
}


int vision::vcam(void)
{


    if (vcamcaptured)
    {
        // Turn Off Vision
        setvisionon(false);
        // Let Anything using the Camera Exit
        waitKey(10);
        // Release Camera
        vcapture.release();
        capture = 0;
    }
    qDebug()<<"Capturing From Camera " << QString::number(int_cam);
    vcapture = VideoCapture(int_cam);

    // Checking If Capture was successful
    if(!vcapture.isOpened())
    {
        setvisionon(false);
        printf("Could not initialize capturing...\n");
        vcamcaptured = false;
        return 1;

    }
    else
    {
        qDebug()<<"Capture From Camera Successful";
        vcamcaptured = true;
    }
    return 0;
}

void vision::releasecam(void)
{
    qDebug()<<"Releasing Capture";
    cvReleaseCapture(&capture);
    camcaptured = false;

}

void vision::releasevcam(void)
{
    qDebug()<<"Releasing Capture";
    vcapture.release();
    vcamcaptured = false;

}

// Get X Position
int vision::getposX(void)
{
	return posX;
}

// Get X Position
int vision::getposY(void)
{
    return posY;
}


void vision::SetImageFound(bool imgfound)
{
	imagefound = imgfound;
}


bool vision::GetImageFound(void)
{
	return imagefound;
}

void vision::SetOutputString(char * OutStr)
{
	OutputString = OutStr;
}

char * vision::GetOutString(void)
{
	return OutputString;
}

bool vision::GetCamCaptured()
{
    return camcaptured;
}

bool vision::GetVCamCaptured()
{
    return vcamcaptured;
}

void vision::setnoise(double noisearg)
{
    noise = noisearg;

}

void vision::facestep()
{

    grabframe();
    facedetector();

}

void vision::grabframe(void)
{

    vcapture.grab();
    vcapture.retrieve(rawfrm);
    buf.updatebuffer(rawfrm);

}

void vision::facedetector(void)
{
    std::vector<Rect> faces;
    Mat frame_gray;
    if (face_cascade.empty()) startfacedetector();
    cvtColor( buf.frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
    SetImageFound( !faces.empty());

    if (GetImageFound())
    {
        qDebug()<<"Face Detected";
        lastX = posX;
        lastY = posY;
        posX = faces[0].x;

        posY = faces[0].y;
        lasttimer = timer;
        ftime(&timer);
        dt = difftime(timer.time,lasttimer.time)*1000 + timer.millitm - lasttimer.millitm;

        for( int i = 0; i < faces.size(); i++ )
        {
            Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
            ellipse( buf.frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 0, 0, 255 ), 4, 8, 0 );

//            faceROI = frame_gray( faces[i] );
//            std::vector<Rect> eyes;

//            //-- In each face, detect eyes
//            eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );

//            for( int j = 0; j < eyes.size(); j++ )
//            {
//                Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
//                int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
//                circle( buf.frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
//          }
        }
    }
}

bool vision::startfacedetector()
{
    // Loads Cascade Training Data
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return false; };
    //if( !eyes_cascade.load( eye.eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return false; };
    return true;
}
