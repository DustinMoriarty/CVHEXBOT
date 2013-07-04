/********************************************************************************
** Form generated from reading UI file 'robotcontrol.ui'
**
** Created: Tue May 7 00:43:11 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTCONTROL_H
#define UI_ROBOTCONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_robotcontrol
{
public:
    QAction *action_Save;
    QAction *action_Open;
    QAction *action_Close;
    QAction *action_Exit;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabMotionCntrl;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QPushButton *btnDance;
    QPushButton *btnWave;
    QPushButton *btnTiltLeft;
    QPushButton *btnTiltRight;
    QPushButton *pushTiltNone;
    QPushButton *btnBellyFlop;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btncwNeck;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btncw;
    QSpacerItem *horizontalSpacer_9;
    QSpinBox *spinBoxNecRotate;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnccwNeck;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btnfwd;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxBodyRotate;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnrev;
    QPushButton *btnccw;
    QLabel *label_11;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_14;
    QWidget *tabVision;
    QSpinBox *spinBoxCam;
    QLabel *label_10;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *SldVmin;
    QLabel *label;
    QLabel *label_4;
    QSpinBox *spinBoxHMAX;
    QSpinBox *spinBoxSMAX;
    QSpinBox *spinBoxSMIN;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_2;
    QSpinBox *spinBoxVMIN;
    QSpinBox *spinBoxVMAX;
    QSpinBox *spinBoxHMIN;
    QSlider *sldSmin;
    QSlider *sldHmin;
    QSlider *sldSmax;
    QSlider *sldHmax;
    QSlider *sldvmax;
    QWidget *tabPID;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBoxCP;
    QDoubleSpinBox *doubleSpinBoxCI;
    QDoubleSpinBox *doubleSpinBoxCD;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_13;
    QSpinBox *spinBoxdt;
    QWidget *tabFaceRecognition;
    QWidget *tabConnection;
    QLineEdit *lineEditTermCommand;
    QLabel *label_9;
    QCheckBox *ckbxPrepend;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnConnect;
    QPushButton *btnTrack;
    QPushButton *btnVision;
    QPushButton *btnkillall;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *robotcontrol)
    {
        if (robotcontrol->objectName().isEmpty())
            robotcontrol->setObjectName(QString::fromUtf8("robotcontrol"));
        robotcontrol->resize(660, 435);
        robotcontrol->setWindowOpacity(1);
        action_Save = new QAction(robotcontrol);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        action_Open = new QAction(robotcontrol);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        action_Close = new QAction(robotcontrol);
        action_Close->setObjectName(QString::fromUtf8("action_Close"));
        action_Exit = new QAction(robotcontrol);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        centralWidget = new QWidget(robotcontrol);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 80, 611, 291));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabMotionCntrl = new QWidget();
        tabMotionCntrl->setObjectName(QString::fromUtf8("tabMotionCntrl"));
        scrollArea = new QScrollArea(tabMotionCntrl);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(370, 30, 201, 181));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 199, 179));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnDance = new QPushButton(scrollAreaWidgetContents);
        btnDance->setObjectName(QString::fromUtf8("btnDance"));

        gridLayout_3->addWidget(btnDance, 0, 0, 1, 1);

        btnWave = new QPushButton(scrollAreaWidgetContents);
        btnWave->setObjectName(QString::fromUtf8("btnWave"));

        gridLayout_3->addWidget(btnWave, 0, 1, 1, 1);

        btnTiltLeft = new QPushButton(scrollAreaWidgetContents);
        btnTiltLeft->setObjectName(QString::fromUtf8("btnTiltLeft"));

        gridLayout_3->addWidget(btnTiltLeft, 1, 0, 1, 1);

        btnTiltRight = new QPushButton(scrollAreaWidgetContents);
        btnTiltRight->setObjectName(QString::fromUtf8("btnTiltRight"));

        gridLayout_3->addWidget(btnTiltRight, 2, 0, 1, 1);

        pushTiltNone = new QPushButton(scrollAreaWidgetContents);
        pushTiltNone->setObjectName(QString::fromUtf8("pushTiltNone"));

        gridLayout_3->addWidget(pushTiltNone, 3, 0, 1, 1);

        btnBellyFlop = new QPushButton(scrollAreaWidgetContents);
        btnBellyFlop->setObjectName(QString::fromUtf8("btnBellyFlop"));

        gridLayout_3->addWidget(btnBellyFlop, 1, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(tabMotionCntrl);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 10, 243, 240));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 5, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 5, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 4, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 4, 2, 1, 1);

        btncwNeck = new QPushButton(widget);
        btncwNeck->setObjectName(QString::fromUtf8("btncwNeck"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/rotatecw.png"), QSize(), QIcon::Normal, QIcon::Off);
        btncwNeck->setIcon(icon);
        btncwNeck->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(btncwNeck, 0, 4, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 2, 3, 1, 1);

        btncw = new QPushButton(widget);
        btncw->setObjectName(QString::fromUtf8("btncw"));
        btncw->setIcon(icon);
        btncw->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(btncw, 2, 4, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 4, 4, 1, 1);

        spinBoxNecRotate = new QSpinBox(widget);
        spinBoxNecRotate->setObjectName(QString::fromUtf8("spinBoxNecRotate"));
        spinBoxNecRotate->setValue(20);

        gridLayout_4->addWidget(spinBoxNecRotate, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 5, 4, 1, 1);

        btnccwNeck = new QPushButton(widget);
        btnccwNeck->setObjectName(QString::fromUtf8("btnccwNeck"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/rotateccw.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnccwNeck->setIcon(icon1);
        btnccwNeck->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(btnccwNeck, 0, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 0, 3, 1, 1);

        btnfwd = new QPushButton(widget);
        btnfwd->setObjectName(QString::fromUtf8("btnfwd"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/forwardarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnfwd->setIcon(icon2);
        btnfwd->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(btnfwd, 4, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 2, 1, 1);

        spinBoxBodyRotate = new QSpinBox(widget);
        spinBoxBodyRotate->setObjectName(QString::fromUtf8("spinBoxBodyRotate"));
        spinBoxBodyRotate->setValue(45);

        gridLayout_4->addWidget(spinBoxBodyRotate, 2, 5, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 1, 5, 1, 1);

        btnrev = new QPushButton(widget);
        btnrev->setObjectName(QString::fromUtf8("btnrev"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icons/backwardarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnrev->setIcon(icon3);
        btnrev->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(btnrev, 5, 3, 1, 1);

        btnccw = new QPushButton(widget);
        btnccw->setObjectName(QString::fromUtf8("btnccw"));
        btnccw->setIcon(icon1);
        btnccw->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(btnccw, 2, 2, 1, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_11, 3, 3, 1, 1);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_12, 1, 3, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 3, 2, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_13, 3, 4, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_14, 3, 5, 1, 1);

        tabWidget->addTab(tabMotionCntrl, QString());
        tabVision = new QWidget();
        tabVision->setObjectName(QString::fromUtf8("tabVision"));
        spinBoxCam = new QSpinBox(tabVision);
        spinBoxCam->setObjectName(QString::fromUtf8("spinBoxCam"));
        spinBoxCam->setGeometry(QRect(110, 30, 61, 27));
        label_10 = new QLabel(tabVision);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 30, 67, 17));
        tabWidget->addTab(tabVision, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 571, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        SldVmin = new QSlider(gridLayoutWidget);
        SldVmin->setObjectName(QString::fromUtf8("SldVmin"));
        SldVmin->setMaximum(255);
        SldVmin->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SldVmin, 3, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        spinBoxHMAX = new QSpinBox(gridLayoutWidget);
        spinBoxHMAX->setObjectName(QString::fromUtf8("spinBoxHMAX"));
        spinBoxHMAX->setMaximum(255);
        spinBoxHMAX->setSingleStep(5);
        spinBoxHMAX->setValue(255);

        gridLayout->addWidget(spinBoxHMAX, 1, 4, 1, 1);

        spinBoxSMAX = new QSpinBox(gridLayoutWidget);
        spinBoxSMAX->setObjectName(QString::fromUtf8("spinBoxSMAX"));
        spinBoxSMAX->setMaximum(255);
        spinBoxSMAX->setSingleStep(5);
        spinBoxSMAX->setValue(255);

        gridLayout->addWidget(spinBoxSMAX, 2, 4, 1, 1);

        spinBoxSMIN = new QSpinBox(gridLayoutWidget);
        spinBoxSMIN->setObjectName(QString::fromUtf8("spinBoxSMIN"));
        spinBoxSMIN->setMaximum(255);
        spinBoxSMIN->setSingleStep(5);

        gridLayout->addWidget(spinBoxSMIN, 2, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        spinBoxVMIN = new QSpinBox(gridLayoutWidget);
        spinBoxVMIN->setObjectName(QString::fromUtf8("spinBoxVMIN"));
        spinBoxVMIN->setMaximum(255);

        gridLayout->addWidget(spinBoxVMIN, 3, 2, 1, 1);

        spinBoxVMAX = new QSpinBox(gridLayoutWidget);
        spinBoxVMAX->setObjectName(QString::fromUtf8("spinBoxVMAX"));
        spinBoxVMAX->setMinimum(0);
        spinBoxVMAX->setMaximum(255);
        spinBoxVMAX->setSingleStep(5);
        spinBoxVMAX->setValue(255);

        gridLayout->addWidget(spinBoxVMAX, 3, 4, 1, 1);

        spinBoxHMIN = new QSpinBox(gridLayoutWidget);
        spinBoxHMIN->setObjectName(QString::fromUtf8("spinBoxHMIN"));
        spinBoxHMIN->setMaximum(255);
        spinBoxHMIN->setSingleStep(5);

        gridLayout->addWidget(spinBoxHMIN, 1, 2, 1, 1);

        sldSmin = new QSlider(gridLayoutWidget);
        sldSmin->setObjectName(QString::fromUtf8("sldSmin"));
        sldSmin->setMaximum(255);
        sldSmin->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sldSmin, 2, 1, 1, 1);

        sldHmin = new QSlider(gridLayoutWidget);
        sldHmin->setObjectName(QString::fromUtf8("sldHmin"));
        sldHmin->setMaximum(255);
        sldHmin->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sldHmin, 1, 1, 1, 1);

        sldSmax = new QSlider(gridLayoutWidget);
        sldSmax->setObjectName(QString::fromUtf8("sldSmax"));
        sldSmax->setMaximum(255);
        sldSmax->setSliderPosition(255);
        sldSmax->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sldSmax, 2, 3, 1, 1);

        sldHmax = new QSlider(gridLayoutWidget);
        sldHmax->setObjectName(QString::fromUtf8("sldHmax"));
        sldHmax->setMaximum(255);
        sldHmax->setSliderPosition(255);
        sldHmax->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sldHmax, 1, 3, 1, 1);

        sldvmax = new QSlider(gridLayoutWidget);
        sldvmax->setObjectName(QString::fromUtf8("sldvmax"));
        sldvmax->setMaximum(255);
        sldvmax->setSliderPosition(255);
        sldvmax->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sldvmax, 3, 3, 1, 1);

        tabWidget->addTab(tab, QString());
        tabPID = new QWidget();
        tabPID->setObjectName(QString::fromUtf8("tabPID"));
        layoutWidget = new QWidget(tabPID);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 251, 141));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        doubleSpinBoxCP = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoxCP->setObjectName(QString::fromUtf8("doubleSpinBoxCP"));
        doubleSpinBoxCP->setDecimals(4);
        doubleSpinBoxCP->setMinimum(-10);
        doubleSpinBoxCP->setSingleStep(0.05);
        doubleSpinBoxCP->setValue(0.05);

        gridLayout_2->addWidget(doubleSpinBoxCP, 0, 1, 1, 1);

        doubleSpinBoxCI = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoxCI->setObjectName(QString::fromUtf8("doubleSpinBoxCI"));
        doubleSpinBoxCI->setDecimals(4);
        doubleSpinBoxCI->setMinimum(-10);

        gridLayout_2->addWidget(doubleSpinBoxCI, 1, 1, 1, 1);

        doubleSpinBoxCD = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoxCD->setObjectName(QString::fromUtf8("doubleSpinBoxCD"));
        doubleSpinBoxCD->setDecimals(4);
        doubleSpinBoxCD->setMinimum(-10);

        gridLayout_2->addWidget(doubleSpinBoxCD, 2, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 3, 0, 1, 1);

        spinBoxdt = new QSpinBox(layoutWidget);
        spinBoxdt->setObjectName(QString::fromUtf8("spinBoxdt"));
        spinBoxdt->setMaximum(3000);
        spinBoxdt->setValue(1000);

        gridLayout_2->addWidget(spinBoxdt, 3, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 2);

        horizontalLayout->addLayout(gridLayout_2);

        tabWidget->addTab(tabPID, QString());
        tabFaceRecognition = new QWidget();
        tabFaceRecognition->setObjectName(QString::fromUtf8("tabFaceRecognition"));
        tabWidget->addTab(tabFaceRecognition, QString());
        tabConnection = new QWidget();
        tabConnection->setObjectName(QString::fromUtf8("tabConnection"));
        lineEditTermCommand = new QLineEdit(tabConnection);
        lineEditTermCommand->setObjectName(QString::fromUtf8("lineEditTermCommand"));
        lineEditTermCommand->setGeometry(QRect(60, 30, 281, 21));
        label_9 = new QLabel(tabConnection);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(60, 10, 281, 17));
        ckbxPrepend = new QCheckBox(tabConnection);
        ckbxPrepend->setObjectName(QString::fromUtf8("ckbxPrepend"));
        ckbxPrepend->setGeometry(QRect(60, 60, 181, 51));
        tabWidget->addTab(tabConnection, QString());
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 0, 269, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnConnect = new QPushButton(layoutWidget1);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(170, 255, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(127, 255, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 127, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(56, 170, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnConnect->setPalette(palette);

        horizontalLayout_2->addWidget(btnConnect);

        btnTrack = new QPushButton(layoutWidget1);
        btnTrack->setObjectName(QString::fromUtf8("btnTrack"));

        horizontalLayout_2->addWidget(btnTrack);

        btnVision = new QPushButton(layoutWidget1);
        btnVision->setObjectName(QString::fromUtf8("btnVision"));

        horizontalLayout_2->addWidget(btnVision);

        btnkillall = new QPushButton(centralWidget);
        btnkillall->setObjectName(QString::fromUtf8("btnkillall"));
        btnkillall->setGeometry(QRect(450, 0, 161, 71));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icons/off.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnkillall->setIcon(icon4);
        btnkillall->setIconSize(QSize(64, 64));
        robotcontrol->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(robotcontrol);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 660, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        robotcontrol->setMenuBar(menuBar);
        mainToolBar = new QToolBar(robotcontrol);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        robotcontrol->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(robotcontrol);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        robotcontrol->setStatusBar(statusBar);
        toolBar = new QToolBar(robotcontrol);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        robotcontrol->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Save);
        menu_File->addAction(action_Open);
        menu_File->addSeparator();
        menu_File->addAction(action_Close);
        menu_File->addAction(action_Exit);

        retranslateUi(robotcontrol);
        QObject::connect(sldHmin, SIGNAL(valueChanged(int)), spinBoxHMIN, SLOT(setValue(int)));
        QObject::connect(spinBoxHMIN, SIGNAL(valueChanged(int)), sldHmin, SLOT(setValue(int)));
        QObject::connect(sldSmin, SIGNAL(valueChanged(int)), spinBoxSMIN, SLOT(setValue(int)));
        QObject::connect(spinBoxSMIN, SIGNAL(valueChanged(int)), sldSmin, SLOT(setValue(int)));
        QObject::connect(spinBoxVMIN, SIGNAL(valueChanged(int)), SldVmin, SLOT(setValue(int)));
        QObject::connect(spinBoxVMAX, SIGNAL(valueChanged(int)), sldvmax, SLOT(setValue(int)));
        QObject::connect(sldvmax, SIGNAL(valueChanged(int)), spinBoxVMAX, SLOT(setValue(int)));
        QObject::connect(SldVmin, SIGNAL(valueChanged(int)), spinBoxVMIN, SLOT(setValue(int)));
        QObject::connect(sldHmax, SIGNAL(valueChanged(int)), spinBoxHMAX, SLOT(setValue(int)));
        QObject::connect(spinBoxSMAX, SIGNAL(valueChanged(int)), spinBoxSMAX, SLOT(setValue(int)));
        QObject::connect(spinBoxHMAX, SIGNAL(valueChanged(int)), sldHmax, SLOT(setValue(int)));
        QObject::connect(sldSmax, SIGNAL(valueChanged(int)), spinBoxSMAX, SLOT(setValue(int)));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(robotcontrol);
    } // setupUi

    void retranslateUi(QMainWindow *robotcontrol)
    {
        robotcontrol->setWindowTitle(QApplication::translate("robotcontrol", "QT Robot Control", 0, QApplication::UnicodeUTF8));
        action_Save->setText(QApplication::translate("robotcontrol", "&Save", 0, QApplication::UnicodeUTF8));
        action_Open->setText(QApplication::translate("robotcontrol", "&Open", 0, QApplication::UnicodeUTF8));
        action_Close->setText(QApplication::translate("robotcontrol", "&Close", 0, QApplication::UnicodeUTF8));
        action_Exit->setText(QApplication::translate("robotcontrol", "&Exit", 0, QApplication::UnicodeUTF8));
        btnDance->setText(QApplication::translate("robotcontrol", "Dance", 0, QApplication::UnicodeUTF8));
        btnWave->setText(QApplication::translate("robotcontrol", "Wave", 0, QApplication::UnicodeUTF8));
        btnTiltLeft->setText(QApplication::translate("robotcontrol", "Tilt Left", 0, QApplication::UnicodeUTF8));
        btnTiltRight->setText(QApplication::translate("robotcontrol", "Tilt Right", 0, QApplication::UnicodeUTF8));
        pushTiltNone->setText(QApplication::translate("robotcontrol", "Tilt None", 0, QApplication::UnicodeUTF8));
        btnBellyFlop->setText(QApplication::translate("robotcontrol", "Belly Flop", 0, QApplication::UnicodeUTF8));
        btncwNeck->setText(QString());
        btncw->setText(QString());
        btnccwNeck->setText(QString());
        btnfwd->setText(QString());
        btnrev->setText(QString());
        btnccw->setText(QString());
        label_11->setText(QApplication::translate("robotcontrol", "Body", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("robotcontrol", "Neck", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabMotionCntrl), QApplication::translate("robotcontrol", "Motion Control", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("robotcontrol", "Camera", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabVision), QApplication::translate("robotcontrol", "Vision", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("robotcontrol", "H ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("robotcontrol", "S ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("robotcontrol", "V", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("robotcontrol", "Max", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("robotcontrol", "Min", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("robotcontrol", "Threashold", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("robotcontrol", "CI", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("robotcontrol", "CP", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("robotcontrol", "CD", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("robotcontrol", "dt (ms)", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabPID), QApplication::translate("robotcontrol", "PID", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabFaceRecognition), QApplication::translate("robotcontrol", "Face Recognition", 0, QApplication::UnicodeUTF8));
        lineEditTermCommand->setText(QApplication::translate("robotcontrol", "gnome-terminal -x", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("robotcontrol", "Terminal Command", 0, QApplication::UnicodeUTF8));
        ckbxPrepend->setText(QApplication::translate("robotcontrol", "Prepend Terminal \n"
"Command To Python \n"
"Connection", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabConnection), QApplication::translate("robotcontrol", "Connection", 0, QApplication::UnicodeUTF8));
        btnConnect->setText(QApplication::translate("robotcontrol", "Connect", 0, QApplication::UnicodeUTF8));
        btnTrack->setText(QApplication::translate("robotcontrol", "Track", 0, QApplication::UnicodeUTF8));
        btnVision->setText(QApplication::translate("robotcontrol", "Vision", 0, QApplication::UnicodeUTF8));
        btnkillall->setText(QApplication::translate("robotcontrol", "E-BRAKE", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("robotcontrol", "&File", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("robotcontrol", "QT Robot Control", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("robotcontrol", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class robotcontrol: public Ui_robotcontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTCONTROL_H
