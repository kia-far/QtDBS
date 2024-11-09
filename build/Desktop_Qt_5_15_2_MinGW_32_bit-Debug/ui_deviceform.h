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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceForm
{
public:
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QComboBox *CustomerCombo;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_7;
    QDateEdit *dateEdit;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_8;
    QDateEdit *dateEdit_2;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_6;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *vb;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;
    QPushButton *AddItemBtn;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_10;
    QGridLayout *cbg;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *SubmitBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DeviceForm)
    {
        if (DeviceForm->objectName().isEmpty())
            DeviceForm->setObjectName(QString::fromUtf8("DeviceForm"));
        DeviceForm->resize(665, 656);
        DeviceForm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        horizontalLayout_10 = new QHBoxLayout(DeviceForm);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
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
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

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

        label_5 = new QLabel(DeviceForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        pushButton_2 = new QPushButton(DeviceForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_2);

        lineEdit = new QLineEdit(DeviceForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(DeviceForm);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);

        spinBox = new QSpinBox(DeviceForm);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setFrame(true);
        spinBox->setMaximum(1000);

        horizontalLayout_12->addWidget(spinBox);

        checkBox = new QCheckBox(DeviceForm);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_12->addWidget(checkBox);


        verticalLayout_3->addLayout(horizontalLayout_12);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        pushButton = new QPushButton(DeviceForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(40, 16777215));
        pushButton->setSizeIncrement(QSize(0, 0));

        horizontalLayout_3->addWidget(pushButton);

        CustomerCombo = new QComboBox(DeviceForm);
        CustomerCombo->setObjectName(QString::fromUtf8("CustomerCombo"));
        sizePolicy2.setHeightForWidth(CustomerCombo->sizePolicy().hasHeightForWidth());
        CustomerCombo->setSizePolicy(sizePolicy2);
        CustomerCombo->setEditable(true);

        horizontalLayout_3->addWidget(CustomerCombo);

        label_3 = new QLabel(DeviceForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_7);

        dateEdit = new QDateEdit(DeviceForm);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        sizePolicy2.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_17->addWidget(dateEdit);

        label_7 = new QLabel(DeviceForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_17->addWidget(label_7);


        verticalLayout_9->addLayout(horizontalLayout_17);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_8);

        dateEdit_2 = new QDateEdit(DeviceForm);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        sizePolicy2.setHeightForWidth(dateEdit_2->sizePolicy().hasHeightForWidth());
        dateEdit_2->setSizePolicy(sizePolicy2);

        horizontalLayout_16->addWidget(dateEdit_2);

        label_8 = new QLabel(DeviceForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_16->addWidget(label_8);


        verticalLayout_9->addLayout(horizontalLayout_16);


        verticalLayout_3->addLayout(verticalLayout_9);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_6);

        label_6 = new QLabel(DeviceForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);

        horizontalLayout_14->addWidget(label_6);


        verticalLayout_5->addLayout(horizontalLayout_14);

        line = new QFrame(DeviceForm);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);


        verticalLayout_7->addLayout(verticalLayout_5);

        scrollArea = new QScrollArea(DeviceForm);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 1000));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 637, 50));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        vb = new QVBoxLayout();
        vb->setObjectName(QString::fromUtf8("vb"));
        vb->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);

        verticalLayout_8->addLayout(vb);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_7->addWidget(scrollArea);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(verticalSpacer);

        pushButton_3 = new QPushButton(DeviceForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_11->addWidget(pushButton_3);

        AddItemBtn = new QPushButton(DeviceForm);
        AddItemBtn->setObjectName(QString::fromUtf8("AddItemBtn"));
        sizePolicy1.setHeightForWidth(AddItemBtn->sizePolicy().hasHeightForWidth());
        AddItemBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(AddItemBtn);


        verticalLayout_7->addLayout(horizontalLayout_11);

        line_2 = new QFrame(DeviceForm);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_2);


        verticalLayout->addLayout(verticalLayout_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        cbg = new QGridLayout();
        cbg->setObjectName(QString::fromUtf8("cbg"));
        cbg->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);

        horizontalLayout_8->addLayout(cbg);

        label_4 = new QLabel(DeviceForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_8->addWidget(label_4);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        textEdit = new QTextEdit(DeviceForm);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy4.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy4);
        textEdit->setTabChangesFocus(true);

        horizontalLayout_2->addWidget(textEdit);

        label_2 = new QLabel(DeviceForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

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
        QWidget::setTabOrder(CustomerCombo, pushButton);
        QWidget::setTabOrder(pushButton, textEdit);
        QWidget::setTabOrder(textEdit, SubmitBtn);
        QWidget::setTabOrder(SubmitBtn, pushButton_2);
        QWidget::setTabOrder(pushButton_2, AddItemBtn);

        retranslateUi(DeviceForm);

        QMetaObject::connectSlotsByName(DeviceForm);
    } // setupUi

    void retranslateUi(QWidget *DeviceForm)
    {
        DeviceForm->setWindowTitle(QCoreApplication::translate("DeviceForm", "\330\257\330\263\330\252\332\257\330\247\331\207 \331\207\330\247", nullptr));
        label_5->setText(QCoreApplication::translate("DeviceForm", "\331\206\330\247\331\205 \330\257\330\263\330\252\332\257\330\247\331\207 :", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DeviceForm", "...", nullptr));
        label->setText(QCoreApplication::translate("DeviceForm", "\330\264\331\205\330\247\330\261\331\207 \330\263\330\261\333\214\330\247\331\204 :", nullptr));
        checkBox->setText(QCoreApplication::translate("DeviceForm", "\330\247\331\201\330\262\331\210\330\257\331\206 \330\254\331\205\330\271\333\214", nullptr));
        pushButton->setText(QCoreApplication::translate("DeviceForm", "+", nullptr));
        label_3->setText(QCoreApplication::translate("DeviceForm", "\331\206\330\247\331\205 \330\256\330\261\333\214\330\257\330\247\330\261 :", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("DeviceForm", "yyyy/M/d", nullptr));
        label_7->setText(QCoreApplication::translate("DeviceForm", "\330\252\330\247\330\261\333\214\330\256 \330\256\330\261\333\214\330\257 :", nullptr));
        dateEdit_2->setDisplayFormat(QCoreApplication::translate("DeviceForm", "yyyy/M/d", nullptr));
        label_8->setText(QCoreApplication::translate("DeviceForm", "\330\252\330\247\330\261\333\214\330\256 \330\247\331\206\331\202\330\266\330\247\333\214 \332\257\330\247\330\261\330\247\331\206\330\252\333\214 :", nullptr));
        label_6->setText(QCoreApplication::translate("DeviceForm", "\331\202\330\267\330\271\330\247\330\252 :", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DeviceForm", "\331\210\333\214\330\261\330\247\333\214\330\264 \331\202\330\267\330\271\331\207", nullptr));
        AddItemBtn->setText(QCoreApplication::translate("DeviceForm", "\330\247\331\201\330\262\331\210\330\257\331\206 \331\202\330\267\330\271\331\207", nullptr));
        label_4->setText(QCoreApplication::translate("DeviceForm", "\331\205\330\252\330\271\331\204\331\202\330\247\330\252 :", nullptr));
        label_2->setText(QCoreApplication::translate("DeviceForm", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252 :", nullptr));
        SubmitBtn->setText(QCoreApplication::translate("DeviceForm", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceForm: public Ui_DeviceForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEFORM_H
