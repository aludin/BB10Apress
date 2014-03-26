/****************************************************************************
** Meta object code from reading C++ file 'Option.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Option.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Option.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Option[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       6,   44, // properties
       1,   68, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      22,    7,    7,    7, 0x05,
      36,    7,    7,    7, 0x05,
      56,    7,    7,    7, 0x05,
      72,    7,    7,    7, 0x05,
      94,    7,    7,    7, 0x05,

 // properties: name, type, flags
     123,  112, 0x0049500b,
     135,  128, 0x06495103,
     148,  128, 0x06495103,
     153,  128, 0x06495103,
     160,  128, 0x06495003,
     169,  128, 0x06495103,

 // properties: notify_signal_id
       0,
       4,
       1,
       3,
       5,
       2,

 // enums: name, flags, count, data
     112, 0x0,    2,   72,

 // enum data: key, value
     180, uint(Option::CALL),
     185, uint(Option::PUT),

       0        // eod
};

static const char qt_meta_stringdata_Option[] = {
    "Option\0\0typeChanged()\0spotChanged()\0"
    "volatilityChanged()\0strikeChanged()\0"
    "riskfreeRateChanged()\0maturityChanged()\0"
    "OptionType\0type\0double\0riskfreeRate\0"
    "spot\0strike\0maturity\0volatility\0CALL\0"
    "PUT\0"
};

void Option::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Option *_t = static_cast<Option *>(_o);
        switch (_id) {
        case 0: _t->typeChanged(); break;
        case 1: _t->spotChanged(); break;
        case 2: _t->volatilityChanged(); break;
        case 3: _t->strikeChanged(); break;
        case 4: _t->riskfreeRateChanged(); break;
        case 5: _t->maturityChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Option::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Option::staticMetaObject = {
    { &Instrument::staticMetaObject, qt_meta_stringdata_Option,
      qt_meta_data_Option, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Option::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Option::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Option::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Option))
        return static_cast<void*>(const_cast< Option*>(this));
    return Instrument::qt_metacast(_clname);
}

int Option::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Instrument::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< OptionType*>(_v) = optionType(); break;
        case 1: *reinterpret_cast< double*>(_v) = riskfreeRate(); break;
        case 2: *reinterpret_cast< double*>(_v) = spot(); break;
        case 3: *reinterpret_cast< double*>(_v) = strike(); break;
        case 4: *reinterpret_cast< double*>(_v) = timeToMaturity(); break;
        case 5: *reinterpret_cast< double*>(_v) = volatility(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setOptionType(*reinterpret_cast< OptionType*>(_v)); break;
        case 1: setRiskfreeRate(*reinterpret_cast< double*>(_v)); break;
        case 2: setSpot(*reinterpret_cast< double*>(_v)); break;
        case 3: setStrike(*reinterpret_cast< double*>(_v)); break;
        case 4: setTimeToMaturity(*reinterpret_cast< double*>(_v)); break;
        case 5: setVolatility(*reinterpret_cast< double*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Option::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Option::spotChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Option::volatilityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Option::strikeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Option::riskfreeRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Option::maturityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
