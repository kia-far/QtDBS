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
#include <QtWidgets/QGridLayout>
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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *SearchForm)
    {
        if (SearchForm->objectName().isEmpty())
            SearchForm->setObjectName(QString::fromUtf8("SearchForm"));
        SearchForm->resize(400, 300);
        SearchForm->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        verticalLayout = new QVBoxLayout(SearchForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(SearchForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        label = new QLabel(SearchForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        lineEdit = new QLineEdit(SearchForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit, 2, 0, 1, 1);

        comboBox = new QComboBox(SearchForm);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

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


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SearchForm);

        QMetaObject::connectSlotsByName(SearchForm);
    } // setupUi

    void retranslateUi(QWidget *SearchForm)
    {
        SearchForm->setWindowTitle(QCoreApplication::translate("SearchForm", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("SearchForm", "\331\205\330\252\331\206 \330\254\330\263\330\252\330\254\331\210 :", nullptr));
        label->setText(QCoreApplication::translate("SearchForm", "\330\254\330\263\330\252\331\210\330\254\331\210 \330\257\330\261 :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchForm: public Ui_SearchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORM_H
