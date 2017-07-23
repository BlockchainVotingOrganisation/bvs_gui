/****************************************************************************
** Meta object code from reading C++ file 'bvs_wallet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bvs_wallet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bvs_wallet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BVS_Wallet_t {
    QByteArrayData data[9];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BVS_Wallet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BVS_Wallet_t qt_meta_stringdata_BVS_Wallet = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BVS_Wallet"
QT_MOC_LITERAL(1, 11, 29), // "on_action_Ausf_hren_triggered"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 29), // "on_actionWahl_ffnen_triggered"
QT_MOC_LITERAL(4, 72, 27), // "on_action_Beenden_triggered"
QT_MOC_LITERAL(5, 100, 29), // "on_actionAuswaehlen_triggered"
QT_MOC_LITERAL(6, 130, 32), // "on_actionEinstellungen_triggered"
QT_MOC_LITERAL(7, 163, 10), // "closeEvent"
QT_MOC_LITERAL(8, 174, 31) // "on_action_Stimmzettel_triggered"

    },
    "BVS_Wallet\0on_action_Ausf_hren_triggered\0"
    "\0on_actionWahl_ffnen_triggered\0"
    "on_action_Beenden_triggered\0"
    "on_actionAuswaehlen_triggered\0"
    "on_actionEinstellungen_triggered\0"
    "closeEvent\0on_action_Stimmzettel_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BVS_Wallet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BVS_Wallet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BVS_Wallet *_t = static_cast<BVS_Wallet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_Ausf_hren_triggered(); break;
        case 1: _t->on_actionWahl_ffnen_triggered(); break;
        case 2: _t->on_action_Beenden_triggered(); break;
        case 3: _t->on_actionAuswaehlen_triggered(); break;
        case 4: _t->on_actionEinstellungen_triggered(); break;
        case 5: _t->closeEvent(); break;
        case 6: _t->on_action_Stimmzettel_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BVS_Wallet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BVS_Wallet.data,
      qt_meta_data_BVS_Wallet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BVS_Wallet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BVS_Wallet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BVS_Wallet.stringdata0))
        return static_cast<void*>(const_cast< BVS_Wallet*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BVS_Wallet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
