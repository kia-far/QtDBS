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
    QByteArrayData data[21];
    char stringdata0[302];
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
QT_MOC_LITERAL(9, 89, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(10, 121, 4), // "arg1"
QT_MOC_LITERAL(11, 126, 20), // "on_SubmitBtn_clicked"
QT_MOC_LITERAL(12, 147, 21), // "on_AddItemBtn_clicked"
QT_MOC_LITERAL(13, 169, 23), // "on_addDeviceBtn_clicked"
QT_MOC_LITERAL(14, 193, 32), // "on_CustomerCombo_editTextChanged"
QT_MOC_LITERAL(15, 226, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(16, 248, 12), // "populateEdit"
QT_MOC_LITERAL(17, 261, 6), // "device"
QT_MOC_LITERAL(18, 268, 2), // "id"
QT_MOC_LITERAL(19, 271, 20), // "on_AddDevBtn_clicked"
QT_MOC_LITERAL(20, 292, 9) // "adminMode"

    },
    "DeviceForm\0optionPage\0\0deviceName\0"
    "itemName\0itemPage\0devicePage\0addCustomer\0"
    "belongingPage\0on_comboBox_currentIndexChanged\0"
    "arg1\0on_SubmitBtn_clicked\0"
    "on_AddItemBtn_clicked\0on_addDeviceBtn_clicked\0"
    "on_CustomerCombo_editTextChanged\0"
    "on_pushButton_clicked\0populateEdit\0"
    "device\0id\0on_AddDevBtn_clicked\0adminMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    1,   89,    2, 0x06 /* Public */,
       6,    0,   92,    2, 0x06 /* Public */,
       7,    0,   93,    2, 0x06 /* Public */,
       8,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   97,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    1,  103,    2, 0x08 /* Private */,
      15,    0,  106,    2, 0x08 /* Private */,
      16,    2,  107,    2, 0x08 /* Private */,
      19,    0,  112,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   17,   18,
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
        case 5: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_SubmitBtn_clicked(); break;
        case 7: _t->on_AddItemBtn_clicked(); break;
        case 8: _t->on_addDeviceBtn_clicked(); break;
        case 9: _t->on_CustomerCombo_editTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->populateEdit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->on_AddDevBtn_clicked(); break;
        case 13: _t->adminMode(); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
