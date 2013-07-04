#ifndef MACHINE_H
#define MACHINE_H
#include "vision.h"
#include "PID_Control.h"
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/types_c.h>
#include <QObject>
#include <QThread>
#include <QProcess>
#include <time.h>
#include <stdio.h>


class machine : public QObject
{
    Q_OBJECT
    QThread ConnectionThread;



private:
	bool connectionon;
    int tracktype;
    bool trackon;

public:
    explicit machine(QObject *parent = 0);
    //machine(QObject *parent);
    ~machine(void);
    //Object To Handle Vision
    vision eye;
    // PID Control
    PID_Control PID;
    //  Process For POMOCO
    QProcess cnct;
    // Move machine Forward By parameter q.  Negative Values of q cause machine to move backward.
	int moveforward(double q);
    int DisconnectBot(void);
    int topomoco(std::string str);
    // Rotate Neck By Parameter q, where q is in degrees counterclockwise.
    int rotateneck(double q);
    // rotate left by parameter q, where q is in degrees.  Negative values of q will cause the machine to rotate right
    int rotateleft(double q);
    void getup();
    void killall();
    void reset();
    void wave();
    void bellyflop();
    void tiltleft();
    void tiltright();
    void tiltnone();
    void dance();

    // machine To Follow With Neck
    int machinetrack(double cp, double ci, double cd);
    int machinetrack();
	// determine if connection is on
    bool getconnectionon(void);
    void setdt(double DTarg);
    void settracktype(int);
    int gettracktype();
    bool gettrackon();


signals:
    void newframe(void);

public slots:
    void ConnectBot(void);
    void ConnectBot(QString cmd);
    void settrackon(bool);

};

#endif

