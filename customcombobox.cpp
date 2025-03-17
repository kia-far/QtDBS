#include "customcombobox.h"
#include <QStringListModel>
#include <QCompleter>
#include <QAbstractItemView>
#include <QDebug>
#include <QListView>
#include <QComboBox>


CustomComboBox::CustomComboBox(QWidget *parent)
    : QComboBox(parent), completer(new QCompleter(this)) {
    this->setEditable(true);
    this->setMaxVisibleItems(10);

    // Force the view to respect the max visible items setting
    QListView* listView = new QListView(this);
    this->setView(listView);

    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setFilterMode(Qt::MatchContains);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->popup()->setStyleSheet("font-size: 20px");
    this->setCompleter(completer);
}

void CustomComboBox::setCompleterData(const QStringList &items) {
    completerData = items;
    completer->setModel(new QStringListModel(items, this));

    // Set items without showing all of them in the dropdown
    this->blockSignals(true);  // Prevent unwanted signals during setup
    this->clear();
    this->addItems(items);
    this->setCurrentText("");
    this->blockSignals(false);
}

void CustomComboBox::showPopup() {
    QString text = this->currentText();

    if (text.isEmpty()) {
        this->clear();
        this->addItems(completerData);
    }

    // Force a fixed height for 10 rows
    QAbstractItemView* view = this->view();
    int rowHeight = view->visualRect(view->model()->index(0, 0)).height();
    if (rowHeight > 0) {
        view->setMaximumHeight(rowHeight * 10 + view->frameWidth() * 2);
    } else {
        // Fallback if we can't get row height
        view->setMaximumHeight(250); // Approximate height for 10 rows
    }

    QComboBox::showPopup();
    this->setCurrentText(text);
}
