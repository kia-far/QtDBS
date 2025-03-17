#include "deviceform.h"
#include "ui_deviceform.h"
#include "itemhandler.h"
#include "myfunctions.h"
#include <QShortcut>
#include <QKeyEvent>
#include <QBoxLayout>
#include <QDebug>
#include <QAction>
#include "QSqlRecord"
#include <QMessageBox>
#include <QCloseEvent>
#include <QCompleter>
#include <QAbstractItemView>
#include "logger.h"
#include <QKeyEvent>
#include <QtConcurrent/QtConcurrentRun>
#include <QtConcurrent/QtConcurrent>
#include <QVariant>
#include "MyTableProxy.h"
#include <printqr.h>
#include "customcombobox.h"


DeviceForm::DeviceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceForm),
    db(DatabaseConnection::getInstance())
{
    // progressBar;
    ui->setupUi(this);
    ui->CustomerCombo->setHidden(true);
    customCombo = new CustomComboBox(this);
    ui->horizontalLayout_3->insertWidget(1,customCombo);
    customCombo->setEditable(true);

    ui->spinBox->setMinimumSize(50,25);
    ui->spinBox->setValue(1);
    ui->spinBox->setDisabled(true);
    admiMode=false;
    checked = true;

    if(!admiMode){ui->pushButton_4->hide(); ui->pushButton_3->hide();ui->AddItemBtn->hide();ui->pushButton_2->hide();ui->EditQRBtn->hide(); }
//    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(this.close()));
    keyBinds();

}
int count;
int indexx;
int indexcounter = 0;
DeviceForm::~DeviceForm()
{
    delete ui;
}

void DeviceForm::trigger(QString device){

    edit= false;
    clearPage();
    admiMode = false;
    currentDevice = device;
    this->show();
    this->activateWindow();

    // qDebug() << "calling setup from trigger ";
    setup();
}

