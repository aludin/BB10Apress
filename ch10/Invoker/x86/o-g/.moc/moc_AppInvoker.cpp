/****************************************************************************
** Meta object code from reading C++ file 'AppInvoker.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/AppInvoker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppInvoker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AppInvoker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       1,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   29,   11,   11, 0x0a,
      61,   57,   11,   11, 0x0a,
     108,   82,   11,   11, 0x0a,
     150,   11,   11,   11, 0x0a,
     184,  164,   11,   11, 0x0a,
     242,  222,   11,   11, 0x0a,
     287,   11,   11,   11, 0x08,
     310,   11,   11,   11, 0x08,
     343,  335,   11,   11, 0x08,

 // properties: name, type, flags
     395,  383, 0x0b495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_AppInvoker[] = {
    "AppInvoker\0\0targetsChanged()\0fileName\0"
    "viewImage(QString)\0url\0openBrowser(QString)\0"
    "subject,body,participants\0"
    "createEvent(QString,QString,QVariantList)\0"
    "takePicture()\0mimeType,action,uri\0"
    "queryTargets(QString,QString,QString)\0"
    "targetId,action,uri\0"
    "invokeTargetWithUri(QString,QString,QString)\0"
    "onInvocationFinished()\0onQueryTargetsResponse()\0"
    "message\0onCardDone(bb::system::CardDoneMessage)\0"
    "QStringList\0targets\0"
};

void AppInvoker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AppInvoker *_t = static_cast<AppInvoker *>(_o);
        switch (_id) {
        case 0: _t->targetsChanged(); break;
        case 1: _t->viewImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->openBrowser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->createEvent((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariantList(*)>(_a[3]))); break;
        case 4: _t->takePicture(); break;
        case 5: _t->queryTargets((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->invokeTargetWithUri((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 7: _t->onInvocationFinished(); break;
        case 8: _t->onQueryTargetsResponse(); break;
        case 9: _t->onCardDone((*reinterpret_cast< const bb::system::CardDoneMessage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AppInvoker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AppInvoker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AppInvoker,
      qt_meta_data_AppInvoker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AppInvoker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AppInvoker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AppInvoker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AppInvoker))
        return static_cast<void*>(const_cast< AppInvoker*>(this));
    return QObject::qt_metacast(_clname);
}

int AppInvoker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< QStringList*>(_v) = targets(); break;
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
void AppInvoker::targetsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
