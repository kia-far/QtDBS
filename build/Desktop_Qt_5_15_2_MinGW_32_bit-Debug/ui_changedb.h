/********************************************************************************
** Form generated from reading UI file 'changedb.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEDB_H
#define UI_CHANGEDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeDB
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChangeDB)
    {
        if (ChangeDB->objectName().isEmpty())
            ChangeDB->setObjectName(QString::fromUtf8("ChangeDB"));
        ChangeDB->resize(387, 275);
        widget = new QWidget(ChangeDB);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 12, 360, 243));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Orientation::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(ChangeDB);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeDB, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangeDB, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangeDB);
    } // setupUi

    void retranslateUi(QDialog *ChangeDB)
    {
        ChangeDB->setWindowTitle(QCoreApplication::translate("ChangeDB", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeDB: public Ui_ChangeDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEDB_H