void DeviceForm::setup(){
    ui->comboBox->blockSignals(true);
    loadLastSN();
    QCalendar calendar( QCalendar::System::Jalali);
    ui->dateEdit_2->setCalendar(calendar);
    ui->dateEdit_2->setDate(QDate::currentDate().addYears(1));
    ui->dateEdit->setCalendar(calendar);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->lineEdit->setReadOnly(false);
    ui->checkBox->setDisabled(false);
    ui->checkBox->setChecked(false);
    ui->spinBox->setValue(1);
    ui->spinBox->setDisabled(true);
    getCustomers();
    if(!admiMode){ui->pushButton_4->hide();ui->pushButton_3->hide();ui->AddItemBtn->hide();ui->pushButton_2->hide();ui->EditQRBtn->hide(); }
    else {ui->pushButton_4->show();ui->pushButton_3->show();ui->AddItemBtn->show();ui->pushButton_2->show();ui->EditQRBtn->show(); }
    // edit = false;
    // admiMode = false;
    // qDebug() << "this is currentDevice:" << currentDevice;
    QString curDev = currentDevice;
    QStringList devices = ItemHandler::loadDevices();
    if(edit==false){
        ui->comboBox->clear();
        for(int i=0;i<devices.length();i++){
                ui->comboBox->addItem(devices[i]);}
    }
    ui->comboBox->setCurrentText(curDev);
    if(admiMode){

    ui->comboBox->addItem("دستگاه جدید");}
    ui->comboBox->setFixedWidth(120);
    ui->pushButton->setFixedWidth(35);
    setTabOrders();
    // qDebug() << "refresh called from setup: " << currentDevice << "is the current device";

    refresh(currentDevice);
    ui->comboBox->blockSignals(false);
}
void DeviceForm::editDevice(QString device , unsigned int id){
    ui->comboBox->blockSignals(true);

    this->show();
    this->activateWindow();

    this->id = id;
    currentDevice = device;
    // qDebug() << "ddddddddddddddddddddddd"<<currentDevice;
    // admiMode = false;
    edit= true;
    setup();
    // qDebug() <<"this is currentDevice in editDevice :"<<currentDevice;
    // ui->comboBox->blockSignals(true);
    ui->comboBox->setCurrentText(device);
    // ui->comboBox->blockSignals(false);
    ui->lineEdit->setText(MyFunctions::intToStr(id));
    // qDebug() << "pop is called from editDevice";
    populateEdit(device,id);
    // qDebug() << device<<"device after popedit called in editDevice grhuuuuuuuuuuuuuuuuuuuuuuuuuurrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr";
    ui->comboBox->blockSignals(false);
}
void DeviceForm::refresh(QString arg1){
    if(devices !=ItemHandler::loadDevices()){
        devices = ItemHandler::loadDevices();
        ui->comboBox->blockSignals(true);
        ui->comboBox->clear();
        ui->comboBox->addItems(devices);
        ui->comboBox->setCurrentText(arg1);
        ui->comboBox->blockSignals(false);
    }
    // qDebug() << "this is arg1" << arg1;
    clearLayout(ui->vb);
    clearLayout(ui->cbg);
    labels.clear();
    comboBoxes.clear();
    addBtns.clear();
    checkBoxes.clear();
    QStringList currentItems = ItemHandler::loadItems(arg1);
    for (int i=0;i<currentItems.size() ;i++ ) {
        createNewItem(currentItems[i] , i);
    }

    QStringList belongings = ItemHandler::loadVisibleBelongings(arg1);
    for (int i=0;i<belongings.size();i++){
        createBelonging(belongings[i],i);
    }
    if(admiMode){
        // QCheckBox *new
        QPushButton *newBelBtn = new QPushButton();
        QString buttonName = QString("افزودن متعلقات");
        newBelBtn->setObjectName("newBelBtn");
        newBelBtn->setText("افزودن متعلقات");
        //    newBelBtn->setFixedWidth(25);
        connect(newBelBtn, &QPushButton::clicked, this, [this ,arg1](){addBelonging (arg1);});
        indexx++;
        ui->cbg->addWidget(newBelBtn,indexx/2+indexx%2,0);
        QPushButton *hideBelBtn = new QPushButton();
        QString hideButtonName = QString("افزودن متعلقات");
        hideBelBtn->setObjectName("newBelBtn");
        hideBelBtn->setText("ویرایش متعلقات");
        //    newBelBtn->setFixedWidth(25);
        connect(hideBelBtn, &QPushButton::clicked, this, [this ,arg1](){hideBelonging (arg1);});
        // indexx++;
        ui->cbg->addWidget(hideBelBtn,indexx/2+indexx%2,1);
    }
    // qDebug()<<"this is edit: "<< edit;
    if(edit){
        // qDebug() << "this is where pop is called : refresh";
        populateEdit(arg1,id);}
}
void DeviceForm::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->comboBox->blockSignals(true);
    if(arg1=="دستگاه جدید"){
        addDevice();
        ui->comboBox->setCurrentIndex(0);
    }
    else{
        // qDebug() <<"calling refresh from combobox index changed. this is the combobox text:" <<arg1;
    currentDevice = arg1;
        refresh(arg1);

    }
    ui->comboBox->blockSignals(false);
}
void DeviceForm::createBelonging(QString itemName,int index){

    QCheckBox *checkBox = new QCheckBox(itemName);
    QString checkBoxName = QString("check_%1").arg(index);
    checkBox->setObjectName(checkBoxName);
    checkBox->setMinimumHeight(25);
//    checkBox->setText(itemName);
    checkBoxes.append(checkBox);
    ui->cbg->addWidget(checkBox,index/2,index%2);
    indexx = index;
    ui->cbg->setRowMinimumHeight(index/2,30);
}

