/****************************************************************************
** Meta object code from reading C++ file 'machine.h'
**
** Created: Fri May 31 21:55:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/machine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'machine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_machine[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      20,    8,    8,    8, 0x0a,
      37,   33,    8,    8, 0x0a,
      57,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_machine[] = {
    "machine\0\0newframe()\0ConnectBot()\0cmd\0"
    "ConnectBot(QString)\0settrackon(bool)\0"
};

void machine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        machine *_t = static_cast<machine *>(_o);
        switch (_id) {
        case 0: _t->newframe(); break;
        case 1: _t->ConnectBot(); break;
        case 2: _t->ConnectBot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->settrackon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData machine::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject machine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_machine,
      qt_meta_data_machine, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &machine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *machine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *machine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_machine))
        return static_cast<void*>(const_cast< machine*>(this));
    return QObject::qt_metacast(_clname);
}

int machine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void machine::newframe()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
