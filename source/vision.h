#pragma once
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/types_c.h>
#include "opencv2/objdetect/objdetect.hpp"


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <sys/timeb.h>
#include <QDebug>
#include <QObject>

#include <buffer.h>

using namespace cv;

class vision : public QObject
{
    Q_OBJECT

private:
	timeb timer;
	timeb lasttimer;
	bool visionon;
    bool camcaptured;
    bool vcamcaptured;
	// Current Position
	int posX;
	int posY;
	double dt;
	// Last Position
	int lastX;
	int lastY;

	// Last 20 Positions
	int position[20][2];
	// Integer For Camera Number
	int int_cam;
	CvScalar HSVmin;
	CvScalar HSVmax;
	// Camera Capture
    CvCapture* capture;  // To Be Replaced with videocapture method
    VideoCapture vcapture;
    Mat rawfrm;

	// Image With Scribble Data For Tracking Visualization
	IplImage* imgScribble;
    bool imagefound;
    double noise;



public:

    buffer buf;
    explicit vision(QObject *parent = 0);
    //~vision(void);
	// Get X Position
	int getposX(void);
    // Get X Position
    int getposY(void);

	// Set HSV Threshold Parameters
	int SetThresh(double Hmin, double Smin, double Vmin, double Hmax, double Smax, double Vmax);
	// Get HSV Threshold Parameters
	int GetThresh(double * buffer);
	// Start Tracking
    int track(void);
    int track(int camera);
    int track(bool loop);
	IplImage* GetThresholdedImage(IplImage* img);
	// Stop Tracking
	int DisconnectVision(void);
	// Determine of Vision Is On
	bool getvisionon(void);
    // Set Visionon
    void setvisionon(bool);
	// get position
	int* getposition(void);
	//get the time difference
	long double getdt(void);
	// sets camera number
	int setcamera(int camera = -1);
	// Execute Single Time Step of Step Function
	int step(void);
	// Turn On Camera And Start Capturing Images Camera is taken from int_cam
	int cam(void);
	// Turn On Camera And Start Capturing Images, Specify Camera As Well
	int cam(int camera);
    int vcam(void);
    void releasecam(void);
    void releasevcam(void);
    char *OutputString;
	void SetImageFound(bool imgfound);
	bool GetImageFound(void);
	void SetOutputString(char * OutStr);
	char *GetOutString(void);
    bool GetCamCaptured(void);
    bool GetVCamCaptured(void);
    void setnoise(double noisearg);
    void facestep(void);
    void grabframe(void);
    void facedetector(void);
    bool startfacedetector(void);
    void threshdetector(void);

    // Change To Private Later
    String face_cascade_name;
    String eyes_cascade_name;
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;
    std::string window_name;
    RNG  rng;



};
