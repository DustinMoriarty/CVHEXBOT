#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include <QMainWindow>
#include <QPushButton>
#include <machine.h>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/types_c.h>



namespace Ui {
class robotcontrol;
}

class robotcontrol : public QMainWindow
{

    Q_OBJECT
public slots:
    void newframe(void);
    
public:

    explicit robotcontrol(QWidget *parent = 0);

    ~robotcontrol();

    void uisave(void);

    void uiopen(void);
    
private slots:

    void on_btnConnect_clicked();

    void on_btnTrack_clicked();

    void on_btnVision_clicked();

    void on_doubleSpinBoxCP_editingFinished();

    void on_doubleSpinBoxCI_editingFinished();

    void on_doubleSpinBoxCD_editingFinished();

    void on_spinBoxHMIN_editingFinished();

    void on_spinBoxSMIN_editingFinished();

    void on_spinBoxVMIN_editingFinished();

    void on_spinBoxHMAX_editingFinished();

    void on_spinBoxSMAX_editingFinished();

    void on_spinBoxVMAX_editingFinished();

    void UpdatePID();

    void UpdateThresh();

    void on_action_Save_triggered();

    void on_action_Open_triggered();

    void on_action_Close_triggered();

    void on_btnccw_clicked();

    void on_btncw_clicked();

    void on_btnfwd_clicked();

    void on_btnrev_clicked();

    void on_btnkillall_clicked();

    void on_spinBoxCam_editingFinished();

    void on_btnDance_clicked();

    void on_btnTiltLeft_clicked();

    void on_btnTiltRight_clicked();

    void on_pushTiltNone_clicked();

    void on_btnWave_clicked();

    void on_btnBellyFlop_clicked();

    void on_btncwNeck_clicked();

    void on_btnccwNeck_clicked();

    void on_ckbxPrepend_clicked();

    void on_spinBoxHMIN_valueChanged(int arg1);

    void on_spinBoxSMIN_valueChanged(int arg1);

    void on_spinBoxVMIN_valueChanged(int arg1);

    void on_spinBoxHMAX_valueChanged(int arg1);

    void on_spinBoxSMAX_valueChanged(int arg1);

    void on_spinBoxVMAX_valueChanged(int arg1);

    void on_spinBoxCam_valueChanged(const QString &arg1);

    void visionoff();

    void visionon();

    void connectbot();

    void disconnectbot();

    void trackon();

    void trackoff();




    //void on_btnConnect_clicked();

    void on_spinBoxNecRotate_valueChanged(int arg1);

    void on_centralWidget_destroyed();

    void on_lineEditTermCommand_editingFinished();

    void on_sldHmin_actionTriggered(int action);

    void on_spinBoxCam_valueChanged(int arg1);



    void on_doubleSpinBoxNoise_valueChanged(double arg1);

    void on_comboBoxTrackType_currentIndexChanged(int index);

    void on_comboBoxTrackType_activated(int index);

private:
    Ui::robotcontrol *ui;
    machine bot;
    machine bot2;


};

#endif // ROBOTCONTROL_H
