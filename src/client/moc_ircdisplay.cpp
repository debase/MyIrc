//
// moc_ircdisplay.cpp for moc_ircdisplay in /tmp/PSU_2013_myirc/src/client
//
// Made by Etienne
// Login   <debas_e@epitech.net>
//
// Started on  Sun Apr 27 01:49:46 2014 Etienne
// Last update Sun Apr 27 01:49:46 2014 Etienne
//

/****************************************************************************
** Meta object code from reading C++ file 'ircdisplay.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ircdisplay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircdisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ircDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      19,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ircDisplay[] = {
    "ircDisplay\0\0loop()\0sendDisplay()\0"
};

void ircDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ircDisplay *_t = static_cast<ircDisplay *>(_o);
        switch (_id) {
        case 0: _t->loop(); break;
        case 1: _t->sendDisplay(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ircDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall
};

const QMetaObject ircDisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ircDisplay,
      qt_meta_data_ircDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ircDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ircDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ircDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ircDisplay))
        return static_cast<void*>(const_cast< ircDisplay*>(this));
    return QWidget::qt_metacast(_clname);
}

int ircDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
