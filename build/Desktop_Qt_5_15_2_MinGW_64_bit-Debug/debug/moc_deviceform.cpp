/****************************************************************************
** Meta object code from reading C++ file 'deviceform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../deviceform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deviceform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceForm_t {
    QByteArrayData data[22];
    char stringdata0[299];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceForm_t qt_meta_stringdata_DeviceForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DeviceForm"
QT_MOC_LITERAL(1, 11, 10), // "optionPage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "deviceName"
QT_MOC_LITERAL(4, 34, 8), // "itemName"
QT_MOC_LITERAL(5, 43, 8), // "itemPage"
QT_MOC_LITERAL(6, 52, 10), // "devicePage"
QT_MOC_LITERAL(7, 63, 11), // "addCustomer"
QT_MOC_LITERAL(8, 75, 13), // "belongingPage"
QT_MOC_LITERAL(9, 89, 10), // "pageUpdate"
QT_MOC_LITERAL(10, 100, 6), // "addAbr"
QT_MOC_LITERAL(11, 107, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(12, 139, 4), // "arg1"
QT_MOC_LITERAL(13, 144, 20), // "on_SubmitBtn_clicked"
QT_MOC_LITERAL(14, 165, 21), // "on_AddItemBtn_clicked"
QT_MOC_LITERAL(15, 187, 32), // "on_CustomerCombo_editTextChanged"
QT_MOC_LITERAL(16, 220, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(17, 242, 12), // "populateEdit"
QT_MOC_LITERAL(18, 255, 6), // "device"
QT_MOC_LITERAL(19, 262, 2), // "id"
QT_MOC_LITERAL(20, 265, 9), // "adminMode"
QT_MOC_LITERAL(21, 275, 23) // "on_pushButton_2_clicked"

    },
    "DeviceForm\0optionPage\0\0deviceName\0"
    "itemName\0itemPage\0devicePage\0addCustomer\0"
    "belongingPage\0pageUpdate\0addAbr\0"
    "on_comboBox_currentIndexChanged\0arg1\0"
    "on_SubmitBtn_clicked\0on_AddItemBtn_clicked\0"
    "on_CustomerCombo_editTextChanged\0"
    "on_pushButton_clicked\0populateEdit\0"
    "device\0id\0adminMode\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       5,    1,   94,    2, 0x06 /* Public */,
       6,    0,   97,    2, 0x06 /* Public */,
       7,    0,   98,    2, 0x06 /* Public */,
       8,    1,   99,    2, 0x06 /* Public */,
       9,    0,  102,    2, 0x06 /* Public */,
      10,    0,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  104,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    2,  113,    2, 0x08 /* Private */,
      20,    0,  118,    2, 0x08 /* Private */,
      21,    0,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,   18,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DeviceForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->optionPage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->itemPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->devicePage(); break;
        case 3: _t->addCustomer(); break;
        case 4: _t->belongingPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->pageUpdate(); break;
        case 6: _t->addAbr(); break;
        case 7: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_SubmitBtn_clicked(); break;
        case 9: _t->on_AddItemBtn_clicked(); break;
        case 10: _t->on_CustomerCombo_editTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->populateEdit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 13: _t->adminMode(); break;
        case 14: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceForm::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceForm::optionPage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceForm::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceForm::itemPage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DeviceForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceForm::devicePage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DeviceForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceForm::addCustomer)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DeviceForm::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceForm::belongingPage)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DeviceForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceForm::pageUpdate)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DeviceForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceForm::addAbr)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeviceForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DeviceForm.data,
    qt_meta_data_DeviceForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DeviceForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void DeviceForm::optionPage(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeviceForm::itemPage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DeviceForm::devicePage()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DeviceForm::addCustomer()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DeviceForm::belongingPage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DeviceForm::pageUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void DeviceForm::addAbr()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
