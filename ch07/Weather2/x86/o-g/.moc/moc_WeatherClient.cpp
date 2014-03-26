/****************************************************************************
** Meta object code from reading C++ file 'WeatherClient.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/WeatherClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WeatherClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WeatherClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x05,
      63,   55,   14,   14, 0x05,
      81,   55,   14,   14, 0x05,
      96,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     112,  107,   14,   14, 0x0a,
     147,  133,   14,   14, 0x0a,
     164,   14,   14,   14, 0x0a,
     173,   14,   14,   14, 0x08,

 // properties: name, type, flags
     207,  197, 0x00095409,

       0        // eod
};

static const char qt_meta_stringdata_WeatherClient[] = {
    "WeatherClient\0\0cities\0"
    "multipleCitiesFound(QStringList)\0"
    "message\0keyError(QString)\0error(QString)\0"
    "finished()\0city\0cityWeather(QString)\0"
    "selectedIndex\0cityWeather(int)\0cancel()\0"
    "onCityRequestFinished()\0CityInfo*\0"
    "cityinfo\0"
};

void WeatherClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WeatherClient *_t = static_cast<WeatherClient *>(_o);
        switch (_id) {
        case 0: _t->multipleCitiesFound((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->keyError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->finished(); break;
        case 4: _t->cityWeather((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->cityWeather((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->cancel(); break;
        case 7: _t->onCityRequestFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WeatherClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WeatherClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WeatherClient,
      qt_meta_data_WeatherClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WeatherClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WeatherClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WeatherClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherClient))
        return static_cast<void*>(const_cast< WeatherClient*>(this));
    return QObject::qt_metacast(_clname);
}

int WeatherClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< CityInfo**>(_v) = city(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WeatherClient::multipleCitiesFound(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WeatherClient::keyError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WeatherClient::error(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WeatherClient::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
