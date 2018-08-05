/****************************************************************************
** Meta object code from reading C++ file 'serverthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/serverthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerThread_t {
    QByteArrayData data[14];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerThread_t qt_meta_stringdata_ServerThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ServerThread"
QT_MOC_LITERAL(1, 13, 5), // "error"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 23), // "QTcpSocket::SocketError"
QT_MOC_LITERAL(4, 44, 11), // "socketError"
QT_MOC_LITERAL(5, 56, 9), // "signalLog"
QT_MOC_LITERAL(6, 66, 9), // "signalEnd"
QT_MOC_LITERAL(7, 76, 10), // "signalSend"
QT_MOC_LITERAL(8, 87, 12), // "disconnected"
QT_MOC_LITERAL(9, 100, 12), // "bytesWritten"
QT_MOC_LITERAL(10, 113, 5), // "bytes"
QT_MOC_LITERAL(11, 119, 9), // "readyRead"
QT_MOC_LITERAL(12, 129, 8), // "slotSend"
QT_MOC_LITERAL(13, 138, 3) // "str"

    },
    "ServerThread\0error\0\0QTcpSocket::SocketError\0"
    "socketError\0signalLog\0signalEnd\0"
    "signalSend\0disconnected\0bytesWritten\0"
    "bytes\0readyRead\0slotSend\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       6,    0,   60,    2, 0x06 /* Public */,
       7,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   64,    2, 0x0a /* Public */,
       9,    1,   65,    2, 0x0a /* Public */,
      11,    0,   68,    2, 0x0a /* Public */,
      12,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void ServerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerThread *_t = static_cast<ServerThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->signalLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalEnd(); break;
        case 3: _t->signalSend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->disconnected(); break;
        case 5: _t->bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->readyRead(); break;
        case 7: _t->slotSend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerThread::*)(QTcpSocket::SocketError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerThread::error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ServerThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerThread::signalLog)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ServerThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerThread::signalEnd)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ServerThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerThread::signalSend)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServerThread.data,
      qt_meta_data_ServerThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ServerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ServerThread::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerThread::signalLog(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ServerThread::signalEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ServerThread::signalSend(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
