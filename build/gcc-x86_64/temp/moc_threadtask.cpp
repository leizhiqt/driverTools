/****************************************************************************
** Meta object code from reading C++ file 'threadtask.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/threadtask.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadtask.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadTask_t {
    QByteArrayData data[23];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadTask_t qt_meta_stringdata_ThreadTask = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ThreadTask"
QT_MOC_LITERAL(1, 11, 13), // "threadSendMsg"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "busType"
QT_MOC_LITERAL(4, 34, 2), // "fd"
QT_MOC_LITERAL(5, 37, 7), // "msgPack"
QT_MOC_LITERAL(6, 45, 4), // "size"
QT_MOC_LITERAL(7, 50, 12), // "checkHexSend"
QT_MOC_LITERAL(8, 63, 25), // "recvAutoTestStringChanged"
QT_MOC_LITERAL(9, 89, 4), // "data"
QT_MOC_LITERAL(10, 94, 6), // "length"
QT_MOC_LITERAL(11, 101, 10), // "revcString"
QT_MOC_LITERAL(12, 112, 16), // "recvRS232Changed"
QT_MOC_LITERAL(13, 129, 16), // "recvRS422Changed"
QT_MOC_LITERAL(14, 146, 14), // "recvDIOChanged"
QT_MOC_LITERAL(15, 161, 9), // "highLevel"
QT_MOC_LITERAL(16, 171, 19), // "directionDIOChanged"
QT_MOC_LITERAL(17, 191, 16), // "enableDIOChanged"
QT_MOC_LITERAL(18, 208, 19), // "runAutoTestComplete"
QT_MOC_LITERAL(19, 228, 17), // "recvDIOLowChanged"
QT_MOC_LITERAL(20, 246, 19), // "recvArinc429Changed"
QT_MOC_LITERAL(21, 266, 8), // "onClosed"
QT_MOC_LITERAL(22, 275, 20) // "onRecvSend422ManData"

    },
    "ThreadTask\0threadSendMsg\0\0busType\0fd\0"
    "msgPack\0size\0checkHexSend\0"
    "recvAutoTestStringChanged\0data\0length\0"
    "revcString\0recvRS232Changed\0"
    "recvRS422Changed\0recvDIOChanged\0"
    "highLevel\0directionDIOChanged\0"
    "enableDIOChanged\0runAutoTestComplete\0"
    "recvDIOLowChanged\0recvArinc429Changed\0"
    "onClosed\0onRecvSend422ManData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadTask[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   79,    2, 0x06 /* Public */,
       8,    2,   90,    2, 0x06 /* Public */,
       8,    1,   95,    2, 0x06 /* Public */,
      12,    3,   98,    2, 0x06 /* Public */,
      13,    3,  105,    2, 0x06 /* Public */,
      14,    2,  112,    2, 0x06 /* Public */,
      16,    2,  117,    2, 0x06 /* Public */,
      17,    2,  122,    2, 0x06 /* Public */,
      18,    0,  127,    2, 0x06 /* Public */,
      19,    0,  128,    2, 0x06 /* Public */,
      20,    3,  129,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    0,  136,    2, 0x08 /* Private */,
      22,    3,  137,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int, QMetaType::Bool,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int,    4,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int,    4,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    4,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    4,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    4,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,    4,    9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::Int,    4,    9,   10,

       0        // eod
};

void ThreadTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->threadSendMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 1: _t->recvAutoTestStringChanged((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->recvAutoTestStringChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->recvRS232Changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->recvRS422Changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->recvDIOChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->directionDIOChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->enableDIOChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->runAutoTestComplete(); break;
        case 9: _t->recvDIOLowChanged(); break;
        case 10: _t->recvArinc429Changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->onClosed(); break;
        case 12: _t->onRecvSend422ManData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadTask::*)(int , int , QByteArray , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::threadSendMsg)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)(QByteArray , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::recvAutoTestStringChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::recvAutoTestStringChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)(int , QByteArray , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::recvRS232Changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)(int , QByteArray , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::recvRS422Changed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::recvDIOChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::directionDIOChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::enableDIOChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::runAutoTestComplete)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::recvDIOLowChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ThreadTask::*)(int , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadTask::recvArinc429Changed)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThreadTask::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ThreadTask.data,
    qt_meta_data_ThreadTask,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThreadTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadTask.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ThreadTask::threadSendMsg(int _t1, int _t2, QByteArray _t3, int _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadTask::recvAutoTestStringChanged(QByteArray _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadTask::recvAutoTestStringChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ThreadTask::recvRS232Changed(int _t1, QByteArray _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ThreadTask::recvRS422Changed(int _t1, QByteArray _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ThreadTask::recvDIOChanged(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ThreadTask::directionDIOChanged(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ThreadTask::enableDIOChanged(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ThreadTask::runAutoTestComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ThreadTask::recvDIOLowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void ThreadTask::recvArinc429Changed(int _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
