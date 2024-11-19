/********************************************************************************
** Form generated from reading UI file 'tables.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLES_H
#define UI_TABLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tables
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer;
    QPushButton *deleteBtn;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *SearchBtn;
    QPushButton *RefreshBtn;
    QPushButton *mainWindowBtn;
    QPushButton *EditBtn;
    QPushButton *AddBtn;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;
    QToolButton *toolButton;
    QComboBox *comboBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *form_Name;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *form_SN;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *form_dev;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_16;
    QLineEdit *form_gDate;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_17;
    QLineEdit *form_pDate;
    QLabel *label_7;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *form_parts;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *form_partHBox;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_5;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *form_bel;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *form_belHBox;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_9;
    QTextBrowser *form_description;

    void setupUi(QWidget *Tables)
    {
        if (Tables->objectName().isEmpty())
            Tables->setObjectName(QString::fromUtf8("Tables"));
        Tables->resize(972, 853);
        Tables->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"QPushButton:disabled {\n"
"    background-color: #d3d3d3; /* Grayer color for disabled buttons */\n"
"    color: #a0a0a0; /* Optional:"
                        " lighter text color for better contrast */\n"
"}\n"
"QToolButton {\n"
"    background-color: rgb(228, 229, 244); /* Light gray background */\n"
"    border: 1px solid #a9a9a9; /* Darker gray border for a 3D effect */\n"
"    border-radius: 6px; /* Rounded corners */\n"
"     /* Padding for a button-like appearance */\n"
"    color: black; /* Text color */\n"
"    \n"
"    /* Subtle gradient for a shiny effect */\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 #f0f0f0, stop:1 #d3d3d3);\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #e6e6e6; /* Change to a lighter shade on hover */\n"
"    border-color: #b0b0b0; /* Change border color on hover */\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"    background-color: #bfbfbf; /* Darker gray when pressed */\n"
"    border-color: #808080; /* Slightly darker border when pressed */\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"    background-color: #d3d3d3; /* Grayer color for disabled buttons */\n"
""
                        "    color: #a0a0a0; /* Optional: lighter text color for better contrast */\n"
"}\n"
"\n"
"\n"
"QWidget {font: 11pt \"Segoe UI\";}\n"
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
"#Tables {\n"
"    background-color: #d0dae1; /* Dark background color for the entire widget */\n"
"    font: 11pt \"Segoe UI\";}\n"
"QScrollBar:vertical {\n"
"    background: #eff3f5; /* Background color of the scrollbar */\n"
"    width: 10px; /* Width of the scrollbar */\n"
"    margin: 0px 0px 0px 0px; /* Margins around the scrollbar "
                        "*/\n"
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
"QScrollBar::handle:vertical:hover, QScrollBar::handle:horizontal:hover {\n"
"    background: #b1c1cd; /* Slightly lighter color on hover for the handle */\n"
"}\n"
""
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
"}"));
        gridLayout = new QGridLayout(Tables);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(Tables);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(0, 200));
        tableView->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        tableView->setFrameShadow(QFrame::Shadow::Sunken);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        tableView->setEditTriggers(QAbstractItemView::EditTrigger::EditKeyPressed);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableView->setTextElideMode(Qt::TextElideMode::ElideRight);
        tableView->setSortingEnabled(true);
        tableView->setWordWrap(true);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        gridLayout->addWidget(tableView, 4, 0, 1, 11);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        deleteBtn = new QPushButton(Tables);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));

        gridLayout->addWidget(deleteBtn, 0, 9, 1, 1);

        comboBox_2 = new QComboBox(Tables);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        SearchBtn = new QPushButton(Tables);
        SearchBtn->setObjectName(QString::fromUtf8("SearchBtn"));

        gridLayout->addWidget(SearchBtn, 0, 7, 1, 1);

        RefreshBtn = new QPushButton(Tables);
        RefreshBtn->setObjectName(QString::fromUtf8("RefreshBtn"));

        gridLayout->addWidget(RefreshBtn, 0, 5, 1, 1);

        mainWindowBtn = new QPushButton(Tables);
        mainWindowBtn->setObjectName(QString::fromUtf8("mainWindowBtn"));

        gridLayout->addWidget(mainWindowBtn, 0, 3, 1, 1);

        EditBtn = new QPushButton(Tables);
        EditBtn->setObjectName(QString::fromUtf8("EditBtn"));

        gridLayout->addWidget(EditBtn, 0, 8, 1, 1);

        AddBtn = new QPushButton(Tables);
        AddBtn->setObjectName(QString::fromUtf8("AddBtn"));

        gridLayout->addWidget(AddBtn, 0, 6, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Tables);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(Tables);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(1000);
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 11);

        toolButton = new QToolButton(Tables);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        gridLayout->addWidget(toolButton, 0, 10, 1, 1);

        comboBox = new QComboBox(Tables);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setBaseSize(QSize(0, 0));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        widget = new QWidget(Tables);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #d0dae1; /* Dark background color for the entire widget */\n"
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
"    border-radius: 6px; "
                        "/* Smooth, rounded edges */\n"
