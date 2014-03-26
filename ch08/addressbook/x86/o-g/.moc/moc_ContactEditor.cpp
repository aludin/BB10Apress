/****************************************************************************
** Meta object code from reading C++ file 'ContactEditor.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ContactEditor.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ContactEditor.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ContactEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       5,   54, // properties
       1,   74, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      34,   14,   14,   14, 0x05,
      52,   14,   14,   14, 0x05,
      70,   14,   14,   14, 0x05,
      85,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     109,   99,   14,   14, 0x0a,
     151,   14,   14,   14, 0x0a,
     165,   14,   14,   14, 0x0a,

 // properties: name, type, flags
     181,  173, 0x0a495103,
     191,  173, 0x0a495103,
     210,  200, 0x10495103,
     219,  173, 0x0a495103,
     230,  225, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

 // enums: name, flags, count, data
     225, 0x0,    2,   78,

 // enum data: key, value
     235, uint(ContactEditor::CreateMode),
     246, uint(ContactEditor::EditMode),

       0        // eod
};

static const char qt_meta_stringdata_ContactEditor[] = {
    "ContactEditor\0\0firstNameChanged()\0"
    "lastNameChanged()\0birthdayChanged()\0"
    "emailChanged()\0modeChanged()\0contactId\0"
    "loadContact(bb::pim::contacts::ContactId)\0"
    "saveContact()\0reset()\0QString\0firstName\0"
    "lastName\0QDateTime\0birthday\0email\0"
    "Mode\0mode\0CreateMode\0EditMode\0"
};

void ContactEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ContactEditor *_t = static_cast<ContactEditor *>(_o);
        switch (_id) {
        case 0: _t->firstNameChanged(); break;
        case 1: _t->lastNameChanged(); break;
        case 2: _t->birthdayChanged(); break;
        case 3: _t->emailChanged(); break;
        case 4: _t->modeChanged(); break;
        case 5: _t->loadContact((*reinterpret_cast< bb::pim::contacts::ContactId(*)>(_a[1]))); break;
        case 6: _t->saveContact(); break;
        case 7: _t->reset(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ContactEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ContactEditor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ContactEditor,
      qt_meta_data_ContactEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContactEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContactEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContactEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContactEditor))
        return static_cast<void*>(const_cast< ContactEditor*>(this));
    return QObject::qt_metacast(_clname);
}

int ContactEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< QString*>(_v) = firstName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = lastName(); break;
        case 2: *reinterpret_cast< QDateTime*>(_v) = birthday(); break;
        case 3: *reinterpret_cast< QString*>(_v) = email(); break;
        case 4: *reinterpret_cast< Mode*>(_v) = mode(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFirstName(*reinterpret_cast< QString*>(_v)); break;
        case 1: setLastName(*reinterpret_cast< QString*>(_v)); break;
        case 2: setBirthday(*reinterpret_cast< QDateTime*>(_v)); break;
        case 3: setEmail(*reinterpret_cast< QString*>(_v)); break;
        case 4: setMode(*reinterpret_cast< Mode*>(_v)); break;
        }
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
void ContactEditor::firstNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ContactEditor::lastNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ContactEditor::birthdayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ContactEditor::emailChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ContactEditor::modeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
