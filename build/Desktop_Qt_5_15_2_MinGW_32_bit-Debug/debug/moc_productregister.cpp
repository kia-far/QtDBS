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
    QByteArrayData data[16];
    char stringdata0[223];
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
QT_MOC_LITERAL(5, 46, 11), // "callHelpPop"
QT_MOC_LITERAL(6, 58, 4), // "text"
QT_MOC_LITERAL(7, 63, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 85, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(9, 117, 5), // "index"
QT_MOC_LITERAL(10, 123, 17), // "on_devBtn_clicked"
QT_MOC_LITERAL(11, 141, 9), // "adminMode"
QT_MOC_LITERAL(12, 151, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(13, 175, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(14, 206, 4), // "arg1"
QT_MOC_LITERAL(15, 211, 11) // "showHelpPop"

    },
    "ProductRegister\0devicePage\0\0pageUpdate\0"
    "addAbr\0callHelpPop\0text\0on_pushButton_clicked\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_devBtn_clicked\0adminMode\0"
    "on_pushButton_2_clicked\0"
    "on_comboBox_currentTextChanged\0arg1\0"
    "showHelpPop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductRegister[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   75,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    1,   82,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,

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
        case 3: _t->callHelpPop((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_devBtn_clicked(); break;
        case 7: _t->adminMode(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->showHelpPop(); break;
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
        {
            using _t = void (ProductRegister::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductRegister::callHelpPop)) {
                *result = 3;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
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

// SIGNAL 3
void ProductRegister::callHelpPop(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
