#include "deviceform.h"
#include "ui_deviceform.h"
#include "itemhandler.h"
#include "myfunctions.h"
#include <QBoxLayout>
#include <QDebug>

DeviceForm::DeviceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceForm),
    db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);
    setup();
}
int indexcounter = 0;
DeviceForm::~DeviceForm()
{
    delete ui;
}

void DeviceForm::setup(){
    QStringList devices = ItemHandler::loadDevices();
    for(int i=0;i<devices.length();i++){
    ui->comboBox->addItem(devices[i]);}
}

void DeviceForm::refresh(){
    clearLayout(ui->vb);
    labels.clear();
    comboBoxes.clear();
    addBtns.clear();
    QStringList currentItems = ItemHandler::loadItems(currentDevice);
    for (int i=0;i<currentItems.size() ;i++ ) {
        createNewItem(currentItems[i] , i);
    }
}
void DeviceForm::on_comboBox_currentIndexChanged(const QString &arg1)
{
    clearLayout(ui->vb);
    clearLayout(ui->cbg);
    labels.clear();
    comboBoxes.clear();
    addBtns.clear();
    checkBoxes.clear();
    currentDevice = arg1;
    QStringList currentItems = ItemHandler::loadItems(arg1);
    for (int i=0;i<currentItems.size() ;i++ ) {
        createNewItem(currentItems[i] , i);
    }
    QStringList belongings = ItemHandler::loadbelongings(arg1);
    for (int i=0;i<belongings.size();i++){
        createBelonging(belongings[i],i);
    }
    qDebug () <<  currentDevice;
}
void DeviceForm::createBelonging(QString itemName,int index){
    QCheckBox *checkBox = new QCheckBox(itemName);
    QString checkBoxName = QString("check_%1").arg(index);
    checkBox->setObjectName(checkBoxName);
    checkBox->setMinimumHeight(25);
//    checkBox->setText(itemName);
    checkBoxes.append(checkBox);
    ui->cbg->addWidget(checkBox,index/2,index%2);
    ui->cbg->setRowMinimumHeight(index/2,30);
}

void DeviceForm::createNewItem(QString itemName, int index) {
    adder =0;
    indexcounter += 1;
    QLabel *label = new QLabel(itemName);
    QString labelName = QString("label_%1").arg(index+10*indexcounter);
    label->setObjectName(labelName);
    labels.append(label);
    QComboBox *comboBox = new QComboBox();
    QString comboBoxName = QString("comboBox_%1").arg(index+10*indexcounter);
    comboBox->insertItems(0,setupOptions(itemName));
    comboBox->setObjectName(comboBoxName);
    comboBoxes.append(comboBox);
    QPushButton *addBtn = new QPushButton();
    QString buttonName = QString("addBtn_%1").arg(index+10*indexcounter);
    addBtn->setObjectName(buttonName);
    addBtn->setText("Add");
    connect(addBtn, &QPushButton::clicked, this, [this, itemName]() {
        addOption(currentDevice,itemName);
    });
    addBtns.append(addBtn);
    QString hbName = QString("hb_%1").arg(index);
    QHBoxLayout *hb = new QHBoxLayout;
    //size constraints:
    label->setAlignment(Qt::AlignRight);
    addBtn->setMaximumWidth(40);
    addBtn->setMinimumHeight(25);
    comboBox->setMinimumHeight(25);
    label->setMinimumHeight(25);
    //----
    hb->addWidget(addBtn);
    hb->addWidget(comboBox);
    hb->addWidget(label);
    ui->vb->addLayout(hb);
    hb->setObjectName(hbName);
}

QStringList DeviceForm::setupOptions(QString itemName){
    return ItemHandler::loadOptions(currentDevice,itemName);
}

void DeviceForm::clearLayout(QLayout *layout) {

    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        //delete item;
    }
}

void DeviceForm::on_SubmitBtn_clicked()
{

    QString newText="";
    QStringList columns={"SerialNumber", "CustomerName" ,"description","belongings"};
//description TEXT, belongings TEXT
    for (QLabel *label : labels) {
        QString text = label->text(); // Get the text from the QLineEdit
        qDebug() << "column" << label->objectName() << ":" << text;
        for(int i=0;i<text.size(); i++){
            if (text.at(i)==" "){newText.append("_");}
            else{newText.append(text.at(i));}
        }
        columns.append(text);
    }
    QString checks = "";
    for (QCheckBox *checkBox : checkBoxes){
        if(checkBox->isChecked()){
        checks.append(checkBox->text()+" ");}
    }
    QVariantList givenData = {MyFunctions::reverseSN( ui->lineEdit->text()).toInt(),ui->CustomerCombo->currentText(),ui->textEdit->toPlainText(), checks};
    for (QComboBox *comboBox : comboBoxes) {
        QString text = comboBox->currentText();
        qDebug() << "Data" << comboBox->objectName() << ":" << text;
        givenData.append(text);
    }
    ItemHandler::insertDataIntoTable(currentDevice,columns,givenData);

}

void DeviceForm::addOption(QString deviceName,QString itemName){
    qDebug() << "option possibly added : " << itemName;
    emit optionPage(deviceName,itemName);
}
void DeviceForm::addItem(QString deviceName){
    emit itemPage(deviceName);
}
void DeviceForm::addDevice(){
    emit devicePage();
}
void DeviceForm::on_AddItemBtn_clicked()
{
    addItem(currentDevice);
}


void DeviceForm::on_addDeviceBtn_clicked()
{
    addDevice();
}

QStringList DeviceForm::getCustomers(QString halfText) {
    QSqlQuery query(db.getConnection());

    QStringList res;

    query.prepare("SELECT Name FROM CustomerInfo WHERE Name LIKE :halfText LIMIT 5");
    query.bindValue(":halfText", "%" + halfText + "%");  // Use wildcards for partial match

    // Execute the query
    if (query.exec()) {
        qDebug() << "Fetch the results";
        while (query.next()) {
            res << query.value(0).toString();  // Assuming 'name' is the first column
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    return res;
}

void DeviceForm::on_CustomerCombo_editTextChanged(const QString &arg1) {
    // Block signals to prevent recursion
    ui->CustomerCombo->blockSignals(true);

    // Clear the existing items in the combo box
    ui->CustomerCombo->clear();

    // Get the filtered customer names based on the input text
    QStringList customers = getCustomers(arg1);

    // Add the new items to the combo box
    ui->CustomerCombo->addItems(customers);

    // Optionally, set the current text back to what was entered
    ui->CustomerCombo->setCurrentText(arg1);

    // Unblock signals after updating
    ui->CustomerCombo->blockSignals(false);
}



void DeviceForm::on_pushButton_clicked()
{
//    emit addCustomer();
    qDebug() << ItemHandler::loadbelongings(currentDevice);
}

