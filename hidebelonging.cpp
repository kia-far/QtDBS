#include "hidebelonging.h"
#include "ui_hidebelonging.h"
#include "itemhandler.h"
#include <QListWidget>

HideBelonging::HideBelonging(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HideBelonging)
{
    ui->setupUi(this);
}

HideBelonging::~HideBelonging()
{
    delete ui;
}

void HideBelonging::setup(QString device){
    ui->listWidget->clear();
    this->device=device;
    this->show();
    this->activateWindow();

    QStringList visibleBelongings = ItemHandler::loadVisibleBelongings(device);
    QStringList belongings = ItemHandler::loadbelongings(device);
    for (const QString& itemText : belongings) {
        QListWidgetItem* item = new QListWidgetItem(itemText, ui->listWidget);

        // Enable checkbox for the item
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);

        // Set the checkbox to unchecked initially
        if(visibleBelongings.contains(itemText)){
            item->setCheckState(Qt::Unchecked);}
        else{item->setCheckState(Qt::Checked);}

        // Add item to the QListWidget
        ui->listWidget->addItem(item);
    }
}

void HideBelonging::submitChanges(QString device) {
    // Get initial visible belongings
    QStringList visibleBelongings = ItemHandler::loadVisibleBelongings(device);

    // Loop through all items in the QListWidget
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem* item = ui->listWidget->item(i);
        QString itemText = item->text();
        bool isInitiallyVisible = visibleBelongings.contains(itemText);
        bool isCurrentlyChecked = (item->checkState() == Qt::Checked);

        // Determine if a change occurred
        if (isInitiallyVisible && isCurrentlyChecked) {
            // Item was visible, now unchecked (hide it)
            ItemHandler::changeBelVisibility(device, itemText);
        } else if (!isInitiallyVisible && !isCurrentlyChecked) {
            // Item was hidden, now checked (show it)
            ItemHandler::changeBelVisibility(device, itemText);
        }
    }
}

void HideBelonging::on_pushButton_clicked()
{
    submitChanges(device);
    emit refreshDevPage(device);
    this->close();
}

void HideBelonging::closePage(){
    this->close();
}
