/****************************************************************************
** Meta object code from reading C++ file 'HybridSensor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/HybridSensor.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HybridSensor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HybridSensor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      29,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   13,   13,   13, 0x0a,
      50,   13,   13,   13, 0x0a,
      57,   13,   13,   13, 0x0a,
      82,   13,   13,   13, 0x0a,

 // properties: name, type, flags
     105,   99, ((uint)QMetaType::QReal << 24) | 0x00495001,
     112,   99, ((uint)QMetaType::QReal << 24) | 0x00495001,
     119,   99, ((uint)QMetaType::QReal << 24) | 0x00495001,
     126,   99, ((uint)QMetaType::QReal << 24) | 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_HybridSensor[] = {
    "HybridSensor\0\0accelChanged()\0luxChanged()\0"
    "start()\0stop()\0onAccellerationChanged()\0"
    "onLightChanged()\0qreal\0accelX\0accelY\0"
    "accelZ\0lux\0"
};

void HybridSensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HybridSensor *_t = static_cast<HybridSensor *>(_o);
        switch (_id) {
        case 0: _t->accelChanged(); break;
        case 1: _t->luxChanged(); break;
        case 2: _t->start(); break;
        case 3: _t->stop(); break;
        case 4: _t->onAccellerationChanged(); break;
        case 5: _t->onLightChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData HybridSensor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HybridSensor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HybridSensor,
      qt_meta_data_HybridSensor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HybridSensor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HybridSensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HybridSensor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HybridSensor))
        return static_cast<void*>(const_cast< HybridSensor*>(this));
    return QObject::qt_metacast(_clname);
}

int HybridSensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = accelX(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = accelY(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = accelZ(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = lux(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void HybridSensor::accelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void HybridSensor::luxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
