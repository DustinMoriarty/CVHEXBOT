#include "robotcontrol.h"
#include "ui_robotcontrol.h"
#include <QMessageBox>
#include <QDebug>


robotcontrol::robotcontrol(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::robotcontrol)
{

    ui->setupUi(this);
    ui->btnConnect->setText("Connect");
    ui->btnTrack->setEnabled(false);
    //bot.eye.DisconnectVision();
    ui->btnVision->setText("Vision On");
    ui->btnTrack->setText("Track On");
    qDebug() << "Initializing robotcontrol GUI";
    UpdateThresh();
    UpdatePID();
    visionoff();
    trackoff();
    disconnectbot();


    //connect(this->bot,SIGNAL(newframe()),this,SLOT(newframe()));


    //connect(bot.eye.buf,SIGNAL(updateframe(Mat&)),this,SLOT(updateFrame(Mat&)));

}

robotcontrol::~robotcontrol()
{
    bot.killall();
    bot.DisconnectBot();
    bot.eye.DisconnectVision();
    delete ui;

}


void robotcontrol::on_btnConnect_clicked()
{
    if (bot.getconnectionon())
    {
        disconnectbot();

    }
    else
    {

        connectbot();

    }

}
void robotcontrol::on_doubleSpinBoxCP_editingFinished()
{
    UpdatePID();

}

void robotcontrol::on_doubleSpinBoxCI_editingFinished()
{
    UpdatePID();


}

void robotcontrol::on_doubleSpinBoxCD_editingFinished()
{
    UpdatePID();
}


void robotcontrol::on_spinBoxHMIN_editingFinished()
{
    UpdateThresh();
}

void robotcontrol::on_spinBoxSMIN_editingFinished()
{
    UpdateThresh();
}

void robotcontrol::on_spinBoxVMIN_editingFinished()
{
    UpdateThresh();
}


void robotcontrol::on_spinBoxHMAX_editingFinished()
{
    UpdateThresh();
}

void robotcontrol::on_spinBoxSMAX_editingFinished()
{
    UpdateThresh();
}


void robotcontrol::on_spinBoxVMAX_editingFinished()
{
    UpdateThresh();
}



// Save Data From UI For Next Session
void robotcontrol::on_action_Save_triggered()
{
    uisave();
}

void robotcontrol::on_action_Open_triggered()
{
    uiopen();
}

void robotcontrol::on_action_Close_triggered()
{
    close();
}

void robotcontrol::on_btnccw_clicked()
{
    double q = ui->spinBoxBodyRotate->value();
    bot.rotateleft(q);
}

void robotcontrol::on_btncw_clicked()
{
    double q = ui->spinBoxBodyRotate->value();
    bot.rotateleft((-1)*q);
}


void robotcontrol::on_btnfwd_clicked()
{
    bot.moveforward(20);
}

void robotcontrol::on_btnrev_clicked()
{
    bot.moveforward(-20);
}

void robotcontrol::on_btnkillall_clicked()
{
    bot.killall();
}

void robotcontrol::on_spinBoxCam_editingFinished()
{

}

void robotcontrol::on_btnDance_clicked()
{
    bot.dance();
}

void robotcontrol::on_btnTiltLeft_clicked()
{
    bot.tiltleft();
}

void robotcontrol::on_btnTiltRight_clicked()
{
    bot.tiltright();
}

void robotcontrol::on_pushTiltNone_clicked()
{
    bot.tiltnone();
}

void robotcontrol::on_btnWave_clicked()
{
    bot.wave();
}

void robotcontrol::on_btnBellyFlop_clicked()
{
    bot.bellyflop();
}

void robotcontrol::on_btncwNeck_clicked()
{
    double q = ui->spinBoxNecRotate->value();
    bot.rotateneck((-1) * q);
}

void robotcontrol::on_btnccwNeck_clicked()
{
    double q = ui->spinBoxNecRotate->value();
    bot.rotateneck(q);

}

void robotcontrol::on_ckbxPrepend_clicked()
{
    UpdateThresh();
}

void robotcontrol::on_spinBoxHMIN_valueChanged(int arg1)
{
    UpdateThresh();
}

void robotcontrol::on_spinBoxSMIN_valueChanged(int arg1)
{
    UpdateThresh();
}

void robotcontrol::on_spinBoxVMIN_valueChanged(int arg1)
{
    UpdateThresh();
}

void robotcontrol::on_spinBoxHMAX_valueChanged(int arg1)
{
    UpdateThresh();
}

void robotcontrol::on_spinBoxSMAX_valueChanged(int arg1)
{
    UpdateThresh();
}

void robotcontrol::on_spinBoxVMAX_valueChanged(int arg1)
{
    UpdateThresh();
}


// Change camera
void robotcontrol::on_spinBoxCam_valueChanged(const QString &arg1)
{
    visionoff();
    int cam = ui->spinBoxCam->value();
    bot.eye.setcamera(cam);
}


