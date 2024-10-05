/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *deviceBtn;
    QPushButton *productBtn;
    QPushButton *customerBtn;
    QPushButton *serviceBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        MainWindow->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        deviceBtn = new QPushButton(centralwidget);
        deviceBtn->setObjectName(QString::fromUtf8("deviceBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deviceBtn->sizePolicy().hasHeightForWidth());
        deviceBtn->setSizePolicy(sizePolicy);
        deviceBtn->setIconSize(QSize(200, 200));

        gridLayout->addWidget(deviceBtn, 0, 0, 1, 1);

        productBtn = new QPushButton(centralwidget);
        productBtn->setObjectName(QString::fromUtf8("productBtn"));
        sizePolicy.setHeightForWidth(productBtn->sizePolicy().hasHeightForWidth());
        productBtn->setSizePolicy(sizePolicy);
        productBtn->setIconSize(QSize(200, 200));

        gridLayout->addWidget(productBtn, 0, 1, 1, 1);

        customerBtn = new QPushButton(centralwidget);
        customerBtn->setObjectName(QString::fromUtf8("customerBtn"));
        sizePolicy.setHeightForWidth(customerBtn->sizePolicy().hasHeightForWidth());
        customerBtn->setSizePolicy(sizePolicy);
        customerBtn->setIconSize(QSize(200, 200));

        gridLayout->addWidget(customerBtn, 1, 0, 1, 1);

        serviceBtn = new QPushButton(centralwidget);
        serviceBtn->setObjectName(QString::fromUtf8("serviceBtn"));
        sizePolicy.setHeightForWidth(serviceBtn->sizePolicy().hasHeightForWidth());
        serviceBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(serviceBtn, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\330\265\331\201\330\255\331\207 \330\247\330\265\331\204\333\214", nullptr));
        deviceBtn->setText(QString());
        productBtn->setText(QString());
        customerBtn->setText(QString());
        serviceBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
