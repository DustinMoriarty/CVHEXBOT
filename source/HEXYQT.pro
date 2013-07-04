#-------------------------------------------------
#
# Project created by QtCreator 2013-05-06T15:02:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HEXYQT
TEMPLATE = app


SOURCES += main.cpp\
        robotcontrol.cpp \
    machine.cpp \
    PID_Control.cpp \
    vision.cpp \
    buffer.cpp \
    MatToQImage.cpp

HEADERS  += robotcontrol.h \
    machine.h \
    PID_Control.h \
    vision.h \
    buffer.h \
    MatToQImage.h

FORMS    += robotcontrol.ui

CONFIG += console

#Linux
## Edit the path below to match your system
INCLUDEPATH += /usr/include

## File names may be different note depending on version.

LIBS += -L/usr/include/libs
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

## Win32
## Edit the path below to match your system
## TO DO:  Make a successful build on windows
#INCLUDEPATH += C:/Users/DustinM/UserSoft/opencv/build/include
#LIBS += -LC:/Users/DustinM/UserSoft/opencv/build/x86/mingw/lib

## File names may be different note depending on version.
#LIBS += -lopencv_core244
#LIBS += -lopencv_imgproc244
#LIBS += -lopencv_highgui244
#LIBS += -lopencv_ml244
#LIBS += -lopencv_video244
#LIBS += -lopencv_features2d244
#LIBS += -lopencv_calib3d244
#LIBS += -lopencv_objdetect244
#LIBS += -lopencv_contrib244
#LIBS += -lopencv_legacy244
#LIBS += -lopencv_flann244


RESOURCES += \
    ../Python/python.qrc \
    ../icons/resources.qrc

OTHER_FILES += \
    ../icons/rotatecw.png \
    ../icons/rotateccw.png \
    ../icons/rightarrow.png \
    ../icons/off.png \
    ../icons/leftwarrow.png \
    ../icons/forwardarrow.png \
    ../icons/backwardarrow.png