// Open XML File of UI Data
void robotcontrol::uiopen()
{

    //Close Current Vision Processes Before Changing Values
    visionoff();

    // Initialize with current values so that if all else fales, we keep what we have.
    double cp = ui->doubleSpinBoxCP->value();
    double ci = ui->doubleSpinBoxCI->value();
    double cd = ui->doubleSpinBoxCD->value();

    int hmin = ui->spinBoxHMIN->value();
    int hmax = ui->spinBoxHMAX->value();
    int smin = ui->spinBoxSMIN->value();
    int smax = ui->spinBoxSMAX->value();
    int vmin = ui->spinBoxVMIN->value();
    int vmax = ui->spinBoxVMAX->value();

    QString term = ui->lineEditTermCommand->text();

    int cam = ui->spinBoxCam->value();

    // OPEN XML File With Dialog For Writing
    QString frstr = QFileDialog::getOpenFileName(this,tr("Config File"),tr(""));
    QFile * frfile = new QFile(frstr);
        if (!frfile->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"File Can Not Be Read";
            return;
        }


    QXmlStreamReader fr(frfile);
    qDebug()<< "Created Stream Reader";
    //Parse the XML until we reach end of it

    while((!fr.atEnd() && !fr.hasError()))
    {
        // Read next element
        fr.readNext();
        qDebug()<<"Reading Next Line";
        qDebug() << "Token = "<< fr.tokenString();

        //If token is just StartDocument - go to next
        if(fr.tokenType() == QXmlStreamReader::StartDocument)
        {
            qDebug()<<"Found Document Start";
            continue;
        }


        //If token is StartElement - read it
        if(fr.tokenType() == QXmlStreamReader::StartElement)
        {
            qDebug()<<"Found Element";
            if(fr.name() == "SETTINGS")
                continue;
            if(fr.name() == "cp")
                qDebug()<< "Found CP = " << fr.readElementText();
            else if(fr.name() == "ci")
                ci = fr.readElementText().toDouble();

            else if(fr.name() == "cd")
                cd = fr.readElementText().toDouble();
            else if(fr.name() == "hmin")
                hmin = fr.readElementText().toInt();
            else if(fr.name() == "hmax")
                hmax = fr.readElementText().toInt();
            else if(fr.name() == "smin")
                smin = fr.readElementText().toInt();
            else if(fr.name() == "smax")
                smax = fr.readElementText().toInt();
            else if(fr.name() == "vmin")
                vmin = fr.readElementText().toInt();
            else if(fr.name() == "vmax")
                vmax = fr.readElementText().toInt();
            else if(fr.name() == "term")
                term = fr.readElementText();
            else if(fr.name() == "cam" )
                cam = fr.readElementText().toInt();
            else
            qDebug()<< "Element Found But Not Recognized";
        }
    }

    fr.clear();
    frfile->close();

    // Update UI with values from XML file
    ui->doubleSpinBoxCP->setValue(cp);
    ui->doubleSpinBoxCI->setValue(ci);
    ui->doubleSpinBoxCD->setValue(cd);
    ui->spinBoxHMIN->setValue(hmin);
    ui->spinBoxHMAX->setValue(hmax);
    ui->spinBoxSMIN->setValue(smin);
    ui->spinBoxSMAX->setValue(smax);
    ui->spinBoxVMIN->setValue(vmin);
    ui->spinBoxVMAX->setValue(vmax);
    ui->lineEditTermCommand->setText(term);
    ui->spinBoxCam->setValue(cam);
}


//Save XML File of UI Data
void robotcontrol::uisave()
{
    // Extract Data From UI
    double cp = ui->doubleSpinBoxCP->value();
    double ci = ui->doubleSpinBoxCI->value();
    double cd = ui->doubleSpinBoxCD->value();
    int hmin = ui->spinBoxHMIN->value();
    int hmax = ui->spinBoxHMAX->value();
    int smin = ui->spinBoxSMIN->value();
    int smax = ui->spinBoxSMAX->value();
    int vmin = ui->spinBoxVMIN->value();
    int vmax = ui->spinBoxVMAX->value();

    QString term = ui->lineEditTermCommand->text();
    int cam = ui->spinBoxCam->value();

    // OPEN XML File With Dialog For Writing
    QString fwstr = QFileDialog::getSaveFileName(this,tr("Config File"),tr("myhexyqtconfig.xml"));
    QFile fwfile(fwstr);
    fwfile.open(QIODevice::WriteOnly);
    QXmlStreamWriter fw(&fwfile);

    /*
     *Write Data To XML File.
     *Add Additional Data Below.
     *Update Open Command To Read Any New Data.
     */
    fw.setAutoFormatting(true);
    fw.writeStartDocument();
    fw.writeStartElement("SETTINGS");
    fw.writeTextElement("cp",QString::number(cp));
    fw.writeTextElement("ci",QString::number(ci));
    fw.writeTextElement("cd",QString::number(cd));
    fw.writeTextElement("hmin",QString::number(hmin));
    fw.writeTextElement("hmax",QString::number(hmax));
    fw.writeTextElement("smin",QString::number(smin));
    fw.writeTextElement("smax",QString::number(smax));
    fw.writeTextElement("vmin",QString::number(vmin));
    fw.writeTextElement("vmax",QString::number(vmax));
    fw.writeTextElement("term",term);
    fw.writeTextElement("cam",QString::number(cam));
    fw.writeEndElement();
    fw.writeEndDocument();

    fwfile.close();
}

