/********************************************************************************
** Form generated from reading UI file 'deviceform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEFORM_H
#define UI_DEVICEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_DeviceForm
{
public:
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *AddItemBtn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QComboBox *CustomerCombo;
    QLabel *label_3;
    QVBoxLayout *vb;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_8;
    QGridLayout *cbg;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *SubmitBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DeviceForm)
    {
        if (DeviceForm->objectName().isEmpty())
            DeviceForm->setObjectName(QString::fromUtf8("DeviceForm"));
        DeviceForm->resize(665, 561);
        horizontalLayout_10 = new QHBoxLayout(DeviceForm);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_4 = new QSpacerItem(306, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox = new QComboBox(DeviceForm);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(comboBox);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        AddItemBtn = new QPushButton(DeviceForm);
        AddItemBtn->setObjectName(QString::fromUtf8("AddItemBtn"));

        horizontalLayout_7->addWidget(AddItemBtn);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(verticalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        lineEdit = new QLineEdit(DeviceForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(DeviceForm);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton = new QPushButton(DeviceForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMaximumSize(QSize(40, 16777215));
        pushButton->setSizeIncrement(QSize(0, 0));

        horizontalLayout_3->addWidget(pushButton);

        CustomerCombo = new QComboBox(DeviceForm);
        CustomerCombo->setObjectName(QString::fromUtf8("CustomerCombo"));
        sizePolicy1.setHeightForWidth(CustomerCombo->sizePolicy().hasHeightForWidth());
        CustomerCombo->setSizePolicy(sizePolicy1);
        CustomerCombo->setEditable(true);

        horizontalLayout_3->addWidget(CustomerCombo);

        label_3 = new QLabel(DeviceForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_4);


        verticalLayout->addLayout(verticalLayout_3);

        vb = new QVBoxLayout();
        vb->setObjectName(QString::fromUtf8("vb"));
        vb->setSizeConstraint(QLayout::SetMinimumSize);

        verticalLayout->addLayout(vb);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        textEdit = new QTextEdit(DeviceForm);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setTabChangesFocus(true);

        horizontalLayout_2->addWidget(textEdit);

        label_2 = new QLabel(DeviceForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        cbg = new QGridLayout();
        cbg->setObjectName(QString::fromUtf8("cbg"));
        cbg->setSizeConstraint(QLayout::SetMinimumSize);

        horizontalLayout_8->addLayout(cbg);

        label_4 = new QLabel(DeviceForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_4);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        SubmitBtn = new QPushButton(DeviceForm);
        SubmitBtn->setObjectName(QString::fromUtf8("SubmitBtn"));

        horizontalLayout_4->addWidget(SubmitBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout_10->addLayout(verticalLayout);

        QWidget::setTabOrder(comboBox, lineEdit);
        QWidget::setTabOrder(lineEdit, CustomerCombo);
        QWidget::setTabOrder(CustomerCombo, textEdit);
        QWidget::setTabOrder(textEdit, SubmitBtn);
        QWidget::setTabOrder(SubmitBtn, AddItemBtn);
        QWidget::setTabOrder(AddItemBtn, pushButton);

        retranslateUi(DeviceForm);

        QMetaObject::connectSlotsByName(DeviceForm);
    } // setupUi

    void retranslateUi(QWidget *DeviceForm)
    {
        DeviceForm->setWindowTitle(QCoreApplication::translate("DeviceForm", "Form", nullptr));
        AddItemBtn->setText(QCoreApplication::translate("DeviceForm", "\330\247\331\201\330\262\331\210\330\257\331\206 \331\202\330\267\330\271\331\207", nullptr));
        label->setText(QCoreApplication::translate("DeviceForm", "\330\264\331\205\330\247\330\261\331\207 \330\263\330\261\333\214\330\247\331\204 :", nullptr));
        pushButton->setText(QCoreApplication::translate("DeviceForm", "+", nullptr));
        label_3->setText(QCoreApplication::translate("DeviceForm", "\331\206\330\247\331\205 \330\256\330\261\333\214\330\257\330\247\330\261 :", nullptr));
        label_2->setText(QCoreApplication::translate("DeviceForm", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252 :", nullptr));
        label_4->setText(QCoreApplication::translate("DeviceForm", "\331\205\330\252\330\271\331\204\331\202\330\247\330\252 :", nullptr));
        SubmitBtn->setText(QCoreApplication::translate("DeviceForm", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceForm: public Ui_DeviceForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEFORM_H