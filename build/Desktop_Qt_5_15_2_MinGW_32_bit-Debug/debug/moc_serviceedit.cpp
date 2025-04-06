/****************************************************************************
** Meta object code from reading C++ file 'serviceedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../serviceedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serviceedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serviceEdit_t {
    QByteArrayData data[14];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serviceEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serviceEdit_t qt_meta_stringdata_serviceEdit = {
    {
QT_MOC_LITERAL(0, 0, 11), // "serviceEdit"
QT_MOC_LITERAL(1, 12, 15), // "callPageRefresh"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "callHelpPop"
QT_MOC_LITERAL(4, 41, 4), // "text"
QT_MOC_LITERAL(5, 46, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 68, 32), // "on_CustomerCombo_editTextChanged"
QT_MOC_LITERAL(7, 101, 4), // "arg1"
QT_MOC_LITERAL(8, 106, 31), // "on_ProductCombo_editTextChanged"
QT_MOC_LITERAL(9, 138, 32), // "onProductComboCurrentTextChanged"
QT_MOC_LITERAL(10, 171, 25), // "on_ProductCombo_activated"
QT_MOC_LITERAL(11, 197, 5), // "index"
QT_MOC_LITERAL(12, 203, 24), // "onCustomerComboActivated"
QT_MOC_LITERAL(13, 228, 11) // "showHelpPop"

    },
    "serviceEdit\0callPageRefresh\0\0callHelpPop\0"
    "text\0on_pushButton_clicked\0"
    "on_CustomerCombo_editTextChanged\0arg1\0"
    "on_ProductCombo_editTextChanged\0"
    "onProductComboCurrentTextChanged\0"
    "on_ProductCombo_activated\0index\0"
    "onCustomerComboActivated\0showHelpPop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serviceEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   63,    2, 0x08 /* Private */,
       6,    1,   64,    2, 0x08 /* Private */,
       8,    1,   67,    2, 0x08 /* Private */,
       9,    1,   70,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      12,    1,   76,    2, 0x08 /* Private */,
      13,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

       0        // eod
};

void serviceEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serviceEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->callPageRefresh(); break;
        case 1: _t->callHelpPop((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_CustomerCombo_editTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_ProductCombo_editTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onProductComboCurrentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_ProductCombo_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onCustomerComboActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->showHelpPop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (serviceEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serviceEdit::callPageRefresh)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (serviceEdit::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serviceEdit::callHelpPop)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serviceEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_serviceEdit.data,
    qt_meta_data_serviceEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serviceEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serviceEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serviceEdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int serviceEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void serviceEdit::callPageRefresh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void serviceEdit::callHelpPop(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
