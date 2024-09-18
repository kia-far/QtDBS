/********************************************************************************
** Form generated from reading UI file 'addabr.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDABR_H
#define UI_ADDABR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAbr
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *submitButton;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *AddAbr)
    {
        if (AddAbr->objectName().isEmpty())
            AddAbr->setObjectName(QString::fromUtf8("AddAbr"));
        AddAbr->resize(400, 300);
        AddAbr->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        verticalLayout_2 = new QVBoxLayout(AddAbr);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBox = new QComboBox(AddAbr);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_4->addWidget(comboBox);

        label = new QLabel(AddAbr);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);


        horizontalLayout->addLayout(horizontalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit = new QLineEdit(AddAbr);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);

        label_2 = new QLabel(AddAbr);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);


        horizontalLayout_2->addLayout(horizontalLayout_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        submitButton = new QPushButton(AddAbr);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        horizontalLayout_3->addWidget(submitButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AddAbr);

        QMetaObject::connectSlotsByName(AddAbr);
    } // setupUi

    void retranslateUi(QWidget *AddAbr)
    {
        AddAbr->setWindowTitle(QCoreApplication::translate("AddAbr", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddAbr", "\331\206\330\247\331\205 \330\257\330\263\330\252\332\257\330\247\331\207 :", nullptr));
        label_2->setText(QCoreApplication::translate("AddAbr", "\330\255\330\261\331\201 \330\254\330\257\333\214\330\257 :", nullptr));
        submitButton->setText(QCoreApplication::translate("AddAbr", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddAbr: public Ui_AddAbr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDABR_H
