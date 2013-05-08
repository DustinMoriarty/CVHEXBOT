/****************************************************************************
** Meta object code from reading C++ file 'robotcontrol.h'
**
** Created: Wed May 8 02:46:07 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/robotcontrol.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_robotcontrol[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      38,   13,   13,   13, 0x08,
      60,   13,   13,   13, 0x08,
      83,   13,   13,   13, 0x08,
     120,   13,   13,   13, 0x08,
     157,   13,   13,   13, 0x08,
     194,   13,   13,   13, 0x08,
     227,   13,   13,   13, 0x08,
     260,   13,   13,   13, 0x08,
     293,   13,   13,   13, 0x08,
     326,   13,   13,   13, 0x08,
     359,   13,   13,   13, 0x08,
     392,   13,   13,   13, 0x08,
     404,   13,   13,   13, 0x08,
     419,   13,   13,   13, 0x08,
     446,   13,   13,   13, 0x08,
     473,   13,   13,   13, 0x08,
     501,   13,   13,   13, 0x08,
     521,   13,   13,   13, 0x08,
     540,   13,   13,   13, 0x08,
     560,   13,   13,   13, 0x08,
     580,   13,   13,   13, 0x08,
     604,   13,   13,   13, 0x08,
     636,   13,   13,   13, 0x08,
     658,   13,   13,   13, 0x08,
     683,   13,   13,   13, 0x08,
     709,   13,   13,   13, 0x08,
     735,   13,   13,   13, 0x08,
     756,   13,   13,   13, 0x08,
     782,   13,   13,   13, 0x08,
     805,   13,   13,   13, 0x08,
     829,   13,   13,   13, 0x08,
     859,  854,   13,   13, 0x08,
     892,  854,   13,   13, 0x08,
     925,  854,   13,   13, 0x08,
     958,  854,   13,   13, 0x08,
     991,  854,   13,   13, 0x08,
    1024,  854,   13,   13, 0x08,
    1057,  854,   13,   13, 0x08,
    1093,   13,   13,   13, 0x08,
    1105,   13,   13,   13, 0x08,
    1116,   13,   13,   13, 0x08,
    1129,   13,   13,   13, 0x08,
    1145,   13,   13,   13, 0x08,
    1155,   13,   13,   13, 0x08,
    1166,  854,   13,   13, 0x08,
    1204,   13,   13,   13, 0x08,
    1233,   13,   13,   13, 0x08,
    1281, 1274,   13,   13, 0x08,
    1313,  854,   13,   13, 0x08,
    1345,  854,   13,   13, 0x08,
    1394, 1388,   13,   13, 0x08,
    1440, 1388,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_robotcontrol[] = {
    "robotcontrol\0\0on_btnConnect_clicked()\0"
    "on_btnTrack_clicked()\0on_btnVision_clicked()\0"
    "on_doubleSpinBoxCP_editingFinished()\0"
    "on_doubleSpinBoxCI_editingFinished()\0"
    "on_doubleSpinBoxCD_editingFinished()\0"
    "on_spinBoxHMIN_editingFinished()\0"
    "on_spinBoxSMIN_editingFinished()\0"
    "on_spinBoxVMIN_editingFinished()\0"
    "on_spinBoxHMAX_editingFinished()\0"
    "on_spinBoxSMAX_editingFinished()\0"
    "on_spinBoxVMAX_editingFinished()\0"
    "UpdatePID()\0UpdateThresh()\0"
    "on_action_Save_triggered()\0"
    "on_action_Open_triggered()\0"
    "on_action_Close_triggered()\0"
    "on_btnccw_clicked()\0on_btncw_clicked()\0"
    "on_btnfwd_clicked()\0on_btnrev_clicked()\0"
    "on_btnkillall_clicked()\0"
    "on_spinBoxCam_editingFinished()\0"
    "on_btnDance_clicked()\0on_btnTiltLeft_clicked()\0"
    "on_btnTiltRight_clicked()\0"
    "on_pushTiltNone_clicked()\0"
    "on_btnWave_clicked()\0on_btnBellyFlop_clicked()\0"
    "on_btncwNeck_clicked()\0on_btnccwNeck_clicked()\0"
    "on_ckbxPrepend_clicked()\0arg1\0"
    "on_spinBoxHMIN_valueChanged(int)\0"
    "on_spinBoxSMIN_valueChanged(int)\0"
    "on_spinBoxVMIN_valueChanged(int)\0"
    "on_spinBoxHMAX_valueChanged(int)\0"
    "on_spinBoxSMAX_valueChanged(int)\0"
    "on_spinBoxVMAX_valueChanged(int)\0"
    "on_spinBoxCam_valueChanged(QString)\0"
    "visionoff()\0visionon()\0connectbot()\0"
    "disconnectbot()\0trackon()\0trackoff()\0"
    "on_spinBoxNecRotate_valueChanged(int)\0"
    "on_centralWidget_destroyed()\0"
    "on_lineEditTermCommand_editingFinished()\0"
    "action\0on_sldHmin_actionTriggered(int)\0"
    "on_spinBoxCam_valueChanged(int)\0"
    "on_doubleSpinBoxNoise_valueChanged(double)\0"
    "index\0on_comboBoxTrackType_currentIndexChanged(int)\0"
    "on_comboBoxTrackType_activated(int)\0"
};

void robotcontrol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        robotcontrol *_t = static_cast<robotcontrol *>(_o);
        switch (_id) {
        case 0: _t->on_btnConnect_clicked(); break;
        case 1: _t->on_btnTrack_clicked(); break;
        case 2: _t->on_btnVision_clicked(); break;
        case 3: _t->on_doubleSpinBoxCP_editingFinished(); break;
        case 4: _t->on_doubleSpinBoxCI_editingFinished(); break;
        case 5: _t->on_doubleSpinBoxCD_editingFinished(); break;
        case 6: _t->on_spinBoxHMIN_editingFinished(); break;
        case 7: _t->on_spinBoxSMIN_editingFinished(); break;
        case 8: _t->on_spinBoxVMIN_editingFinished(); break;
        case 9: _t->on_spinBoxHMAX_editingFinished(); break;
        case 10: _t->on_spinBoxSMAX_editingFinished(); break;
        case 11: _t->on_spinBoxVMAX_editingFinished(); break;
        case 12: _t->UpdatePID(); break;
        case 13: _t->UpdateThresh(); break;
        case 14: _t->on_action_Save_triggered(); break;
        case 15: _t->on_action_Open_triggered(); break;
        case 16: _t->on_action_Close_triggered(); break;
        case 17: _t->on_btnccw_clicked(); break;
        case 18: _t->on_btncw_clicked(); break;
        case 19: _t->on_btnfwd_clicked(); break;
        case 20: _t->on_btnrev_clicked(); break;
        case 21: _t->on_btnkillall_clicked(); break;
        case 22: _t->on_spinBoxCam_editingFinished(); break;
        case 23: _t->on_btnDance_clicked(); break;
        case 24: _t->on_btnTiltLeft_clicked(); break;
        case 25: _t->on_btnTiltRight_clicked(); break;
        case 26: _t->on_pushTiltNone_clicked(); break;
        case 27: _t->on_btnWave_clicked(); break;
        case 28: _t->on_btnBellyFlop_clicked(); break;
        case 29: _t->on_btncwNeck_clicked(); break;
        case 30: _t->on_btnccwNeck_clicked(); break;
        case 31: _t->on_ckbxPrepend_clicked(); break;
        case 32: _t->on_spinBoxHMIN_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_spinBoxSMIN_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_spinBoxVMIN_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_spinBoxHMAX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_spinBoxSMAX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_spinBoxVMAX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->on_spinBoxCam_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: _t->visionoff(); break;
        case 40: _t->visionon(); break;
        case 41: _t->connectbot(); break;
        case 42: _t->disconnectbot(); break;
        case 43: _t->trackon(); break;
        case 44: _t->trackoff(); break;
        case 45: _t->on_spinBoxNecRotate_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->on_centralWidget_destroyed(); break;
        case 47: _t->on_lineEditTermCommand_editingFinished(); break;
        case 48: _t->on_sldHmin_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->on_spinBoxCam_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->on_doubleSpinBoxNoise_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 51: _t->on_comboBoxTrackType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->on_comboBoxTrackType_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData robotcontrol::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject robotcontrol::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_robotcontrol,
      qt_meta_data_robotcontrol, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &robotcontrol::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *robotcontrol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *robotcontrol::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_robotcontrol))
        return static_cast<void*>(const_cast< robotcontrol*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int robotcontrol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
