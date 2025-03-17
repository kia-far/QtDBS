/********************************************************************************
** Form generated from reading UI file 'customcombobox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMCOMBOBOX_H
#define UI_CUSTOMCOMBOBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customcombobox
{
public:

    void setupUi(QWidget *customcombobox)
    {
        if (customcombobox->objectName().isEmpty())
            customcombobox->setObjectName(QString::fromUtf8("customcombobox"));
        customcombobox->resize(400, 300);

        retranslateUi(customcombobox);

        QMetaObject::connectSlotsByName(customcombobox);
    } // setupUi

    void retranslateUi(QWidget *customcombobox)
    {
        customcombobox->setWindowTitle(QCoreApplication::translate("customcombobox", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customcombobox: public Ui_customcombobox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMCOMBOBOX_H
