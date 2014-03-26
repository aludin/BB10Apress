/****************************************************************************
** Meta object code from reading C++ file 'CompositeInstrument.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/CompositeInstrument.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CompositeInstrument.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CompositeInstrument[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      39,   20,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CompositeInstrument[] = {
    "CompositeInstrument\0\0instrumentAdded()\0"
    "instrumentRemoved()\0"
};

void CompositeInstrument::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CompositeInstrument *_t = static_cast<CompositeInstrument *>(_o);
        switch (_id) {
        case 0: _t->instrumentAdded(); break;
        case 1: _t->instrumentRemoved(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CompositeInstrument::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CompositeInstrument::staticMetaObject = {
    { &Instrument::staticMetaObject, qt_meta_stringdata_CompositeInstrument,
      qt_meta_data_CompositeInstrument, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CompositeInstrument::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CompositeInstrument::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CompositeInstrument::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CompositeInstrument))
        return static_cast<void*>(const_cast< CompositeInstrument*>(this));
    return Instrument::qt_metacast(_clname);
}

int CompositeInstrument::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Instrument::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CompositeInstrument::instrumentAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CompositeInstrument::instrumentRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
