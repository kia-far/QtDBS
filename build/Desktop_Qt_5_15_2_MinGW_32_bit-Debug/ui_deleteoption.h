/********************************************************************************
** Form generated from reading UI file 'deleteoption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEOPTION_H
#define UI_DELETEOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteOption
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QWidget *DeleteOption)
    {
        if (DeleteOption->objectName().isEmpty())
            DeleteOption->setObjectName(QString::fromUtf8("DeleteOption"));
        DeleteOption->resize(250, 200);
        DeleteOption->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"QWidget {font: 11pt \"Segoe UI\";}\n"
"QWidget {\n"
"    background-color: #d0dae1; /* Dark background color for the entire widge"
                        "t */\n"
"    font: 11pt \"Segoe UI\";\n"
"}\n"
"\n"
"/* Style for QLineEdit with a darker background and smoother edges */\n"
"QLineEdit {\n"
"    background-color: #eff3f5; /* Darker grayish background */\n"
"    color: #000000; /* Light text color for readability */\n"
"    border: 1px solid #5c5c70; /* Slightly lighter border for contrast */\n"
"    border-radius: 6px; /* Smooth, rounded edges */\n"
"    padding: 5px; /* Padding for a cleaner look */\n"
"    font: 11pt \"Segoe UI\";\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #7878a0; /* Lighter border color on focus */\n"
"    background-color: #e0e6eb; /* Slightly lighter background on focus */\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    background-color: #eff3f5; /* Darker grayish background */\n"
"    color: #000000; /* Light text color for readability */\n"
"    border: 1px solid #5c5c70; /* Slightly lighter border for contrast */\n"
"    border-radius: 6px; /* Smooth, rounded edges */\n"
"    padding: 5px; /* Padding for a cleaner look */\n"
"   "
                        " font: 11pt \"Segoe UI\";\n"
"}\n"
"\n"
"QTextBrowser:focus {\n"
"    border-color: #7878a0; /* Lighter border color on focus */\n"
"    background-color: #e0e6eb; /* Slightly lighter background on focus */\n"
"}\n"
"\n"
"QCheckBox {\n"
"    color: #000000; /* Light text color for dark background */\n"
"    font: 11pt \"Segoe UI\";\n"
"}\n"
"\n"
"QCheckBox:disabled {\n"
"    color: #000000; /* Same text color for disabled state */\n"
"    opacity: 1; /* Remove opacity reduction */\n"
"}\n"
"\n"
"/* Blue indicator for checked and disabled QCheckBox */\n"
"QCheckBox::indicator:checked:disabled {\n"
"    background-color: #92a8b9; /* Blue color to appear as enabled */\n"
"	opacity: 1;\n"
"   /* border: 1px solid #3a7bd5;  Blue border to match the indicator */\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled {\n"
"    opacity: 1; /* Remove opacity change for checkbox indicator */\n"
"}\n"
"\n"
"/* Background color for QWidget */\n"
"/* Style for the vertical scrollbar */\n"
"QScrollBar:vertical {\n"
"    background: #"
                        "eff3f5; /* Background color of the scrollbar */\n"
"    width: 10px; /* Width of the scrollbar */\n"
"    margin: 0px 0px 0px 0px; /* Margins around the scrollbar */\n"
"    border-radius: 5px; /* Rounded edges for the scrollbar track */\n"
"}\n"
"\n"
"/* Style for the horizontal scrollbar */\n"
"QScrollBar:horizontal {\n"
"    background: #eff3f5; /* Background color of the scrollbar */\n"
"    height: 10px; /* Height of the scrollbar */\n"
"    margin: 0px 0px 0px 0px; /* Margins around the scrollbar */\n"
"    border-radius: 5px; /* Rounded edges for the scrollbar track */\n"
"}\n"
"\n"
"/* Handle (scroller) styling for both horizontal and vertical scrollbars */\n"
"QScrollBar::handle:vertical, QScrollBar::handle:horizontal {\n"
"    background: #92a8b9; /* Color of the scroller */\n"
"    min-height: 20px; /* Minimum height for the vertical handle */\n"
"    min-width: 20px; /* Minimum width for the horizontal handle */\n"
"    border-radius: 5px; /* Smooth, rounded edges for the handle */\n"
"}\n"
"\n"
"Q"
                        "ScrollBar::handle:vertical:hover, QScrollBar::handle:horizontal:hover {\n"
"    background: #b1c1cd; /* Slightly lighter color on hover for the handle */\n"
"}\n"
"\n"
"/* Remove the top/bottom buttons on the scrollbar */\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical,\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    background: none; /* No additional lines/buttons */\n"
"    height: 0px;\n"
"    width: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical,\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"    background: none; /* No page scroll styling */\n"
"}\n"
"QTextEdit {\n"
"    background-color: #eff3f5; /* Darker grayish background */\n"
"    color: #000000; /* Light text color for readability */\n"
"    border: 1px solid #5c5c70; /* Slightly lighter border for contrast */\n"
"    border-radius: 6px; /* Smooth, rounded edges */\n"
"    padding: 5px; /* Padding for a cleaner look */\n"
"    font: 11pt \""
                        "Segoe UI\";\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border-color: #7878a0; /* Lighter border color on focus */\n"
"    background-color: #e0e6eb; /* Slightly lighter background on focus */\n"
"}\n"
"QComboBox {\n"
"    background-color: #eff3f5; /* Darker grayish background */\n"
"    color: #000000; /* Light text color for readability */\n"
"    border: 1px solid #5c5c70; /* Slightly lighter border for contrast */\n"
"    border-radius: 6px; /* Smooth, rounded edges */\n"
"    padding: 5px; /* Padding for a cleaner look */\n"
"    font: 11pt \"Segoe UI\";\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border-color: #7878a0; /* Lighter border color on focus */\n"
"    background-color: #e0e6eb; /* Slightly lighter background on focus */\n"
"}\n"
"QDateEdit {\n"
"    background-color: #eff3f5; /* Darker grayish background */\n"
"    color: #000000; /* Light text color for readability */\n"
"    border: 1px solid #5c5c70; /* Slightly lighter border for contrast */\n"
"    border-radius: 6px; /* Smooth, rounded edges "
                        "*/\n"
"    padding: 5px; /* Padding for a cleaner look */\n"
"    font: 11pt \"Segoe UI\";\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border-color: #7878a0; /* Lighter border color on focus */\n"
"    background-color: #e0e6eb; /* Slightly lighter background on focus */\n"
"}"));
        horizontalLayout = new QHBoxLayout(DeleteOption);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DeleteOption);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 30));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        comboBox = new QComboBox(DeleteOption);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEditable(false);

        verticalLayout_3->addWidget(comboBox);


        verticalLayout->addLayout(verticalLayout_3);

        pushButton = new QPushButton(DeleteOption);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(DeleteOption);

        QMetaObject::connectSlotsByName(DeleteOption);
    } // setupUi

    void retranslateUi(QWidget *DeleteOption)
    {
        DeleteOption->setWindowTitle(QCoreApplication::translate("DeleteOption", "Form", nullptr));
        label->setText(QCoreApplication::translate("DeleteOption", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("DeleteOption", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteOption: public Ui_DeleteOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEOPTION_H
