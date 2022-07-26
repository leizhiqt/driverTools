/****************************************************************************
** Meta object code from reading C++ file 'buscomm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/buscomm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buscomm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_busComm_t {
    QByteArrayData data[29];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_busComm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_busComm_t qt_meta_stringdata_busComm = {
    {
QT_MOC_LITERAL(0, 0, 7), // "busComm"
QT_MOC_LITERAL(1, 8, 17), // "recvStringChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "onCloseThread"
QT_MOC_LITERAL(4, 41, 13), // "handleTimeout"
QT_MOC_LITERAL(5, 55, 15), // "onRecvStringMsg"
QT_MOC_LITERAL(6, 71, 2), // "fd"
QT_MOC_LITERAL(7, 74, 4), // "data"
QT_MOC_LITERAL(8, 79, 6), // "length"
QT_MOC_LITERAL(9, 86, 10), // "revcString"
QT_MOC_LITERAL(10, 97, 16), // "onRecvStringMsg1"
QT_MOC_LITERAL(11, 114, 14), // "onTheadSendMsg"
QT_MOC_LITERAL(12, 129, 7), // "busType"
QT_MOC_LITERAL(13, 137, 7), // "msgPack"
QT_MOC_LITERAL(14, 145, 4), // "size"
QT_MOC_LITERAL(15, 150, 12), // "checkHexSend"
QT_MOC_LITERAL(16, 163, 21), // "onRunAutoTestComplete"
QT_MOC_LITERAL(17, 185, 4), // "open"
QT_MOC_LITERAL(18, 190, 5), // "close"
QT_MOC_LITERAL(19, 196, 13), // "setRecvString"
QT_MOC_LITERAL(20, 210, 10), // "recvString"
QT_MOC_LITERAL(21, 221, 18), // "btnAutoTestClicked"
QT_MOC_LITERAL(22, 240, 7), // "sendMsg"
QT_MOC_LITERAL(23, 248, 9), // "pinConfig"
QT_MOC_LITERAL(24, 258, 3), // "pin"
QT_MOC_LITERAL(25, 262, 7), // "pinMode"
QT_MOC_LITERAL(26, 270, 12), // "writeDigital"
QT_MOC_LITERAL(27, 283, 5), // "value"
QT_MOC_LITERAL(28, 289, 11) // "readDigital"

    },
    "busComm\0recvStringChanged\0\0onCloseThread\0"
    "handleTimeout\0onRecvStringMsg\0fd\0data\0"
    "length\0revcString\0onRecvStringMsg1\0"
    "onTheadSendMsg\0busType\0msgPack\0size\0"
    "checkHexSend\0onRunAutoTestComplete\0"
    "open\0close\0setRecvString\0recvString\0"
    "btnAutoTestClicked\0sendMsg\0pinConfig\0"
    "pin\0pinMode\0writeDigital\0value\0"
    "readDigital"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_busComm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       1,  188, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    0,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  111,    2, 0x0a /* Public */,
       5,    3,  112,    2, 0x0a /* Public */,
       5,    2,  119,    2, 0x0a /* Public */,
       5,    3,  124,    2, 0x0a /* Public */,
       5,    2,  131,    2, 0x0a /* Public */,
       5,    1,  136,    2, 0x0a /* Public */,
      10,    3,  139,    2, 0x0a /* Public */,
      11,    5,  146,    2, 0x0a /* Public */,
      16,    0,  157,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      17,    0,  158,    2, 0x02 /* Public */,
      18,    0,  159,    2, 0x02 /* Public */,
      19,    1,  160,    2, 0x02 /* Public */,
      21,    0,  163,    2, 0x02 /* Public */,
      22,    5,  164,    2, 0x02 /* Public */,
      23,    2,  175,    2, 0x02 /* Public */,
      26,    2,  180,    2, 0x02 /* Public */,
      28,    1,  185,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int, QMetaType::Bool,   12,    6,   13,   14,   15,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int, QMetaType::Bool,   12,    6,   13,   14,   15,
    QMetaType::Int, QMetaType::Int, QMetaType::Char,   24,   25,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   24,   27,
    QMetaType::Int, QMetaType::Int,   24,

 // properties: name, type, flags
      20, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void busComm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<busComm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recvStringChanged(); break;
        case 1: _t->onCloseThread(); break;
        case 2: _t->handleTimeout(); break;
        case 3: _t->onRecvStringMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->onRecvStringMsg((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->onRecvStringMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->onRecvStringMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->onRecvStringMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->onRecvStringMsg1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->onTheadSendMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 10: _t->onRunAutoTestComplete(); break;
        case 11: _t->open(); break;
        case 12: { int _r = _t->close();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setRecvString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->btnAutoTestClicked(); break;
        case 15: { int _r = _t->sendMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { int _r = _t->pinConfig((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: { int _r = _t->writeDigital((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 18: { int _r = _t->readDigital((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (busComm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&busComm::recvStringChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (busComm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&busComm::onCloseThread)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<busComm *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->recvString(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<busComm *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRecvString(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject busComm::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_busComm.data,
    qt_meta_data_busComm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *busComm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *busComm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_busComm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int busComm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
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
void busComm::recvStringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void busComm::onCloseThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