"    padding: 5px; /* Padding for a cleaner look */\n"
"    font: 11pt \"Segoe UI\";\n"
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
""
                        "/* Style for the vertical scrollbar */\n"
"QScrollBar:vertical {\n"
"    background: #eff3f5; /* Background color of the scrollbar */\n"
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
""
                        "    border-radius: 5px; /* Smooth, rounded edges for the handle */\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover, QScrollBar::handle:horizontal:hover {\n"
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
""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        form_Name = new QLineEdit(widget);
        form_Name->setObjectName(QString::fromUtf8("form_Name"));
        form_Name->setReadOnly(true);

        horizontalLayout_3->addWidget(form_Name);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        form_SN = new QLineEdit(widget);
        form_SN->setObjectName(QString::fromUtf8("form_SN"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(form_SN->sizePolicy().hasHeightForWidth());
        form_SN->setSizePolicy(sizePolicy3);
        form_SN->setReadOnly(true);

        horizontalLayout->addWidget(form_SN);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label_2);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        form_dev = new QLineEdit(widget);
        form_dev->setObjectName(QString::fromUtf8("form_dev"));
        form_dev->setReadOnly(true);

        horizontalLayout_7->addWidget(form_dev);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);


        horizontalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        form_gDate = new QLineEdit(widget);
        form_gDate->setObjectName(QString::fromUtf8("form_gDate"));
        form_gDate->setReadOnly(true);

        horizontalLayout_16->addWidget(form_gDate);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_16->addWidget(label_8);


        horizontalLayout_6->addLayout(horizontalLayout_16);

        horizontalSpacer_4 = new QSpacerItem(184, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        form_pDate = new QLineEdit(widget);
        form_pDate->setObjectName(QString::fromUtf8("form_pDate"));
        form_pDate->setReadOnly(true);

        horizontalLayout_17->addWidget(form_pDate);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_17->addWidget(label_7);


        horizontalLayout_6->addLayout(horizontalLayout_17);


        verticalLayout_3->addLayout(horizontalLayout_6);

        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy4);
        scrollArea->setMinimumSize(QSize(0, 125));
        scrollArea->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 926, 123));
        horizontalLayout_8 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        form_parts = new QGroupBox(scrollAreaWidgetContents);
        form_parts->setObjectName(QString::fromUtf8("form_parts"));
        sizePolicy.setHeightForWidth(form_parts->sizePolicy().hasHeightForWidth());
        form_parts->setSizePolicy(sizePolicy);
        form_parts->setMinimumSize(QSize(0, 0));
        form_parts->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        form_parts->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        horizontalLayout_2 = new QHBoxLayout(form_parts);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        form_partHBox = new QHBoxLayout();
        form_partHBox->setObjectName(QString::fromUtf8("form_partHBox"));
        form_partHBox->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);

        horizontalLayout_2->addLayout(form_partHBox);


        horizontalLayout_8->addWidget(form_parts);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(widget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(0, 100));
        scrollArea_2->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        scrollArea_2->setWidgetResizable(true);
        scrollArea_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 926, 98));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        form_bel = new QGroupBox(scrollAreaWidgetContents_5);
        form_bel->setObjectName(QString::fromUtf8("form_bel"));
        sizePolicy.setHeightForWidth(form_bel->sizePolicy().hasHeightForWidth());
        form_bel->setSizePolicy(sizePolicy);
        form_bel->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        form_bel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        horizontalLayout_4 = new QHBoxLayout(form_bel);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        form_belHBox = new QHBoxLayout();
        form_belHBox->setObjectName(QString::fromUtf8("form_belHBox"));

        horizontalLayout_4->addLayout(form_belHBox);


        verticalLayout_2->addWidget(form_bel);

        scrollArea_2->setWidget(scrollAreaWidgetContents_5);

        verticalLayout_3->addWidget(scrollArea_2);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        horizontalLayout_9 = new QHBoxLayout(groupBox);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        form_description = new QTextBrowser(groupBox);
        form_description->setObjectName(QString::fromUtf8("form_description"));
        form_description->setMinimumSize(QSize(0, 100));
        form_description->setMaximumSize(QSize(16777215, 100));
        form_description->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_9->addWidget(form_description);


        verticalLayout_3->addWidget(groupBox);


        gridLayout->addWidget(widget, 6, 0, 1, 11);

        QWidget::setTabOrder(comboBox, comboBox_2);
        QWidget::setTabOrder(comboBox_2, mainWindowBtn);
        QWidget::setTabOrder(mainWindowBtn, RefreshBtn);
        QWidget::setTabOrder(RefreshBtn, AddBtn);
        QWidget::setTabOrder(AddBtn, SearchBtn);
        QWidget::setTabOrder(SearchBtn, EditBtn);
        QWidget::setTabOrder(EditBtn, deleteBtn);
        QWidget::setTabOrder(deleteBtn, tableView);

        retranslateUi(Tables);

        QMetaObject::connectSlotsByName(Tables);
    } // setupUi

    void retranslateUi(QWidget *Tables)
    {
        Tables->setWindowTitle(QCoreApplication::translate("Tables", "\330\254\330\257\331\210\331\204", nullptr));
        deleteBtn->setText(QCoreApplication::translate("Tables", "\330\255\330\260\331\201", nullptr));
        SearchBtn->setText(QCoreApplication::translate("Tables", "\330\254\330\263\330\252\330\254\331\210", nullptr));
        RefreshBtn->setText(QCoreApplication::translate("Tables", "\330\250\330\247\330\262\330\256\331\210\330\247\331\206\333\214", nullptr));
        mainWindowBtn->setText(QCoreApplication::translate("Tables", "\330\265\331\201\330\255\331\207 \330\247\330\265\331\204\333\214", nullptr));
        EditBtn->setText(QCoreApplication::translate("Tables", "\331\210\333\214\330\261\330\247\333\214\330\264", nullptr));
        AddBtn->setText(QCoreApplication::translate("Tables", "\330\247\331\201\330\262\331\210\330\257\331\206", nullptr));
        label->setText(QCoreApplication::translate("Tables", "\330\257\330\261 \330\255\330\247\331\204 \330\247\330\266\330\247\331\201\331\207 \332\251\330\261\330\257\331\206 \330\257\330\263\330\252\332\257\330\247\331\207 \331\207\330\247. \331\204\330\267\331\201\330\247 \331\205\331\206\330\252\330\270\330\261 \330\250\331\205\330\247\331\206\333\214\330\257.", nullptr));
#if QT_CONFIG(tooltip)
        toolButton->setToolTip(QCoreApplication::translate("Tables", "<html><head/><body><p>\330\256\330\261\331\210\330\254\333\214 \330\247\332\251\330\263\331\204</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton->setText(QCoreApplication::translate("Tables", "...", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Tables", "\331\205\330\264\330\252\330\261\333\214\330\247\331\206", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Tables", "\330\256\330\257\331\205\330\247\330\252", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Tables", "\330\257\330\263\330\252\332\257\330\247\331\207 \331\207\330\247", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Tables", "\331\205\330\255\330\265\331\210\331\204\330\247\330\252", nullptr));

        label_3->setText(QCoreApplication::translate("Tables", "\331\206\330\247\331\205 \330\256\330\261\333\214\330\257\330\247\330\261 :", nullptr));
        label_2->setText(QCoreApplication::translate("Tables", "\330\264\331\205\330\247\330\261\331\207 \330\263\330\261\333\214\330\247\331\204 :", nullptr));
        label_5->setText(QCoreApplication::translate("Tables", "\331\206\330\247\331\205 \330\257\330\263\330\252\332\257\330\247\331\207 :", nullptr));
        label_8->setText(QCoreApplication::translate("Tables", "\330\252\330\247\330\261\333\214\330\256 \330\247\331\206\331\202\330\266\330\247\333\214 \332\257\330\247\330\261\330\247\331\206\330\252\333\214 :", nullptr));
        label_7->setText(QCoreApplication::translate("Tables", "\330\252\330\247\330\261\333\214\330\256 \330\256\330\261\333\214\330\257 :", nullptr));
        form_parts->setTitle(QCoreApplication::translate("Tables", "\331\202\330\267\330\271\330\247\330\252", nullptr));
        form_bel->setTitle(QCoreApplication::translate("Tables", "\331\205\330\252\330\271\331\204\331\202\330\247\330\252", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Tables", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tables: public Ui_Tables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLES_H
