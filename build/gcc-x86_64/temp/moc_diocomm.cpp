/****************************************************************************
** Meta object code from reading C++ file 'diocomm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/diocomm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diocomm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dioComm_t {
    QByteArrayData data[18];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dioComm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dioComm_t qt_meta_stringdata_dioComm = {
    {
QT_MOC_LITERAL(0, 0, 7), // "dioComm"
QT_MOC_LITERAL(1, 8, 14), // "recvDIOChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 2), // "fd"
QT_MOC_LITERAL(4, 27, 16), // "enableDIOChanged"
QT_MOC_LITERAL(5, 44, 13), // "onCloseThread"
QT_MOC_LITERAL(6, 58, 12), // "onDIORecvMsg"
QT_MOC_LITERAL(7, 71, 9), // "highLevel"
QT_MOC_LITERAL(8, 81, 17), // "onDIODirectionMsg"
QT_MOC_LITERAL(9, 99, 14), // "onDIOEnableMsg"
QT_MOC_LITERAL(10, 114, 8), // "onClosed"
QT_MOC_LITERAL(11, 123, 11), // "onDIOLowMsg"
QT_MOC_LITERAL(12, 135, 13), // "qmlSetRecvDIO"
QT_MOC_LITERAL(13, 149, 9), // "recvDIO01"
QT_MOC_LITERAL(14, 159, 18), // "qmlSetDirectionDIO"
QT_MOC_LITERAL(15, 178, 12), // "directionDIO"
QT_MOC_LITERAL(16, 191, 12), // "setEnableDIO"
QT_MOC_LITERAL(17, 204, 9) // "enableDIO"

    },
    "dioComm\0recvDIOChanged\0\0fd\0enableDIOChanged\0"
    "onCloseThread\0onDIORecvMsg\0highLevel\0"
    "onDIODirectionMsg\0onDIOEnableMsg\0"
    "onClosed\0onDIOLowMsg\0qmlSetRecvDIO\0"
    "recvDIO01\0qmlSetDirectionDIO\0directionDIO\0"
    "setEnableDIO\0enableDIO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dioComm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       5,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   76,    2, 0x0a /* Public */,
       8,    2,   81,    2, 0x0a /* Public */,
       9,    2,   86,    2, 0x0a /* Public */,
      10,    0,   91,    2, 0x0a /* Public */,
      11,    0,   92,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      12,    2,   93,    2, 0x02 /* Public */,
      14,    2,   98,    2, 0x02 /* Public */,
      16,    2,  103,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    7,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   17,

       0        // eod
};

void dioComm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dioComm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recvDIOChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->enableDIOChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onCloseThread(); break;
        case 3: _t->onDIORecvMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->onDIODirectionMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->onDIOEnableMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->onClosed(); break;
        case 7: _t->onDIOLowMsg(); break;
        case 8: _t->qmlSetRecvDIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->qmlSetDirectionDIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->setEnableDIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dioComm::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dioComm::recvDIOChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (dioComm::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dioComm::enableDIOChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (dioComm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dioComm::onCloseThread)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dioComm::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_dioComm.data,
    qt_meta_data_dioComm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dioComm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dioComm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dioComm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int dioComm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void dioComm::recvDIOChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void dioComm::enableDIOChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void dioComm::onCloseThread()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
