/****************************************************************************
** Meta object code from reading C++ file 'rs422comm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/rs422comm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rs422comm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rs422Comm_t {
    QByteArrayData data[31];
    char stringdata0[357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rs422Comm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rs422Comm_t qt_meta_stringdata_rs422Comm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "rs422Comm"
QT_MOC_LITERAL(1, 10, 16), // "recvRS422Changed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "fd"
QT_MOC_LITERAL(4, 31, 21), // "recvBytesRS422Changed"
QT_MOC_LITERAL(5, 53, 21), // "sendBytesRS422Changed"
QT_MOC_LITERAL(6, 75, 15), // "hexRS422Changed"
QT_MOC_LITERAL(7, 91, 13), // "onCloseThread"
QT_MOC_LITERAL(8, 105, 14), // "send422ManData"
QT_MOC_LITERAL(9, 120, 4), // "data"
QT_MOC_LITERAL(10, 125, 6), // "length"
QT_MOC_LITERAL(11, 132, 14), // "onRS422RecvMsg"
QT_MOC_LITERAL(12, 147, 8), // "onClosed"
QT_MOC_LITERAL(13, 156, 16), // "onRecv422ManPara"
QT_MOC_LITERAL(14, 173, 4), // "int*"
QT_MOC_LITERAL(15, 178, 7), // "fdmPara"
QT_MOC_LITERAL(16, 186, 12), // "setRecvRS422"
QT_MOC_LITERAL(17, 199, 9), // "recvRS422"
QT_MOC_LITERAL(18, 209, 17), // "setRecvBytesRS422"
QT_MOC_LITERAL(19, 227, 14), // "recvBytesRS422"
QT_MOC_LITERAL(20, 242, 17), // "setSendBytesRS422"
QT_MOC_LITERAL(21, 260, 14), // "sendBytesRS422"
QT_MOC_LITERAL(22, 275, 11), // "setHexRS422"
QT_MOC_LITERAL(23, 287, 8), // "hexRS422"
QT_MOC_LITERAL(24, 296, 13), // "saveFileClick"
QT_MOC_LITERAL(25, 310, 8), // "saveFile"
QT_MOC_LITERAL(26, 319, 11), // "rs422Config"
QT_MOC_LITERAL(27, 331, 8), // "baudrate"
QT_MOC_LITERAL(28, 340, 4), // "bits"
QT_MOC_LITERAL(29, 345, 6), // "parity"
QT_MOC_LITERAL(30, 352, 4) // "stop"

    },
    "rs422Comm\0recvRS422Changed\0\0fd\0"
    "recvBytesRS422Changed\0sendBytesRS422Changed\0"
    "hexRS422Changed\0onCloseThread\0"
    "send422ManData\0data\0length\0onRS422RecvMsg\0"
    "onClosed\0onRecv422ManPara\0int*\0fdmPara\0"
    "setRecvRS422\0recvRS422\0setRecvBytesRS422\0"
    "recvBytesRS422\0setSendBytesRS422\0"
    "sendBytesRS422\0setHexRS422\0hexRS422\0"
    "saveFileClick\0saveFile\0rs422Config\0"
    "baudrate\0bits\0parity\0stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rs422Comm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    1,  112,    2, 0x06 /* Public */,
       5,    1,  115,    2, 0x06 /* Public */,
       6,    1,  118,    2, 0x06 /* Public */,
       7,    0,  121,    2, 0x06 /* Public */,
       8,    3,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    3,  129,    2, 0x0a /* Public */,
      12,    0,  136,    2, 0x0a /* Public */,
      13,    1,  137,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      16,    2,  140,    2, 0x02 /* Public */,
      18,    2,  145,    2, 0x02 /* Public */,
      20,    2,  150,    2, 0x02 /* Public */,
      22,    2,  155,    2, 0x02 /* Public */,
      24,    2,  160,    2, 0x02 /* Public */,
      26,    5,  165,    2, 0x02 /* Public */,
      26,    4,  176,    2, 0x22 /* Public | MethodCloned */,
      26,    3,  185,    2, 0x22 /* Public | MethodCloned */,
      26,    2,  192,    2, 0x22 /* Public | MethodCloned */,
      26,    1,  197,    2, 0x22 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int,    3,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int,    3,    9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Long,    3,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::Long,    3,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   25,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   27,   28,   29,   30,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   27,   28,   29,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   27,   28,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   27,
    QMetaType::Int, QMetaType::Int,    3,

       0        // eod
};

void rs422Comm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rs422Comm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recvRS422Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->recvBytesRS422Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->sendBytesRS422Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->hexRS422Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->onCloseThread(); break;
        case 5: _t->send422ManData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->onRS422RecvMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->onClosed(); break;
        case 8: _t->onRecv422ManPara((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 9: _t->setRecvRS422((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 10: _t->setRecvBytesRS422((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 11: _t->setSendBytesRS422((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 12: _t->setHexRS422((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->saveFileClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: { int _r = _t->rs422Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->rs422Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { int _r = _t->rs422Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: { int _r = _t->rs422Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 18: { int _r = _t->rs422Config((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (rs422Comm::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs422Comm::recvRS422Changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (rs422Comm::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs422Comm::recvBytesRS422Changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (rs422Comm::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs422Comm::sendBytesRS422Changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (rs422Comm::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs422Comm::hexRS422Changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (rs422Comm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs422Comm::onCloseThread)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (rs422Comm::*)(int , QByteArray , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs422Comm::send422ManData)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rs422Comm::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_rs422Comm.data,
    qt_meta_data_rs422Comm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rs422Comm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rs422Comm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rs422Comm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rs422Comm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void rs422Comm::recvRS422Changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rs422Comm::recvBytesRS422Changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rs422Comm::sendBytesRS422Changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rs422Comm::hexRS422Changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rs422Comm::onCloseThread()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void rs422Comm::send422ManData(int _t1, QByteArray _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
