/****************************************************************************
** Meta object code from reading C++ file 'afficheprojet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projet/afficheprojet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'afficheprojet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AfficheProjet_t {
    QByteArrayData data[6];
    char stringdata[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AfficheProjet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AfficheProjet_t qt_meta_stringdata_AfficheProjet = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AfficheProjet"
QT_MOC_LITERAL(1, 14, 14), // "supprimerTache"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "i"
QT_MOC_LITERAL(4, 32, 15), // "supprimerProjet"
QT_MOC_LITERAL(5, 48, 11) // "ajouteTache"

    },
    "AfficheProjet\0supprimerTache\0\0i\0"
    "supprimerProjet\0ajouteTache"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AfficheProjet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AfficheProjet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AfficheProjet *_t = static_cast<AfficheProjet *>(_o);
        switch (_id) {
        case 0: _t->supprimerTache((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->supprimerProjet(); break;
        case 2: _t->ajouteTache(); break;
        default: ;
        }
    }
}

const QMetaObject AfficheProjet::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AfficheProjet.data,
      qt_meta_data_AfficheProjet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AfficheProjet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AfficheProjet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AfficheProjet.stringdata))
        return static_cast<void*>(const_cast< AfficheProjet*>(this));
    return QDialog::qt_metacast(_clname);
}

int AfficheProjet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE