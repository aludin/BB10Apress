/****************************************************************************
** Meta object code from reading C++ file 'AddressBook.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/AddressBook.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddressBook.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddressBook[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   29,   12,   12, 0x0a,
      71,   12,   12,   12, 0x0a,
      87,   12,   12,   12, 0x0a,
     101,   12,   12,   12, 0x0a,
     115,   12,   12,   12, 0x0a,
     131,   12,   12,   12, 0x08,
     157,  148,   12,   12, 0x08,

 // properties: name, type, flags
     220,  190, 0x00095409,
     234,  226, 0x0a495103,
     256,  241, 0x00095409,
     285,  270, 0x00095409,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_AddressBook[] = {
    "AddressBook\0\0filterChanged()\0indexPath\0"
    "setCurrentContact(QVariantList)\0"
    "createContact()\0editContact()\0"
    "viewContact()\0deleteContact()\0"
    "filterContacts()\0contacts\0"
    "onSearchFinished(QList<Contact>)\0"
    "bb::cascades::GroupDataModel*\0model\0"
    "QString\0filter\0ContactViewer*\0"
    "contactViewer\0ContactEditor*\0contactEditor\0"
};

void AddressBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddressBook *_t = static_cast<AddressBook *>(_o);
        switch (_id) {
        case 0: _t->filterChanged(); break;
        case 1: _t->setCurrentContact((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 2: _t->createContact(); break;
        case 3: _t->editContact(); break;
        case 4: _t->viewContact(); break;
        case 5: _t->deleteContact(); break;
        case 6: _t->filterContacts(); break;
        case 7: _t->onSearchFinished((*reinterpret_cast< QList<Contact>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddressBook::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddressBook::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AddressBook,
      qt_meta_data_AddressBook, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddressBook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddressBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddressBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddressBook))
        return static_cast<void*>(const_cast< AddressBook*>(this));
    return QObject::qt_metacast(_clname);
}

int AddressBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< bb::cascades::GroupDataModel**>(_v) = model(); break;
        case 1: *reinterpret_cast< QString*>(_v) = filter(); break;
        case 2: *reinterpret_cast< ContactViewer**>(_v) = contactViewer(); break;
        case 3: *reinterpret_cast< ContactEditor**>(_v) = contactEditor(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setFilter(*reinterpret_cast< QString*>(_v)); break;
        }
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
void AddressBook::filterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
