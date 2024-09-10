/********************************************************************************
** Form generated from reading UI file 'customerform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERFORM_H
#define UI_CUSTOMERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerForm
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CustomerForm)
    {
        if (CustomerForm->objectName().isEmpty())
            CustomerForm->setObjectName(QString::fromUtf8("CustomerForm"));
        CustomerForm->resize(718, 519);
        verticalLayout = new QVBoxLayout(CustomerForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        lineEdit_4 = new QLineEdit(CustomerForm);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit_4, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(CustomerForm);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit_3, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(CustomerForm);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(CustomerForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        label_2 = new QLabel(CustomerForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(CustomerForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(CustomerForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(CustomerForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        retranslateUi(CustomerForm);

        QMetaObject::connectSlotsByName(CustomerForm);
    } // setupUi

    void retranslateUi(QWidget *CustomerForm)
    {
        CustomerForm->setWindowTitle(QCoreApplication::translate("CustomerForm", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("CustomerForm", "\331\206\330\247\331\205 :", nullptr));
        label_3->setText(QCoreApplication::translate("CustomerForm", "\330\264\331\205\330\247\330\261\331\207 \330\252\331\204\331\201\331\206 \331\207\331\205\330\261\330\247\331\207 :", nullptr));
        label_4->setText(QCoreApplication::translate("CustomerForm", "\331\206\330\247\331\205 \331\206\331\205\330\247\333\214\331\206\330\257\331\207 :", nullptr));
        pushButton->setText(QCoreApplication::translate("CustomerForm", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerForm: public Ui_CustomerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERFORM_H
