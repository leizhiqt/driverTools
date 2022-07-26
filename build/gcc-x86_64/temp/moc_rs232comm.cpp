/****************************************************************************
** Meta object code from reading C++ file 'rs232comm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/rs232comm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rs232comm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rs232Comm_t {
    QByteArrayData data[27];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rs232Comm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rs232Comm_t qt_meta_stringdata_rs232Comm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "rs232Comm"
QT_MOC_LITERAL(1, 10, 16), // "recvRS232Changed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "fd"
QT_MOC_LITERAL(4, 31, 21), // "recvBytesRS232Changed"
QT_MOC_LITERAL(5, 53, 21), // "sendBytesRS232Changed"
QT_MOC_LITERAL(6, 75, 15), // "hexRS232Changed"
QT_MOC_LITERAL(7, 91, 13), // "onCloseThread"
QT_MOC_LITERAL(8, 105, 14), // "onRS232RecvMsg"
QT_MOC_LITERAL(9, 120, 4), // "data"
QT_MOC_LITERAL(10, 125, 6), // "length"
QT_MOC_LITERAL(11, 132, 8), // "onClosed"
QT_MOC_LITERAL(12, 141, 12), // "setRecvRS232"
QT_MOC_LITERAL(13, 154, 9), // "recvRS232"
QT_MOC_LITERAL(14, 164, 17), // "setRecvBytesRS232"
QT_MOC_LITERAL(15, 182, 14), // "recvBytesRS232"
QT_MOC_LITERAL(16, 197, 17), // "setSendBytesRS232"
QT_MOC_LITERAL(17, 215, 14), // "sendBytesRS232"
QT_MOC_LITERAL(18, 230, 13), // "saveFileClick"
QT_MOC_LITERAL(19, 244, 8), // "saveFile"
QT_MOC_LITERAL(20, 253, 11), // "setHexRS232"
QT_MOC_LITERAL(21, 265, 8), // "hexRS232"
QT_MOC_LITERAL(22, 274, 11), // "rs232Config"
QT_MOC_LITERAL(23, 286, 8), // "baudrate"
QT_MOC_LITERAL(24, 295, 4), // "bits"
QT_MOC_LITERAL(25, 300, 6), // "parity"
QT_MOC_LITERAL(26, 307, 4) // "stop"

    },
    "rs232Comm\0recvRS232Changed\0\0fd\0"
    "recvBytesRS232Changed\0sendBytesRS232Changed\0"
    "hexRS232Changed\0onCloseThread\0"
    "onRS232RecvMsg\0data\0length\0onClosed\0"
    "setRecvRS232\0recvRS232\0setRecvBytesRS232\0"
    "recvBytesRS232\0setSendBytesRS232\0"
    "sendBytesRS232\0saveFileClick\0saveFile\0"
    "setHexRS232\0hexRS232\0rs232Config\0"
    "baudrate\0bits\0parity\0stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rs232Comm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       5,    1,  105,    2, 0x06 /* Public */,
       6,    1,  108,    2, 0x06 /* Public */,
       7,    0,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,  112,    2, 0x0a /* Public */,
      11,    0,  119,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      12,    2,  120,    2, 0x02 /* Public */,
      14,    2,  125,    2, 0x02 /* Public */,
      16,    2,  130,    2, 0x02 /* Public */,
      18,    2,  135,    2, 0x02 /* Public */,
      20,    2,  140,    2, 0x02 /* Public */,
      22,    5,  145,    2, 0x02 /* Public */,
      22,    4,  156,    2, 0x22 /* Public | MethodCloned */,
      22,    3,  165,    2, 0x22 /* Public | MethodCloned */,
      22,    2,  172,    2, 0x22 /* Public | MethodCloned */,
      22,    1,  177,    2, 0x22 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int,    3,    9,   10,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Long,    3,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Long,    3,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   21,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   23,   24,   25,   26,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   23,   24,   25,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   23,   24,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   23,
    QMetaType::Int, QMetaType::Int,    3,

       0        // eod
};

void rs232Comm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rs232Comm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recvRS232Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->recvBytesRS232Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->sendBytesRS232Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->hexRS232Changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->onCloseThread(); break;
        case 5: _t->onRS232RecvMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->onClosed(); break;
        case 7: _t->setRecvRS232((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->setRecvBytesRS232((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 9: _t->setSendBytesRS232((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 10: _t->saveFileClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->setHexRS232((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: { int _r = _t->rs232Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->rs232Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->rs232Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->rs232Config((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { int _r = _t->rs232Config((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (rs232Comm::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs232Comm::recvRS232Changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (rs232Comm::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs232Comm::recvBytesRS232Changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (rs232Comm::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs232Comm::sendBytesRS232Changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (rs232Comm::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs232Comm::hexRS232Changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (rs232Comm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rs232Comm::onCloseThread)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rs232Comm::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_rs232Comm.data,
    qt_meta_data_rs232Comm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rs232Comm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rs232Comm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rs232Comm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rs232Comm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void rs232Comm::recvRS232Changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rs232Comm::recvBytesRS232Changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rs232Comm::sendBytesRS232Changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rs232Comm::hexRS232Changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rs232Comm::onCloseThread()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
