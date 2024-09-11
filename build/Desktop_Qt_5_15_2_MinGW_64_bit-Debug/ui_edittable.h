/********************************************************************************
** Form generated from reading UI file 'edittable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTABLE_H
#define UI_EDITTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditTable
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *pushButton;
    QDateEdit *dateEdit;

    void setupUi(QWidget *EditTable)
    {
        if (EditTable->objectName().isEmpty())
            EditTable->setObjectName(QString::fromUtf8("EditTable"));
        EditTable->resize(867, 444);
        EditTable->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        layoutWidget = new QWidget(EditTable);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 821, 367));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(819, 0));

        verticalLayout->addWidget(tableView);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        dateEdit = new QDateEdit(EditTable);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(190, 10, 110, 22));

        retranslateUi(EditTable);

        QMetaObject::connectSlotsByName(EditTable);
    } // setupUi

    void retranslateUi(QWidget *EditTable)
    {
        EditTable->setWindowTitle(QCoreApplication::translate("EditTable", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("EditTable", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditTable: public Ui_EditTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTABLE_H
