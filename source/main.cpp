#include "robotcontrol.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    robotcontrol w;
    w.show();
    
    return a.exec();
}
