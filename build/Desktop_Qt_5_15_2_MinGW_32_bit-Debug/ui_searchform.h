/********************************************************************************
** Form generated from reading UI file 'searchform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFORM_H
#define UI_SEARCHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QComboBox *comboBox_4;
    QLabel *label_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *SearchForm)
    {
        if (SearchForm->objectName().isEmpty())
            SearchForm->setObjectName(QString::fromUtf8("SearchForm"));
        SearchForm->resize(400, 300);
        SearchForm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout_3 = new QVBoxLayout(SearchForm);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox = new QComboBox(SearchForm);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_5->addWidget(comboBox);

        label = new QLabel(SearchForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(SearchForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);

        comboBox_4 = new QComboBox(SearchForm);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        horizontalLayout->addWidget(comboBox_4);

        label_2 = new QLabel(SearchForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        widget = new QWidget(SearchForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_3->addWidget(comboBox_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBox_3 = new QComboBox(widget);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout_4->addWidget(comboBox_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label_4);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(widget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        buttonBox = new QDialogButtonBox(SearchForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        horizontalLayout_2->addWidget(buttonBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(comboBox, lineEdit);

        retranslateUi(SearchForm);

        QMetaObject::connectSlotsByName(SearchForm);
    } // setupUi

    void retranslateUi(QWidget *SearchForm)
    {
        SearchForm->setWindowTitle(QCoreApplication::translate("SearchForm", "\330\254\330\263\330\252\330\254\331\210", nullptr));
        label->setText(QCoreApplication::translate("SearchForm", "\330\254\330\263\330\252\330\254\331\210 \330\257\330\261 :", nullptr));
        label_2->setText(QCoreApplication::translate("SearchForm", "\331\205\330\252\331\206 \330\254\330\263\330\252\330\254\331\210 :", nullptr));
        label_3->setText(QCoreApplication::translate("SearchForm", "\331\206\331\210\330\271 \331\202\330\267\330\271\331\207 :", nullptr));
        label_4->setText(QCoreApplication::translate("SearchForm", "\331\206\330\247\331\205 \331\202\330\267\330\271\331\207 :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchForm: public Ui_SearchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORM_H
