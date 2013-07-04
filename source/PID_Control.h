#pragma once
#include <cmath>
#include <QString>
#include <QDebug>
#include <QApplication>

class PID_Control
{
private:
	//PID Coefficients
	double cp;
	double ci;
	double cd;
	// time in seconds
	double t;
	//Value of PID From Data
	double P;
	double I;
	double D;
	double error;

public:
	PID_Control(void);
	~PID_Control(void);
	// Set PID values
	double step(double dt, double signal, double feedback);
	int setPID(double CP, double CI, double CD);
	int reset(void);
};

