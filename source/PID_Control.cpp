#include "PID_Control.h"



PID_Control::PID_Control(void)
	: cp(0)
	, ci(0)
	, cd(0)
	, t(0)
	, P(0)
	, I(0)
	, D(0)
	, error(0)

{

}


PID_Control::~PID_Control(void)
{
}


// Set PID values
int PID_Control::setPID(double cprop, double cint, double cder)
{
	cp = cprop;
	ci = cint;
	cd = cder;
	return 0;
}



double PID_Control::step(double dt, double signal, double feedback)
{
	//declare variables
	double output = 0;
	double lasterror;
	lasterror = error;
	error = signal - feedback;
	// Assign PID values

	P = error;
	I = (error-lasterror)*dt + I;

    if (dt != 0) D = (error - lasterror)/dt;

    else

    {
        qDebug()<< "Warning: dt = 0, D ignored in PID";

        D = 0;

    }

    output = double(cp)*P + double(ci)*I + double(cd)*D;

    qDebug()<<"cp = "<< QString().number(cp,'g',4) << "ci = "<< QString().number(ci,'g',4)  << "cd = "<<QString().number(cd,'g',4);
    qDebug()<<"Output = " << QString().number(output,'g',4);

    return output;
}




int PID_Control::reset(void)
{
	P = 0;
	I = 0;
	D = 0;
	t = 0;
	return 0;
}
