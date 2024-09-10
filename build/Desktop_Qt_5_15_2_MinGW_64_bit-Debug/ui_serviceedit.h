/********************************************************************************
** Form generated from reading UI file 'serviceedit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICEEDIT_H
#define UI_SERVICEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serviceEdit
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QDateEdit *dateEdit;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *serviceEdit)
    {
        if (serviceEdit->objectName().isEmpty())
            serviceEdit->setObjectName(QString::fromUtf8("serviceEdit"));
        serviceEdit->resize(525, 377);
        gridLayout_5 = new QGridLayout(serviceEdit);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        lineEdit_4 = new QLineEdit(serviceEdit);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit_4, 4, 0, 1, 1);

        lineEdit = new QLineEdit(serviceEdit);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(serviceEdit);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit_2, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(serviceEdit);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit_3, 2, 0, 1, 1);

        lineEdit_5 = new QLineEdit(serviceEdit);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lineEdit_5, 5, 0, 1, 1);

        dateEdit = new QDateEdit(serviceEdit);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(false);

        gridLayout_2->addWidget(dateEdit, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        label = new QLabel(serviceEdit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMidLineWidth(1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(serviceEdit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(serviceEdit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(serviceEdit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(serviceEdit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(serviceEdit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 0, 1, 1);


        retranslateUi(serviceEdit);

        QMetaObject::connectSlotsByName(serviceEdit);
    } // setupUi

    void retranslateUi(QWidget *serviceEdit)
    {
        serviceEdit->setWindowTitle(QCoreApplication::translate("serviceEdit", "Form", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("serviceEdit", "yyyy/M/d", nullptr));
        label->setText(QCoreApplication::translate("serviceEdit", "\330\252\330\247\330\261\333\214\330\256 :", nullptr));
        label_2->setText(QCoreApplication::translate("serviceEdit", "\331\205\330\263\330\246\331\210\331\204 :", nullptr));
        label_3->setText(QCoreApplication::translate("serviceEdit", "\330\252\330\247\330\261\333\214\330\256 :", nullptr));
        label_4->setText(QCoreApplication::translate("serviceEdit", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252 :", nullptr));
        label_5->setText(QCoreApplication::translate("serviceEdit", "\331\202\330\267\330\271\331\207 \330\256\330\261\330\247\330\250 :", nullptr));
        pushButton->setText(QCoreApplication::translate("serviceEdit", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serviceEdit: public Ui_serviceEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICEEDIT_H