//Update PID
void robotcontrol::UpdatePID()
{
    qDebug()<<"Updating PID";
    double cp;
    double ci;
    double cd;

    cp = ui->doubleSpinBoxCP->value();
    ci = ui->doubleSpinBoxCI->value();
    cd = ui->doubleSpinBoxCD->value();
    bot.PID.setPID(cp,ci,cd);
    qDebug()<<"PID Updated";
}

//Update Threshold From Spinbox
void robotcontrol::UpdateThresh()
{
    int hmin = ui->spinBoxHMIN->value();
    int hmax = ui->spinBoxHMAX->value();
    int smin = ui->spinBoxSMIN->value();
    int smax = ui->spinBoxSMAX->value();
    int vmin = ui->spinBoxVMIN->value();
    int vmax = ui->spinBoxVMAX->value();
    double noise = ui->doubleSpinBoxNoise->value();



    bot.eye.SetThresh(hmin,smin,vmin,hmax,smax,vmax);
    bot.eye.setnoise(noise);
}

void robotcontrol::connectbot()
{

    //Turn On Connection

    bool prepend = ui->ckbxPrepend->isChecked();
    QString term = ui->lineEditTermCommand->text();
    term.append(" ");

    if (prepend)
    {
        bot.ConnectBot(term);
    }
    else
    {
        bot.ConnectBot();


    }
    ui->btnConnect->setText("Disconnect");
    ui->btnTrack->setEnabled(true);



}

void robotcontrol::disconnectbot()
{
    //Turn Off Connection
    bot.DisconnectBot();
    bot.eye.DisconnectVision();
    ui->btnConnect->setText("Connect");
    ui->btnTrack->setEnabled(false);
    ui->btnTrack->setText("Track On");
}

//void robotcontrol::on_btnConnect_clicked()
//{

//}

void robotcontrol::on_spinBoxNecRotate_valueChanged(int arg1)
{

}

void robotcontrol::on_centralWidget_destroyed()
{

}

void robotcontrol::on_lineEditTermCommand_editingFinished()
{

}

void robotcontrol::on_sldHmin_actionTriggered(int action)
{

}

void robotcontrol::on_spinBoxCam_valueChanged(int arg1)
{

}


void robotcontrol::on_btnTrack_clicked()
{
    if (bot.eye.getvisionon())
    {
        trackoff();
    }
    else
    {
        trackon();
    }

}

void robotcontrol::trackon()
{
    // Turn On Tracking
    UpdatePID();
    visionoff();

    ui->btnVision->setText("Vision Off");
    ui->btnTrack->setText("Track Off");
    bot.settrackon(true);

    bot.machinetrack();

    // Check To See If Turning On Tracking And Vision was Successful
    if (bot.eye.getvisionon() && bot.eye.GetCamCaptured())
    {
        ui->btnVision->setText("Vision Off");
        ui->btnTrack->setText("Track Off");
    }
    else
    {
        ui->btnVision->setText("Vision On");
        ui->btnTrack->setText("Track On");
        qDebug()<<"Attempt To Turn On Vision Failed";
        if (!(bot.eye.getvisionon())) qDebug() <<"For Unknown Reasons (bot.eye.getvisionon() returns false)";
        if (!(bot.eye.GetCamCaptured())) qDebug() << "Camera Would Not Turn On.  Try A Different Camera";

    }
}

void robotcontrol::trackoff()
{
    visionoff();
    bot.settrackon(false);
}


void robotcontrol::on_btnVision_clicked()
{
    qDebug()<< QString(bot.eye.getvisionon());
    if (bot.eye.getvisionon()) visionoff();
    else visionon();

}


void robotcontrol::visionoff()
{
    // Turn Off Vision
    ui->btnVision->setText("Vision On");
    ui->btnTrack->setText("Track On");
    bot.eye.DisconnectVision();
    bot.settrackon(false);
}


void robotcontrol::visionon()
{
    // Turn On Vision
    ui->btnVision->setText("Vision Off");
    bot.eye.DisconnectVision();
    bot.machinetrack();

    cv::waitKey(10);

    // Check To See If Turning On Vision was Successful
    if (bot.eye.getvisionon() && bot.eye.GetCamCaptured())
    {
        ui->btnVision->setText("Vision Off");
    }
    else
    {
        ui->btnVision->setText("Vision On");
        ui->btnTrack->setText("Track On");
    }

}



void robotcontrol::on_doubleSpinBoxNoise_valueChanged(double arg1)
{
    UpdateThresh();

}



void robotcontrol::on_comboBoxTrackType_currentIndexChanged(int index)
{

    bot.settracktype(index);
}

void robotcontrol::on_comboBoxTrackType_activated(int index)
{
     bot.settracktype(index);
}

void robotcontrol::newframe()
{
    qDebug()<<"Buffer Updated";
}