void DeviceForm::createNewItem(QString itemName, int index) {
    adder = 0;
    indexcounter += 1;

    QLabel *label = new QLabel(itemName);
    QString labelName = QString("label_%1").arg(index + 10 * indexcounter);
    label->setObjectName(labelName);

    // Set size policy to adjust based on content
    label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    label->setAlignment(Qt::AlignCenter);
    label->adjustSize();

    labels.append(label);

    QComboBox *comboBox = new QComboBox();
    QString comboBoxName = QString("comboBox_%1").arg(index + 10 * indexcounter);
    comboBox->insertItem(0, "هیچ کدام");
    comboBox->insertItems(1, setupOptions(itemName));

    if (admiMode) {
        comboBox->insertItem(setupOptions(itemName).size() + 1, "افزودن گزینه");
        connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this, comboBox, itemName](int index) {
            if (index == setupOptions(itemName).size() + 1) {
                addOption(currentDevice, itemName);
                comboBox->setCurrentIndex(0);
            }
        });

        comboBox->insertItem(setupOptions(itemName).size() + 2, "پاک کردن گزینه");
        connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this, comboBox , itemName](int index) {
            if (index == setupOptions(itemName).size() + 2) {
                removeOption(currentDevice, itemName);
                comboBox->setCurrentIndex(0);
            }
        });
    }

    // Set size policy and adjust combo box as well
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    comboBox->adjustSize();
    comboBoxes.append(comboBox);

    QString hbName = QString("hb_%1").arg(index);
    QHBoxLayout *hb = new QHBoxLayout;
    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    // Set alignment and add widgets to layout
    label->setAlignment(Qt::AlignCenter);
    hb->addSpacerItem(spacer);
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
void DeviceForm::populateEdit(QString device,unsigned int id){
    ui->comboBox->blockSignals(true);
    // qDebug() << "device is " << device<<" in popedit";
    currentDevice = device;
    ui->lastSNLabel->setText("");
    loadDate(id);
    ui->comboBox->clear();
    ui->comboBox->addItem(device);
    ui->comboBox->blockSignals(false);
    ui->lineEdit->setReadOnly(true);
    ui->checkBox->setChecked(false);
    ui->checkBox->setDisabled(true);
    ui->spinBox->setValue(1);
    ui->spinBox->setDisabled(true);
    edit = true;
    QString newText="";
    QSqlQuery query(db.getConnection());

    QStringList res;
    // qDebug() << device <<"device pre query!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    query.prepare("SELECT * FROM " + device + " WHERE SerialNumber LIKE "+QString::number(id));
    // qDebug() << device<< id<<"in pop";
    if (query.exec()) {
        QSqlRecord record = query.record();
        int numCols = record.count();
//        qDebug() << "Fetch the results";
        while (query.next()) {
            for (int i=0;i<numCols;i++){
            res.append( query.value(i).toString());
        }}
    } else {
        // qDebug() << "Query execution failed:" << query.lastError().text();
    }
    // qDebug() << "this is res "<<res ;
    // qDebug() << "this is ID" <<id;
    customCombo->setCurrentText(res[1]);
    // qDebug() << "is this working?"<<res[1];
    ui->textEdit->setText(res[2]);
    QStringList columns={"SerialNumber", "CustomerName" ,"description","belongings"};

    QString checks = "";
    for (QCheckBox *checkBox : checkBoxes){
//        if(checkBox->isChecked()){
//        checks.append(checkBox->text()+" ");}
        if(res[3].contains(checkBox->text())){checkBox->setChecked(true);}
        else{checkBox->setChecked(false);}
    }
    int count =4;
//    QVariantList givenData = {MyFunctions::reverseSN( ui->lineEdit->text()).toInt(),customCombo->currentText(),ui->textEdit->toPlainText(), checks};
    for (QComboBox *comboBox : comboBoxes) {
//        QString text = comboBox->currentText();
//        qDebug() << "Data" << comboBox->objectName() << ":" << text;
//        givenData.append(text);
    comboBox->setCurrentText(res[count]);
// qDebug() << res[count]<<"this is res "<<count;
    count++;
    }

//    ItemHandler::insertDataIntoTable(currentDevice,columns,givenData);

}

/*
        QCalendar calendar( QCalendar::System::Jalali);
        ui->dateEdit_2->setCalendar(calendar);
        ui->dateEdit_2->setDate(QDate::currentDate());
        ui->dateEdit->setCalendar(calendar);
        ui->dateEdit->setDate(QDate::currentDate().addYears(1));
 */


