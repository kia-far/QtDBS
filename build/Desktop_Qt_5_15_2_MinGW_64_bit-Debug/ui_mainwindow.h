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
#include <QtGui/QIcon>
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
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        deviceBtn = new QPushButton(centralwidget);
        deviceBtn->setObjectName(QString::fromUtf8("deviceBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deviceBtn->sizePolicy().hasHeightForWidth());
        deviceBtn->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/images/Hardware.png"), QSize(), QIcon::Normal, QIcon::Off);
        deviceBtn->setIcon(icon);
        deviceBtn->setIconSize(QSize(200, 200));

        gridLayout->addWidget(deviceBtn, 0, 0, 1, 1);

        productBtn = new QPushButton(centralwidget);
        productBtn->setObjectName(QString::fromUtf8("productBtn"));
        sizePolicy.setHeightForWidth(productBtn->sizePolicy().hasHeightForWidth());
        productBtn->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/images/Products.png"), QSize(), QIcon::Normal, QIcon::Off);
        productBtn->setIcon(icon1);
        productBtn->setIconSize(QSize(0, 0));

        gridLayout->addWidget(productBtn, 0, 1, 1, 1);

        customerBtn = new QPushButton(centralwidget);
        customerBtn->setObjectName(QString::fromUtf8("customerBtn"));
        sizePolicy.setHeightForWidth(customerBtn->sizePolicy().hasHeightForWidth());
        customerBtn->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/images/Customers.png"), QSize(), QIcon::Normal, QIcon::Off);
        customerBtn->setIcon(icon2);

        gridLayout->addWidget(customerBtn, 1, 0, 1, 1);

        serviceBtn = new QPushButton(centralwidget);
        serviceBtn->setObjectName(QString::fromUtf8("serviceBtn"));
        sizePolicy.setHeightForWidth(serviceBtn->sizePolicy().hasHeightForWidth());
        serviceBtn->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/images/Services.png"), QSize(), QIcon::Normal, QIcon::Off);
        serviceBtn->setIcon(icon3);

        gridLayout->addWidget(serviceBtn, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
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
