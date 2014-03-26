/****************************************************************************
** Meta object code from reading C++ file 'ContactViewer.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ContactViewer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ContactViewer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ContactViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       5,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      34,   14,   14,   14, 0x05,
      52,   14,   14,   14, 0x05,
      70,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   85,   14,   14, 0x08,

 // properties: name, type, flags
     125,  117, 0x0a495001,
     135,  117, 0x0a495001,
     154,  144, 0x10495001,
     163,  117, 0x0a495001,
     181,  117, 0x0a495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       2,
       3,

       0        // eod
};

static const char qt_meta_stringdata_ContactViewer[] = {
    "ContactViewer\0\0firstNameChanged()\0"
    "lastNameChanged()\0birthdayChanged()\0"
    "emailChanged()\0ids\0contactsChanged(QList<int>)\0"
    "QString\0firstName\0lastName\0QDateTime\0"
    "birthday\0formattedBirthday\0email\0"
};

void ContactViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ContactViewer *_t = static_cast<ContactViewer *>(_o);
        switch (_id) {
        case 0: _t->firstNameChanged(); break;
        case 1: _t->lastNameChanged(); break;
        case 2: _t->birthdayChanged(); break;
        case 3: _t->emailChanged(); break;
        case 4: _t->contactsChanged((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ContactViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ContactViewer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ContactViewer,
      qt_meta_data_ContactViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContactViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContactViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContactViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContactViewer))
        return static_cast<void*>(const_cast< ContactViewer*>(this));
    return QObject::qt_metacast(_clname);
}

int ContactViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = firstName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = lastName(); break;
        case 2: *reinterpret_cast< QDateTime*>(_v) = birthday(); break;
        case 3: *reinterpret_cast< QString*>(_v) = formattedBirthday(); break;
        case 4: *reinterpret_cast< QString*>(_v) = email(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ContactViewer::firstNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ContactViewer::lastNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ContactViewer::birthdayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ContactViewer::emailChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
