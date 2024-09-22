/********************************************************************************
** Form generated from reading UI file 'productregister.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTREGISTER_H
#define UI_PRODUCTREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductRegister
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_8;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *lineEdit_10;
    QLabel *label_7;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_11;
    QTextEdit *textEdit;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *devBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ProductRegister)
    {
        if (ProductRegister->objectName().isEmpty())
            ProductRegister->setObjectName(QString::fromUtf8("ProductRegister"));
        ProductRegister->resize(394, 438);
        ProductRegister->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        verticalLayout = new QVBoxLayout(ProductRegister);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_8 = new QLineEdit(ProductRegister);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 3, 0, 1, 1);

        label_3 = new QLabel(ProductRegister);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 1, 1, 1);

        label_5 = new QLabel(ProductRegister);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 10, 1, 1, 1);

        label_2 = new QLabel(ProductRegister);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        lineEdit_10 = new QLineEdit(ProductRegister);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        gridLayout->addWidget(lineEdit_10, 6, 0, 1, 1);

        label_7 = new QLabel(ProductRegister);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 12, 1, 1, 1);

        comboBox = new QComboBox(ProductRegister);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        lineEdit_11 = new QLineEdit(ProductRegister);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        gridLayout->addWidget(lineEdit_11, 7, 0, 1, 1);

        textEdit = new QTextEdit(ProductRegister);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 12, 0, 1, 1);

        dateEdit = new QDateEdit(ProductRegister);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout->addWidget(dateEdit, 10, 0, 1, 1);

        dateEdit_2 = new QDateEdit(ProductRegister);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        gridLayout->addWidget(dateEdit_2, 9, 0, 1, 1);

        label = new QLabel(ProductRegister);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        label_4 = new QLabel(ProductRegister);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 7, 1, 1, 1);

        label_6 = new QLabel(ProductRegister);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 9, 1, 1, 1);

        devBtn = new QPushButton(ProductRegister);
        devBtn->setObjectName(QString::fromUtf8("devBtn"));

        gridLayout->addWidget(devBtn, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(ProductRegister);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(lineEdit_8, lineEdit_10);
        QWidget::setTabOrder(lineEdit_10, lineEdit_11);
        QWidget::setTabOrder(lineEdit_11, textEdit);
        QWidget::setTabOrder(textEdit, pushButton);

        retranslateUi(ProductRegister);

        QMetaObject::connectSlotsByName(ProductRegister);
    } // setupUi

    void retranslateUi(QWidget *ProductRegister)
    {
        ProductRegister->setWindowTitle(QCoreApplication::translate("ProductRegister", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("ProductRegister", "\331\201\330\247\332\251\330\252\331\210\330\261 :", nullptr));
        label_5->setText(QCoreApplication::translate("ProductRegister", "\330\247\331\206\331\202\330\266\330\247\333\214 \332\257\330\247\330\261\330\247\331\206\330\252\333\214 :", nullptr));
        label_2->setText(QCoreApplication::translate("ProductRegister", "\331\206\330\247\331\205 \330\257\330\263\330\252\332\257\330\247\331\207 :", nullptr));
        label_7->setText(QCoreApplication::translate("ProductRegister", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252 :", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("ProductRegister", "yyyy/M/d", nullptr));
        dateEdit_2->setDisplayFormat(QCoreApplication::translate("ProductRegister", "yyyy/M/d", nullptr));
        label->setText(QCoreApplication::translate("ProductRegister", "\330\264\331\205\330\247\330\261\331\207 \330\263\330\261\333\214\330\247\331\204 :", nullptr));
        label_4->setText(QCoreApplication::translate("ProductRegister", "\330\264\331\205\330\247\330\261\331\207 anydesk :", nullptr));
        label_6->setText(QCoreApplication::translate("ProductRegister", "\330\252\330\247\330\261\333\214\330\256 \330\256\330\261\333\214\330\257 :", nullptr));
        devBtn->setText(QCoreApplication::translate("ProductRegister", "\330\252\331\206\330\270\333\214\331\205\330\247\330\252 \330\257\330\263\330\252\332\257\330\247\331\207", nullptr));
        pushButton->setText(QCoreApplication::translate("ProductRegister", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductRegister: public Ui_ProductRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTREGISTER_H
