/********************************************************************************
** Form generated from reading UI file 'addoption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOPTION_H
#define UI_ADDOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddOption
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *AddOption)
    {
        if (AddOption->objectName().isEmpty())
            AddOption->setObjectName(QString::fromUtf8("AddOption"));
        AddOption->resize(247, 218);
        verticalLayout_2 = new QVBoxLayout(AddOption);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AddOption);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 30));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(AddOption);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(AddOption);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AddOption);

        QMetaObject::connectSlotsByName(AddOption);
    } // setupUi

    void retranslateUi(QWidget *AddOption)
    {
        AddOption->setWindowTitle(QCoreApplication::translate("AddOption", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddOption", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("AddOption", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddOption: public Ui_AddOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOPTION_H
