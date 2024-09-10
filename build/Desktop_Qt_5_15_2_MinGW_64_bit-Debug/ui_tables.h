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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tables
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *EditBtn;
    QPushButton *AddBtn;
    QPushButton *RefreshBtn;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox;
    QTableView *tableView;
    QPushButton *mainWindowBtn;
    QPushButton *SearchBtn;
    QComboBox *comboBox_2;

    void setupUi(QWidget *Tables)
    {
        if (Tables->objectName().isEmpty())
            Tables->setObjectName(QString::fromUtf8("Tables"));
        Tables->resize(802, 525);
        gridLayout = new QGridLayout(Tables);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        EditBtn = new QPushButton(Tables);
        EditBtn->setObjectName(QString::fromUtf8("EditBtn"));

        gridLayout->addWidget(EditBtn, 0, 8, 1, 1);

        AddBtn = new QPushButton(Tables);
        AddBtn->setObjectName(QString::fromUtf8("AddBtn"));

        gridLayout->addWidget(AddBtn, 0, 6, 1, 1);

        RefreshBtn = new QPushButton(Tables);
        RefreshBtn->setObjectName(QString::fromUtf8("RefreshBtn"));

        gridLayout->addWidget(RefreshBtn, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

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

        tableView = new QTableView(Tables);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setEditTriggers(QAbstractItemView::EditKeyPressed);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout->addWidget(tableView, 2, 0, 1, 9);

        mainWindowBtn = new QPushButton(Tables);
        mainWindowBtn->setObjectName(QString::fromUtf8("mainWindowBtn"));

        gridLayout->addWidget(mainWindowBtn, 0, 3, 1, 1);

        SearchBtn = new QPushButton(Tables);
        SearchBtn->setObjectName(QString::fromUtf8("SearchBtn"));

        gridLayout->addWidget(SearchBtn, 0, 7, 1, 1);

        comboBox_2 = new QComboBox(Tables);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 0, 1, 1, 1);


        retranslateUi(Tables);

        QMetaObject::connectSlotsByName(Tables);
    } // setupUi

    void retranslateUi(QWidget *Tables)
    {
        Tables->setWindowTitle(QCoreApplication::translate("Tables", "Form", nullptr));
        EditBtn->setText(QCoreApplication::translate("Tables", "\331\210\333\214\330\261\330\247\333\214\330\264", nullptr));
        AddBtn->setText(QCoreApplication::translate("Tables", "\330\247\331\201\330\262\331\210\330\257\331\206", nullptr));
        RefreshBtn->setText(QCoreApplication::translate("Tables", "\330\250\330\247\330\262\330\256\331\210\330\247\331\206\333\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Tables", "\331\205\330\264\330\252\330\261\333\214\330\247\331\206", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Tables", "\330\256\330\257\331\205\330\247\330\252", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Tables", "\330\257\330\263\330\252\332\257\330\247\331\207 \331\207\330\247", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Tables", "\331\205\330\255\330\265\331\210\331\204\330\247\330\252", nullptr));

        mainWindowBtn->setText(QCoreApplication::translate("Tables", "\330\265\331\201\330\255\331\207 \330\247\330\265\331\204\333\214", nullptr));
        SearchBtn->setText(QCoreApplication::translate("Tables", "\330\254\330\263\330\252\330\254\331\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tables: public Ui_Tables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLES_H
