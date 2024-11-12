/****************************************************************************
** Meta object code from reading C++ file 'productregister.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../productregister.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'productregister.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProductRegister_t {
    QByteArrayData data[13];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProductRegister_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProductRegister_t qt_meta_stringdata_ProductRegister = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ProductRegister"
QT_MOC_LITERAL(1, 16, 10), // "devicePage"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "pageUpdate"
QT_MOC_LITERAL(4, 39, 6), // "addAbr"
QT_MOC_LITERAL(5, 46, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 68, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(7, 100, 5), // "index"
QT_MOC_LITERAL(8, 106, 17), // "on_devBtn_clicked"
QT_MOC_LITERAL(9, 124, 9), // "adminMode"
QT_MOC_LITERAL(10, 134, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(11, 158, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(12, 189, 4) // "arg1"

    },
    "ProductRegister\0devicePage\0\0pageUpdate\0"
    "addAbr\0on_pushButton_clicked\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_devBtn_clicked\0adminMode\0"
    "on_pushButton_2_clicked\0"
    "on_comboBox_currentTextChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductRegister[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void ProductRegister::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProductRegister *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->devicePage(); break;
        case 1: _t->pageUpdate(); break;
        case 2: _t->addAbr(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_devBtn_clicked(); break;
        case 6: _t->adminMode(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProductRegister::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductRegister::devicePage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProductRegister::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductRegister::pageUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProductRegister::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductRegister::addAbr)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProductRegister::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ProductRegister.data,
    qt_meta_data_ProductRegister,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProductRegister::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductRegister::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProductRegister.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ProductRegister::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ProductRegister::devicePage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProductRegister::pageUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ProductRegister::addAbr()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
