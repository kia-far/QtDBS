/********************************************************************************
** Form generated from reading UI file 'requestform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUESTFORM_H
#define UI_REQUESTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RequestForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_5;
    QLineEdit *cell;
    QCheckBox *checkBox;
    QLineEdit *power;
    QCheckBox *checkBox_2;
    QLineEdit *sn;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QGridLayout *gridLayout_3;
    QLineEdit *charger;
    QLabel *label_5;
    QLineEdit *battery;
    QLabel *label_6;
    QLineEdit *board;
    QLabel *label_7;
    QLineEdit *motherBoard;
    QLabel *label_8;
    QLineEdit *memory;
    QLabel *label_9;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_11;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *RequestForm)
    {
        if (RequestForm->objectName().isEmpty())
            RequestForm->setObjectName(QString::fromUtf8("RequestForm"));
        RequestForm->resize(823, 555);
        RequestForm->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        layoutWidget = new QWidget(RequestForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 11, 781, 521));
        gridLayout_8 = new QGridLayout(layoutWidget);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        cell = new QLineEdit(layoutWidget);
        cell->setObjectName(QString::fromUtf8("cell"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cell->sizePolicy().hasHeightForWidth());
        cell->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(cell, 1, 0, 1, 2);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(checkBox, 2, 0, 1, 1);

        power = new QLineEdit(layoutWidget);
        power->setObjectName(QString::fromUtf8("power"));
        sizePolicy.setHeightForWidth(power->sizePolicy().hasHeightForWidth());
        power->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(power, 3, 0, 1, 2);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        sizePolicy1.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(checkBox_2, 2, 1, 1, 1);

        sn = new QLineEdit(layoutWidget);
        sn->setObjectName(QString::fromUtf8("sn"));
        sizePolicy.setHeightForWidth(sn->sizePolicy().hasHeightForWidth());
        sn->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(sn, 0, 0, 1, 2);


        gridLayout_7->addLayout(gridLayout_5, 0, 1, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_6->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_6->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 3, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(checkBox_3, 0, 0, 1, 1);

        checkBox_4 = new QCheckBox(layoutWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(checkBox_4->sizePolicy().hasHeightForWidth());
        checkBox_4->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(checkBox_4, 0, 1, 1, 1);

        checkBox_5 = new QCheckBox(layoutWidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        sizePolicy2.setHeightForWidth(checkBox_5->sizePolicy().hasHeightForWidth());
        checkBox_5->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(checkBox_5, 0, 2, 1, 1);

        checkBox_6 = new QCheckBox(layoutWidget);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        sizePolicy2.setHeightForWidth(checkBox_6->sizePolicy().hasHeightForWidth());
        checkBox_6->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(checkBox_6, 1, 0, 1, 1);

        checkBox_7 = new QCheckBox(layoutWidget);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        sizePolicy2.setHeightForWidth(checkBox_7->sizePolicy().hasHeightForWidth());
        checkBox_7->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(checkBox_7, 1, 1, 1, 1);

        checkBox_8 = new QCheckBox(layoutWidget);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        sizePolicy2.setHeightForWidth(checkBox_8->sizePolicy().hasHeightForWidth());
        checkBox_8->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(checkBox_8, 1, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_4, 1, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        charger = new QLineEdit(layoutWidget);
        charger->setObjectName(QString::fromUtf8("charger"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(charger->sizePolicy().hasHeightForWidth());
        charger->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(charger, 0, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);

        battery = new QLineEdit(layoutWidget);
        battery->setObjectName(QString::fromUtf8("battery"));
        sizePolicy4.setHeightForWidth(battery->sizePolicy().hasHeightForWidth());
        battery->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(battery, 1, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy5.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label_6, 1, 1, 1, 1);

        board = new QLineEdit(layoutWidget);
        board->setObjectName(QString::fromUtf8("board"));
        sizePolicy4.setHeightForWidth(board->sizePolicy().hasHeightForWidth());
        board->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(board, 2, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy5.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label_7, 2, 1, 1, 1);

        motherBoard = new QLineEdit(layoutWidget);
        motherBoard->setObjectName(QString::fromUtf8("motherBoard"));
        sizePolicy4.setHeightForWidth(motherBoard->sizePolicy().hasHeightForWidth());
        motherBoard->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(motherBoard, 3, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy5.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label_8, 3, 1, 1, 1);

        memory = new QLineEdit(layoutWidget);
        memory->setObjectName(QString::fromUtf8("memory"));
        sizePolicy4.setHeightForWidth(memory->sizePolicy().hasHeightForWidth());
        memory->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(memory, 4, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy5.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label_9, 4, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_3, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBox_12 = new QCheckBox(layoutWidget);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        sizePolicy2.setHeightForWidth(checkBox_12->sizePolicy().hasHeightForWidth());
        checkBox_12->setSizePolicy(sizePolicy2);
        checkBox_12->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        gridLayout_2->addWidget(checkBox_12, 0, 0, 1, 1);

        checkBox_9 = new QCheckBox(layoutWidget);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        sizePolicy2.setHeightForWidth(checkBox_9->sizePolicy().hasHeightForWidth());
        checkBox_9->setSizePolicy(sizePolicy2);
        checkBox_9->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        checkBox_9->setAutoFillBackground(false);

        gridLayout_2->addWidget(checkBox_9, 0, 1, 1, 1);

        checkBox_13 = new QCheckBox(layoutWidget);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));
        sizePolicy2.setHeightForWidth(checkBox_13->sizePolicy().hasHeightForWidth());
        checkBox_13->setSizePolicy(sizePolicy2);
        checkBox_13->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        gridLayout_2->addWidget(checkBox_13, 1, 0, 1, 1);

        checkBox_10 = new QCheckBox(layoutWidget);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        sizePolicy2.setHeightForWidth(checkBox_10->sizePolicy().hasHeightForWidth());
        checkBox_10->setSizePolicy(sizePolicy2);
        checkBox_10->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        gridLayout_2->addWidget(checkBox_10, 1, 1, 1, 1);

        checkBox_14 = new QCheckBox(layoutWidget);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));
        sizePolicy2.setHeightForWidth(checkBox_14->sizePolicy().hasHeightForWidth());
        checkBox_14->setSizePolicy(sizePolicy2);
        checkBox_14->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        gridLayout_2->addWidget(checkBox_14, 2, 0, 1, 1);

        checkBox_11 = new QCheckBox(layoutWidget);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        sizePolicy2.setHeightForWidth(checkBox_11->sizePolicy().hasHeightForWidth());
        checkBox_11->setSizePolicy(sizePolicy2);
        checkBox_11->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        gridLayout_2->addWidget(checkBox_11, 2, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 2, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout, 3, 0, 1, 2);


        retranslateUi(RequestForm);

        QMetaObject::connectSlotsByName(RequestForm);
    } // setupUi

    void retranslateUi(QWidget *RequestForm)
    {
        RequestForm->setWindowTitle(QCoreApplication::translate("RequestForm", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("RequestForm", "Pactos", nullptr));
        checkBox_2->setText(QCoreApplication::translate("RequestForm", "Metec with power", nullptr));
        label->setText(QCoreApplication::translate("RequestForm", "\330\264\331\205\330\247\330\261\331\207 \330\263\330\261\333\214\330\247\331\204 :", nullptr));
        label_2->setText(QCoreApplication::translate("RequestForm", "Cell:", nullptr));
        label_3->setText(QCoreApplication::translate("RequestForm", "USB:", nullptr));
        label_4->setText(QCoreApplication::translate("RequestForm", "Power:", nullptr));
        checkBox_3->setText(QCoreApplication::translate("RequestForm", "USB Cable", nullptr));
        checkBox_4->setText(QCoreApplication::translate("RequestForm", "\332\251\333\214\331\201", nullptr));
        checkBox_5->setText(QCoreApplication::translate("RequestForm", "\330\262\333\214\330\261 \332\251\333\214\330\250\330\261\330\257", nullptr));
        checkBox_6->setText(QCoreApplication::translate("RequestForm", "Navid", nullptr));
        checkBox_7->setText(QCoreApplication::translate("RequestForm", "pacjaws", nullptr));
        checkBox_8->setText(QCoreApplication::translate("RequestForm", "\330\263\330\247\331\205\330\247\331\206\331\207", nullptr));
        label_5->setText(QCoreApplication::translate("RequestForm", "\330\264\330\247\330\261\332\230\330\261:", nullptr));
        label_6->setText(QCoreApplication::translate("RequestForm", "\330\250\330\247\330\267\330\261\333\214:", nullptr));
        label_7->setText(QCoreApplication::translate("RequestForm", "\330\250\330\261\330\257 ACC :", nullptr));
        label_8->setText(QCoreApplication::translate("RequestForm", "\331\205\330\247\330\257\330\261\330\250\330\261\330\257:", nullptr));
        label_9->setText(QCoreApplication::translate("RequestForm", "\330\255\330\247\331\201\330\270\331\207:", nullptr));
        checkBox_12->setText(QCoreApplication::translate("RequestForm", "\330\252\330\250\330\257\333\214\331\204 2 \330\250\331\207 1 \330\247\330\263\330\252\330\261\333\214\331\210", nullptr));
        checkBox_9->setText(QCoreApplication::translate("RequestForm", "\332\251\330\247\330\250\331\204 Extended \330\247\330\263\330\252\330\261\333\214\331\210", nullptr));
        checkBox_13->setText(QCoreApplication::translate("RequestForm", "\332\251\330\247\330\250\331\204 HDMI", nullptr));
        checkBox_10->setText(QCoreApplication::translate("RequestForm", "\332\251\330\247\330\250\331\204 LAN ", nullptr));
        checkBox_14->setText(QCoreApplication::translate("RequestForm", "DVD \330\261\330\247\331\207\331\206\331\205\330\247", nullptr));
        checkBox_11->setText(QCoreApplication::translate("RequestForm", "\330\261\330\247\331\207\331\206\331\205\330\247\333\214 \330\250\330\261\333\214\331\204", nullptr));
        pushButton->setText(QCoreApplication::translate("RequestForm", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RequestForm: public Ui_RequestForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTFORM_H
