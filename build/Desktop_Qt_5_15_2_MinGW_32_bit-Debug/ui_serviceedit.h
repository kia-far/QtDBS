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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serviceEdit
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *ProductCombo;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *CustomerCombo;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *textEdit;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *serviceEdit)
    {
        if (serviceEdit->objectName().isEmpty())
            serviceEdit->setObjectName(QString::fromUtf8("serviceEdit"));
        serviceEdit->resize(525, 397);
        serviceEdit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(228, 229, 244); /* Light gray background */\n"
"    border: 1px solid #a9a9a9; /* Darker gray border for a 3D effect */\n"
"    border-radius: 6px; /* Rounded corners */\n"
"    padding: 5px 10px; /* Padding for a button-like appearance */\n"
"    color: black; /* Text color */\n"
"    \n"
"    /* Subtle gradient for a shiny effect */\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 #f0f0f0, stop:1 #d3d3d3);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e6e6e6; /* Change to a lighter shade on hover */\n"
"    border-color: #b0b0b0; /* Change border color on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bfbfbf; /* Darker gray when pressed */\n"
"    border-color: #808080; /* Slightly darker border when pressed */\n"
"}\n"
"\n"
"\n"
"QWidget {font: 12pt \"Segoe UI\";}"));
        verticalLayout = new QVBoxLayout(serviceEdit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        ProductCombo = new QComboBox(serviceEdit);
        ProductCombo->setObjectName(QString::fromUtf8("ProductCombo"));
        ProductCombo->setEditable(true);

        horizontalLayout_8->addWidget(ProductCombo);

        label_7 = new QLabel(serviceEdit);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_8->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        CustomerCombo = new QComboBox(serviceEdit);
        CustomerCombo->setObjectName(QString::fromUtf8("CustomerCombo"));
        CustomerCombo->setEditable(true);

        horizontalLayout_7->addWidget(CustomerCombo);

        label_6 = new QLabel(serviceEdit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_7->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dateEdit = new QDateEdit(serviceEdit);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(false);

        horizontalLayout->addWidget(dateEdit);

        label = new QLabel(serviceEdit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMidLineWidth(1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_2 = new QLineEdit(serviceEdit);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_2);

        label_2 = new QLabel(serviceEdit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_3 = new QLineEdit(serviceEdit);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit_3);

        label_3 = new QLabel(serviceEdit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_5 = new QLineEdit(serviceEdit);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(lineEdit_5);

        label_5 = new QLabel(serviceEdit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        textEdit = new QTextEdit(serviceEdit);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setTabChangesFocus(true);

        horizontalLayout_5->addWidget(textEdit);

        label_4 = new QLabel(serviceEdit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButton = new QPushButton(serviceEdit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_6->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(serviceEdit);

        QMetaObject::connectSlotsByName(serviceEdit);
    } // setupUi

    void retranslateUi(QWidget *serviceEdit)
    {
        serviceEdit->setWindowTitle(QCoreApplication::translate("serviceEdit", "\330\256\330\257\331\205\330\247\330\252", nullptr));
        label_7->setText(QCoreApplication::translate("serviceEdit", "\331\205\330\255\330\265\331\210\331\204 :", nullptr));
        label_6->setText(QCoreApplication::translate("serviceEdit", "\331\205\330\264\330\252\330\261\333\214 :", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("serviceEdit", "yyyy/M/d", nullptr));
        label->setText(QCoreApplication::translate("serviceEdit", "\330\252\330\247\330\261\333\214\330\256 :", nullptr));
        label_2->setText(QCoreApplication::translate("serviceEdit", "\331\205\330\263\330\246\331\210\331\204 :", nullptr));
        label_3->setText(QCoreApplication::translate("serviceEdit", "\331\206\331\210\330\271 \330\256\330\257\331\205\330\247\330\252", nullptr));
        label_5->setText(QCoreApplication::translate("serviceEdit", "\331\202\330\267\330\271\331\207 \330\256\330\261\330\247\330\250 :", nullptr));
        label_4->setText(QCoreApplication::translate("serviceEdit", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252 :", nullptr));
        pushButton->setText(QCoreApplication::translate("serviceEdit", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serviceEdit: public Ui_serviceEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICEEDIT_H