void DeviceForm::on_SubmitBtn_clicked()
{
    // loadLastSN();
    // qDebug() << MyFunctions::convertToEnglishString("1400/12/9");
    // qDebug() << MyFunctions::convertToEnglishString("۱۱۱۱/۳۳/۱۱");
    // addBulk();
    if(MyFunctions::checkSN( ui->lineEdit->text())){
        if(!MyFunctions::deviceFromLetter(ui->lineEdit->text(),currentDevice)){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Error");
            msgBox.setText("شماره سریال با نوع دستگاه مطابقت ندارد"
                           "آیا مطمئنید؟");
            msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int res = msgBox.exec();
            switch(res) {
            case QMessageBox::Yes :{
                if( MyFunctions::convertToEnglishInt( ui->spinBox->text())>1){
                    if(checkBulkSN()){
                        if(MyFunctions::checkData(customCombo->currentText(),"Name","CustomerInfo")||customCombo->currentText()==""){
                            if(askForQR()){
                                if(PrintQR::checkConnection()) {count = 3;}
                                else{count = 2;
                                    QMessageBox msgBox;
                                    msgBox.setIcon(QMessageBox::Critical);
                                    msgBox.setWindowTitle("Error");
                                    msgBox.setText("پرینتل وصل نیست!");
                                    msgBox.setStandardButtons(QMessageBox::Ok);
                                    msgBox.exec();}}
                            else{count = 2;

                            }
                            QtConcurrent::run(this, &DeviceForm::addBulk);
                        }
                        else{
                            QMessageBox msgBox;
                            msgBox.setIcon(QMessageBox::Critical);
                            msgBox.setWindowTitle("Error");
                            msgBox.setText("نام مشتری نادرست است");
                            msgBox.setStandardButtons(QMessageBox::Ok);
                            msgBox.exec();
                        }
                    }

                }
                else{
                    submit(ui->lineEdit->text(),1);}
                break;
            }
            case QMessageBox::No :{
                break;
            }
            default :
                break;

            }
        }
        else{
            if(MyFunctions::convertToEnglishInt( ui->spinBox->text())>1){
                logger::log("submit pressed entering bulk!");
                if(MyFunctions::convertToEnglishInt( ui->spinBox->text())>1){
                    if(checkBulkSN()){
                        if(MyFunctions::checkData(customCombo->currentText(),"Name","CustomerInfo")||customCombo->currentText()==""){
                            if(askForQR()){
                                if(PrintQR::checkConnection()){
                                    count =3;}
                                else{
                                    count = 2;
                                    QMessageBox msgBox;
                                    msgBox.setIcon(QMessageBox::Critical);
                                    msgBox.setWindowTitle("Error");
                                    msgBox.setText("پرینتل وصل نیست!");
                                    msgBox.setStandardButtons(QMessageBox::Ok);
                                    msgBox.exec();
                                }}
                            else{count = 2;}
                            QtConcurrent::run(this, &DeviceForm::addBulk);
                        }
                        else{
                            QMessageBox msgBox;
                            msgBox.setIcon(QMessageBox::Critical);
                            msgBox.setWindowTitle("Error");
                            msgBox.setText("نام مشتری نادرست است");
                            msgBox.setStandardButtons(QMessageBox::Ok);
                            msgBox.exec();
                        }                    }
                }
            }
            else{
                logger::log("entering solo submit!");
                submit(ui->lineEdit->text(),1);}

        }
}
    else{        QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Error");
    msgBox.setText("پرینتل وصل نیست!");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();}
    }

void DeviceForm::addOption(QString deviceName,QString itemName){
//    qDebug() << "option possibly added : " << itemName;
    emit optionPage(deviceName,itemName);
}
void DeviceForm::removeOption(QString deviceName,QString itemName){
    emit removeOptionPage(deviceName,itemName);
}
void DeviceForm::addItem(QString deviceName){

    emit itemPage(deviceName);
}
void DeviceForm::addDevice(){
    emit devicePage();
}

