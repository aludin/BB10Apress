/****************************************************************************
** Meta object code from reading C++ file 'CityInfo.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/CityInfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CityInfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CityInfo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       8,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      24,    9,    9,    9, 0x05,
      39,    9,    9,    9, 0x05,
      57,    9,    9,    9, 0x05,
     105,   76,    9,    9, 0x05,
     149,    9,    9,    9, 0x05,
     166,    9,    9,    9, 0x05,
     187,    9,    9,    9, 0x05,
     208,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     233,    9,    9,    9, 0x08,

 // properties: name, type, flags
     272,  264, 0x0a495001,
     277,  264, 0x0a495001,
     283,  264, 0x0a495001,
     292,  264, 0x0a495001,
     302,  264, 0x0a495001,
     319,  310, 0xff495001,
     331,  264, 0x0a495001,
     343,  264, 0x0a495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       5,
       6,
       7,
       8,

       0        // eod
};

static const char qt_meta_stringdata_CityInfo[] = {
    "CityInfo\0\0cityChanged()\0stateChanged()\0"
    "latitudeChanged()\0longitudeChanged()\0"
    "latitude,longitude,markerUrl\0"
    "coordinatesChanged(QString,QString,QString)\0"
    "weatherChanged()\0weatherIconChanged()\0"
    "temperatureChanged()\0lastObservationChanged()\0"
    "onWeatherIconRequestFinished()\0QString\0"
    "city\0state\0latitude\0longitude\0weather\0"
    "QVariant\0weatherIcon\0temperature\0"
    "lastObservation\0"
};

void CityInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CityInfo *_t = static_cast<CityInfo *>(_o);
        switch (_id) {
        case 0: _t->cityChanged(); break;
        case 1: _t->stateChanged(); break;
        case 2: _t->latitudeChanged(); break;
        case 3: _t->longitudeChanged(); break;
        case 4: _t->coordinatesChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->weatherChanged(); break;
        case 6: _t->weatherIconChanged(); break;
        case 7: _t->temperatureChanged(); break;
        case 8: _t->lastObservationChanged(); break;
        case 9: _t->onWeatherIconRequestFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CityInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CityInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CityInfo,
      qt_meta_data_CityInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CityInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CityInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CityInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CityInfo))
        return static_cast<void*>(const_cast< CityInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int CityInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = city(); break;
        case 1: *reinterpret_cast< QString*>(_v) = state(); break;
        case 2: *reinterpret_cast< QString*>(_v) = latitude(); break;
        case 3: *reinterpret_cast< QString*>(_v) = longitude(); break;
        case 4: *reinterpret_cast< QString*>(_v) = weather(); break;
        case 5: *reinterpret_cast< QVariant*>(_v) = weatherIcon(); break;
        case 6: *reinterpret_cast< QString*>(_v) = temperature(); break;
        case 7: *reinterpret_cast< QString*>(_v) = lastObservation(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CityInfo::cityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CityInfo::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CityInfo::latitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CityInfo::longitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void CityInfo::coordinatesChanged(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CityInfo::weatherChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void CityInfo::weatherIconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void CityInfo::temperatureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void CityInfo::lastObservationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