void DeviceForm::submit(QString SN,int countt){

    SN = SN.toUpper();
    if(countt>1||(customCombo->currentText()==""||MyFunctions::checkData(customCombo->currentText(),"Name","CustomerInfo"))){
        if(countt==1){
            setChecks();
            setColumns();
            setCombos();
        }
        QVariantList givenData;
            givenData = {MyFunctions::reverseSN(SN).toUInt(),customCombo->currentText(),ui->textEdit->toPlainText(), checks};
            for(QString string: combos)
                {    givenData.append(string);}
        givenData[0] = MyFunctions::reverseSN(SN).toUInt();

    if (!edit){
        QSqlQuery q(db.getConnection());
        q.prepare("INSERT INTO ProductInfo (SerialNO , ProductName) VALUES (? ,?)");
        q.addBindValue(givenData[0].toString());
        q.addBindValue(currentDevice);

        bool er = q.exec();
        if (!er) {
            // qDebug() << "Error in ProductInfo insert:" << q.lastError().text();
        }
        //UPDATE ProductInfo SET  PurchaseDate  = ? , GuarantyExp = ? WHERE SerialNO = ?
        q.prepare("UPDATE ProductInfo SET PurchaseDate  = ? , GuarantyExp = ? WHERE SerialNO = ?");
        q.addBindValue( MyFunctions::convertToEnglishString(ui->dateEdit->text()));
        q.addBindValue(MyFunctions::convertToEnglishString(ui->dateEdit_2->text()));
        q.addBindValue(givenData[0].toString());
        // qDebug() << givenData;
        bool err = q.exec();
        if (!err) {
            // qDebug() << "Error in ProductSecInfo insert:" << q.lastError().text();
        }
        if(er&&err){
            ItemHandler::insertDataIntoTable(currentDevice,columns,givenData);
            if(countt==1){
                if(askForQR()){
                    if(PrintQR::checkConnection()){
                    QStringList QRData={SN,customCombo->currentText(),"","",MyFunctions::convertToEnglishString( ui->dateEdit->text()),MyFunctions::convertToEnglishString( ui->dateEdit_2->text())};
                    PrintQR::printQRCode(QRData,currentDevice);
                    }
                    else{
                        QMessageBox msgBox;
                        msgBox.setIcon(QMessageBox::Critical);
                        msgBox.setWindowTitle("Error");
                        msgBox.setText("پرینتل وصل نیست!");
                        msgBox.setStandardButtons(QMessageBox::Ok);
                        msgBox.exec();}
                }
            }
            else if(countt==3){
                if(PrintQR::checkConnection()){
                QStringList QRData={SN,customCombo->currentText(),"","",MyFunctions::convertToEnglishString( ui->dateEdit->text()),MyFunctions::convertToEnglishString( ui->dateEdit_2->text())};
                    PrintQR::printQRCode(QRData,currentDevice);}
            }
            else;
            logger::log("inserted product Info and product sec info : "+ QString::number(er)+" & "  +QString::number(err)+" inserted data for " + currentDevice);
            if(countt==1) emit pageUpdate();
            this->close();
        }
        else{
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("Error");
            msgBox.setText("شماره سریال تکراری است");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
        }

    }
    else {
        logger::log("updated "+ currentDevice + " table");
        ItemHandler::updateTable(currentDevice,columns,givenData);
        QSqlQuery q(db.getConnection());
        q.prepare("UPDATE ProductInfo SET  PurchaseDate  = ? , GuarantyExp = ? WHERE SerialNO = ?");
        q.addBindValue( MyFunctions::convertToEnglishString(ui->dateEdit->text()));
        q.addBindValue(MyFunctions::convertToEnglishString(ui->dateEdit_2->text()));
        q.addBindValue(givenData[0].toString());
        // qDebug() << givenData;
        bool err = q.exec();
        if (!err) {
            // qDebug() << "Error in ProductSecInfo insert:" << q.lastError().text();
        }
        if(countt==1)emit pageUpdate();
        this->close();
    }
    }
    else{
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Error");
        msgBox.setText("نام مشتری نادرست است");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
}
}
void DeviceForm::addBelonging(QString deviceName){
    emit belongingPage(deviceName);
}
void DeviceForm::hideBelonging(QString deviceName){
    emit hideBelongingPage(deviceName);
}
void DeviceForm::clearPage(){
    for (QCheckBox *checkbox : checkBoxes){checkbox->setChecked(false);}
    for (QComboBox *combobox : comboBoxes){combobox->setCurrentIndex(0);}
    customCombo->setCurrentText("");
    ui->textEdit->setText("");
    ui->lineEdit->setText("");
}
void DeviceForm::on_AddItemBtn_clicked()
{
    addItem(currentDevice);
}

void DeviceForm::getCustomers() {
    QSqlQuery query(db.getConnection());

    QStringList res;

    query.prepare("SELECT Name FROM CustomerInfo");
    // query.bindValue(":halfText", "%" + halfText + "%");  // Use wildcards for partial match

    // Execute the query
    if (query.exec()) {
//        qDebug() << "Fetch the results";
        while (query.next()) {
            res << query.value(0).toString();  // Assuming 'name' is the first column
        }
    } else {
        // qDebug() << "Query execution failed:" << query.lastError().text();
    }
    customers = res;
    // QCompleter *cCompleter = new QCompleter(customers);
    // cCompleter->setFilterMode(Qt::MatchContains);
    // cCompleter->popup()->setStyleSheet("font-size: 20px");
    customCombo->setCompleterData(customers);

}

void DeviceForm::on_CustomerCombo_editTextChanged(const QString &arg1) {

    customCombo->setCurrentText(arg1.toUpper());
}

void DeviceForm::on_pushButton_clicked()
{
    emit addCustomer();
}

void DeviceForm::adminMode(){
    QStringList combos={};
    for(QComboBox *comboBox: comboBoxes){
        combos.append(comboBox->currentText());
    }
    QStringList dates = {MyFunctions::convertToEnglishString(ui->dateEdit->text()),MyFunctions::convertToEnglishString(ui->dateEdit_2->text())};
    QStringList checks={};
    for(QCheckBox *checkBox: checkBoxes){
        if(checkBox->isChecked()) checks.append("1");
        else checks.append("0");
    }
    bool ischecked = ui->checkBox->isChecked();
    int count = MyFunctions::convertToEnglishInt( ui->spinBox->text());
    if(!admiMode){
        if(MyFunctions::enterAdminMode()){

    admiMode= !admiMode;
        MyFunctions::setAdminMode(true);
    // if(!admiMode){ui->AddItemBtn->hide();}
    // else {ui->AddItemBtn->show();}

    setup();
        }
        else{
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("Error");
            msgBox.setText("حالت ادمین در حال استفاده است");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
        }
    }
    else{
        admiMode = !admiMode;
        emit closeEditItem();
        MyFunctions::setAdminMode(false);

        setup();
    }
    if(combos.size()==comboBoxes.size()){
        int i =0;
        for(QComboBox *comboBox : comboBoxes){
            comboBox->setCurrentText(combos[i]);
            i++;
        }
    }
    QStringList date1 = dates[0].split('/');
    QCalendar calendar(QCalendar::System::Jalali);
    ui->dateEdit->setCalendar(calendar);
    QDate jalaliDate = QDate(date1[0].toInt(),date1[1].toInt(),date1[2].toInt(),calendar);
    ui->dateEdit->setDate(jalaliDate);
    QStringList date2 = dates[1].split('/');
    ui->dateEdit_2->setCalendar(calendar);
    QDate jalaliDate2 = QDate(date2[0].toInt(),date2[1].toInt(),date2[2].toInt(),calendar);
    ui->dateEdit_2->setDate(jalaliDate2);
    int j=0;
    if(checks.size()==checkBoxes.size()){
        for(QCheckBox *checkBox: checkBoxes){
            checkBox->setChecked(checks[j]=="1");
            j++;
        }
    }
    ui->checkBox->setChecked(ischecked);
    if(ischecked) ui->spinBox->setValue(count);
}

void DeviceForm::keyBinds(){
    QAction *f0 = new QAction(this);
    f0->setShortcut(Qt::Key_Q | Qt::CTRL);

    connect(f0, SIGNAL(triggered()), this, SLOT(close()));
    this->addAction(f0);
    QAction *f1 = new QAction(this);
    f1->setShortcut(Qt::Key_S | Qt::CTRL);

    connect(f1, SIGNAL(triggered()), this, SLOT(on_SubmitBtn_clicked()));
    this->addAction(f1);
    QAction *f2 = new QAction(this);
    f2->setShortcut(Qt::Key_M | Qt::CTRL);

    connect(f2, SIGNAL(triggered()), this, SLOT(adminMode()));
    this->addAction(f2);

}

void DeviceForm::on_pushButton_2_clicked()
{
    emit addAbr();
}


void DeviceForm::closeEvent(QCloseEvent *event){
    if(admiMode){
        adminMode();
    }
    event->accept();
}

void DeviceForm::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter){
        bool moved = this->focusNextChild();
        if (moved) {
            // qDebug() << "Moved focus to the next widget.";
        }

        // Mark the event as accepted
        event->accept();
    }
    else{}
}

void DeviceForm::setTabOrders(){
    setTabOrder(ui->comboBox,ui->lineEdit);
    setTabOrder(ui->lineEdit,customCombo);
    setTabOrder(customCombo,ui->pushButton);
    setTabOrder(ui->pushButton,ui->dateEdit);
    setTabOrder(ui->dateEdit,ui->dateEdit_2);
    if(comboBoxes.size()>1){
        setTabOrder(ui->dateEdit_2,comboBoxes.at(0));
        for(int i=1;i<comboBoxes.size();i++){
            setTabOrder(comboBoxes.at(i-1),comboBoxes.at(i));
        }
        setTabOrder(comboBoxes.at(comboBoxes.size()-1),ui->textEdit);
    }
    else if(comboBoxes.size()==1){
        setTabOrder(ui->dateEdit_2,comboBoxes.at(0));
        setTabOrder(comboBoxes.at(0),ui->textEdit);
    }
    else    {setTabOrder(ui->dateEdit_2,ui->textEdit);}
    if(checkBoxes.size()>1){
        setTabOrder(ui->textEdit,checkBoxes.at(0));
        for(int i=1;i<checkBoxes.size();i++){
            setTabOrder(checkBoxes.at(i-1),checkBoxes.at(i));
        }
        setTabOrder(checkBoxes.at(checkBoxes.size()-1),ui->SubmitBtn);
    }
    else if(checkBoxes.size()==1){
        setTabOrder(ui->textEdit,checkBoxes.at(0));
        setTabOrder(checkBoxes.at(0),ui->SubmitBtn);
    }
    else    {setTabOrder(ui->textEdit,ui->SubmitBtn);}
    // if(!comboBoxes.isEmpty()){
    //     setTabOrder(customCombo, comboBoxes.at(0));
    // }
}

void DeviceForm::on_checkBox_stateChanged(int arg1)
{
    ui->spinBox->setDisabled(!arg1);
    // addBulk();
}

void DeviceForm::addBulk(){
    logger::log("addBulk start");
    // int countt = count;
    // qDebug() << "after asking";
    emit setPBRange(MyFunctions::convertToEnglishInt( ui->spinBox->text()));
    handleStarted();
    // ui->progressBar->setRange(0,ui->spinBox->text().toInt());
        QSqlQuery query(db.getConnection());
        QString serialno = ui->lineEdit->text();
        setColumns();
        setChecks();
        setCombos();
            for(int i=0;i<MyFunctions::convertToEnglishInt( ui->spinBox->text());i++){
            submit(serialno,count);
            emit setPBVal(i);
            unsigned int a = MyFunctions::reverseSN(serialno).toUInt();
            a +=1;
            serialno = MyFunctions::intToStr(a);
        }
        handleFinished();
    checked = true;

        logger::log("addbulk done!!");
}
bool DeviceForm::checkBulkSN(){
    logger::log("checking bulk sn");
    QSqlQuery query(db.getConnection());

    QStringList res;
    QString serialno = ui->lineEdit->text();
    for(int i=0;i<MyFunctions::convertToEnglishInt( ui->spinBox->text());i++){

        query.prepare("SELECT SerialNO FROM ProductInfo WHERE SerialNO LIKE ?");
        query.addBindValue(MyFunctions::reverseSN(serialno));  // Use wildcards for partial match

        // Execute the query
        if (query.exec()) {

            while (query.next()) {
                res.append( query.value(0).toString());
            }
        } else {
            // qDebug() << "Query execution failed:" << query.lastError().text();
        }
        unsigned int a = MyFunctions::reverseSN(serialno).toUInt();
        a +=1;
        serialno = MyFunctions::intToStr(a);
    }
    if(res.isEmpty()){
        // qDebug() << "no duplicates";
        return true;
    }

    else{
        // qDebug () << res;
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Error");
        QString msgTxt;
        if(res.size()>1){
            msgTxt = "شماره سریال های";
            for(int i=0;i<res.size();i++){
                msgTxt.append(" "+MyFunctions::intToStr( res[i].toUInt()));
            }
            msgTxt.append(" تکراری میباشند");
        }
        else{
            msgTxt = "شماره سریال ";
            msgTxt.append(MyFunctions::intToStr( res[0].toUInt()));
            msgTxt.append(" تکراری است");
        }
        msgBox.setText(msgTxt);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        return false;
    }
}
void DeviceForm::setColumns(){
    QString newText = "";
    columns=QStringList( {"SerialNumber", "CustomerName" ,"description","belongings"});
    //description TEXT, belongings TEXT
    for (QLabel *label : labels) {
        QString text = label->text();
        for(int i=0;i<text.size(); i++){
            if (text.at(i)==" "){newText.append("_");}
            else{newText.append(text.at(i));}
        }
        columns.append(text);
    }
    // qDebug () << columns;
}
void DeviceForm::setChecks(){
    QString checks = "";
    for (QCheckBox *checkBox : checkBoxes){
        if(checkBox->isChecked()){
            checks.append(checkBox->text()+" ");}
    }
    this->checks = checks;
}
void DeviceForm::setCombos(){
    combos = QStringList({});
    for (QComboBox *comboBox : comboBoxes) {
        QString text = comboBox->currentText();
        combos.append(text);
    }
}
void DeviceForm::handleStarted(){
    // qDebug() << "handle started yooo";
    emit showPB();
}
void DeviceForm::handleFinished(){
    emit hidePB();
    emit pageUpdate();
}
void DeviceForm::loadDate(unsigned int id){
    QSqlQuery query(db.getConnection());
    query.prepare("SELECT * FROM ProductInfo WHERE SerialNO = :serialNumber");
    query.bindValue(":serialNumber", QString::number(id));
    //    qDebug() << "Executing query for ProductSecInfo with Serialnum:" << Serialnum;

    if (!query.exec()) {
        // qDebug() << "Database query error:" << query.lastError().text();
    } else {
        if (query.next()) {

            QCalendar calendar(QCalendar::System::Jalali);
            ui->dateEdit_2->setCalendar(calendar);
            QString rt = query.value("GuarantyExp").toString();
            QStringList parts = rt.split('/');
            if (parts.size() == 3) {
                int year = parts[0].toInt();
                int month = parts[1].toInt();
                int day = parts[2].toInt();
                QDate jalaliDate = QDate(year, month, day, calendar);
                if (jalaliDate.isValid()) {
                    ui->dateEdit_2->setDate(jalaliDate);
                } else {
                    ui->dateEdit_2->setDate(QDate::currentDate().addYears(1));
                }
            } else {
                ui->dateEdit_2->setDate(QDate::currentDate().addYears(1));
            }
            // QCalendar calendar(QCalendar::System::Jalali);
            ui->dateEdit->setCalendar(calendar);
            rt = query.value("PurchaseDate").toString();
            parts = rt.split('/');
            if (parts.size() == 3) {
                int year = parts[0].toInt();
                int month = parts[1].toInt();
                int day = parts[2].toInt();
                // qDebug() << year<<month<<day<<"dateeeee";
                QDate jalaliDate = QDate(year, month, day, calendar);
                if (jalaliDate.isValid()) {
                    ui->dateEdit->setDate(jalaliDate);
                } else {
                    ui->dateEdit->setDate(QDate::currentDate());
                }
            } else {
                ui->dateEdit->setDate(QDate::currentDate());}
        } else {
            // qDebug() << "No data found for serial number:" << id;
        }
    }
}

void DeviceForm::on_pushButton_3_clicked()
{
    emit editItem(currentDevice);
}

void DeviceForm::loadLastSN() {
    this->max=0;
    unsigned int max = 0;

    QSqlQuery query(db.getConnection());
    QString queryStr = QString("SELECT SerialNumber FROM %1").arg(currentDevice);
    query.prepare(queryStr);

    if (!query.exec()) {
        // qDebug() << "Database query error:" << query.lastError().text();
    } else {
        while (query.next()) {
            unsigned int curr = query.value(0).toUInt();

            // Extract the last four digits
            unsigned int lastFourDigits = curr % 10000;

            // Check if these last four digits are the maximum found so far
            if (lastFourDigits > max) {
                max = lastFourDigits;
                this->max=curr;
            }
        }
    }
    if(this->max>0)
        ui->lastSNLabel->setText(MyFunctions::intToStr(this->max)+ " : " +"آخرین شماره سریال ");
    // qDebug() << "Executed query:" << query.executedQuery();
}

bool DeviceForm::askForQR(){
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("QR Code");
    msgBox.setText("آیا میخواهید QR Code را هم پرینت بگیرید؟");
    msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int res = msgBox.exec();
    switch(res) {
    case QMessageBox::Yes :{
        return true;
        break;
    }
    case QMessageBox::No :{
        return false;
        break;
    }
    default :
        return false;
        break;

    }
}

void DeviceForm::on_EditQRBtn_clicked()
{
    emit openQREdit();
}

void DeviceForm::on_pushButton_4_clicked()
{
    emit openDeleteItem(currentDevice);
}

bool DeviceForm::checkItem(QString deviceName,QString itemName){

    QSqlQuery query(db.getConnection());
    QString res = QString("SELECT * FROM " + deviceName + " WHERE " +itemName+" NOT LIKE 'هیچ کدام'");
    query.prepare(res);

    if (query.exec()) {
        while (query.next()) {
            for (int i = 0; i < query.record().count(); ++i) {
                // qDebug()<< ": " << query.value(i).toString();
            }
        }
    } else {
        // qDebug() << "Query failed: " << query.lastError().text();
    }

}


