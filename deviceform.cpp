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


DeviceForm::DeviceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceForm),
    db(DatabaseConnection::getInstance())
{
    // progressBar;
    ui->setupUi(this);

    ui->spinBox->setMinimumSize(50,25);
    ui->spinBox->setValue(1);
    ui->spinBox->setDisabled(true);
    admiMode=false;
    checked = true;
    setup();
    if(!admiMode){ui->pushButton_3->hide();ui->AddItemBtn->hide();ui->pushButton_2->hide(); }
//    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(this.close()));
    keyBinds();

}
int indexx;
int indexcounter = 0;
DeviceForm::~DeviceForm()
{
    delete ui;
}

void DeviceForm::trigger(QString device){
    clearPage();
    admiMode = false;
    currentDevice = device;
    this->show();
    this->activateWindow();


    setup();
}

void DeviceForm::setup(){
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
    if(!admiMode){ui->pushButton_3->hide();ui->AddItemBtn->hide();ui->pushButton_2->hide(); }
    else {ui->pushButton_3->show();ui->AddItemBtn->show();ui->pushButton_2->show(); }
    edit = false;
    // admiMode = false;
    QString curDev = currentDevice;
    QStringList devices = ItemHandler::loadDevices();
    ui->comboBox->clear();
    for(int i=0;i<devices.length();i++){
    ui->comboBox->addItem(devices[i]);}
    ui->comboBox->setCurrentText(curDev);
    if(admiMode){

    ui->comboBox->addItem("دستگاه جدید");}
    ui->comboBox->setFixedWidth(120);
    ui->pushButton->setFixedWidth(35);
    setTabOrders();
}
void DeviceForm::editDevice(QString device , unsigned int id){

    this->show();
    this->activateWindow();


    currentDevice = device;
    admiMode = false;
    setup();
    ui->comboBox->setCurrentText(device);
    ui->lineEdit->setText(MyFunctions::intToStr(id));
    populateEdit(device,id);
}
void DeviceForm::refresh(QString arg1){
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
}
void DeviceForm::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1=="دستگاه جدید"){
        addDevice();
        ui->comboBox->setCurrentIndex(0);
    }
    else{
    currentDevice = arg1;
        refresh(arg1);

}}
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
    loadDate(id);
    ui->comboBox->clear();
    ui->comboBox->addItem(device);
    ui->lineEdit->setReadOnly(true);
    ui->checkBox->setChecked(false);
    ui->checkBox->setDisabled(true);
    ui->spinBox->setValue(1);
    ui->spinBox->setDisabled(true);
    edit = true;
    QString newText="";
    QSqlQuery query(db.getConnection());

    QStringList res;

    query.prepare("SELECT * FROM " + device + " WHERE SerialNumber LIKE "+QString::number(id));

    if (query.exec()) {
        QSqlRecord record = query.record();
        int numCols = record.count();
//        qDebug() << "Fetch the results";
        while (query.next()) {
            for (int i=0;i<numCols;i++){
            res.append( query.value(i).toString());
        }}
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }
    // qDebug() << "this is res "<<res ;
    // qDebug() << "this is ID" <<id;
    ui->CustomerCombo->setCurrentText(res[1]);
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
//    QVariantList givenData = {MyFunctions::reverseSN( ui->lineEdit->text()).toInt(),ui->CustomerCombo->currentText(),ui->textEdit->toPlainText(), checks};
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
                if(ui->spinBox->text().toInt()>1){
                    if(checkBulkSN()){
                        if(MyFunctions::checkData(ui->CustomerCombo->currentText(),"Name","CustomerInfo")||ui->CustomerCombo->currentText()==""){
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
            if(ui->spinBox->text().toInt()>1){
                if(ui->spinBox->text().toInt()>1){
                    if(checkBulkSN()){
                        if(MyFunctions::checkData(ui->CustomerCombo->currentText(),"Name","CustomerInfo")||ui->CustomerCombo->currentText()==""){
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
                submit(ui->lineEdit->text(),1);}

        }
}
    else{        QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Error");
    msgBox.setText("شماره سریال صحیح نمیباشد");
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
    if(countt>1||(ui->CustomerCombo->currentText()==""||MyFunctions::checkData(ui->CustomerCombo->currentText(),"Name","CustomerInfo"))){
        if(countt==1){
            setChecks();
            setColumns();
            setCombos();
        }
        QVariantList givenData;
            givenData = {MyFunctions::reverseSN(SN).toUInt(),ui->CustomerCombo->currentText(),ui->textEdit->toPlainText(), checks};
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
            qDebug() << "Error in ProductInfo insert:" << q.lastError().text();
        }
        q.prepare("INSERT INTO ProductSecInfo (SerialNO , PurchaseDate , GuarantyExp) VALUES (?,?,?)");
        q.addBindValue(givenData[0].toString());
        q.addBindValue(ui->dateEdit->text());
        q.addBindValue(ui->dateEdit_2->text());
        // qDebug() << givenData;
        bool err = q.exec();
        if (!err) {
            qDebug() << "Error in ProductSecInfo insert:" << q.lastError().text();
        }
        if(er&&err){
            ItemHandler::insertDataIntoTable(currentDevice,columns,givenData);
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
    ui->CustomerCombo->setCurrentText("");
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
        qDebug() << "Query execution failed:" << query.lastError().text();
    }
    customers = res;
    QCompleter *cCompleter = new QCompleter(customers);
    cCompleter->setFilterMode(Qt::MatchContains);
    cCompleter->popup()->setStyleSheet("font-size: 20px");
    ui->CustomerCombo->setCompleter(cCompleter);

}

void DeviceForm::on_CustomerCombo_editTextChanged(const QString &arg1) {

    ui->CustomerCombo->setCurrentText(arg1.toUpper());
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
    QStringList dates = {ui->dateEdit->text(),ui->dateEdit_2->text()};
    QStringList checks={};
    for(QCheckBox *checkBox: checkBoxes){
        if(checkBox->isChecked()) checks.append("1");
        else checks.append("0");
    }
    bool ischecked = ui->checkBox->isChecked();
    int count = ui->spinBox->value();
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
    setTabOrder(ui->lineEdit,ui->CustomerCombo);
    setTabOrder(ui->CustomerCombo,ui->pushButton);
    if(comboBoxes.size()>1){
        setTabOrder(ui->pushButton,comboBoxes.at(0));
        for(int i=1;i<comboBoxes.size();i++){
            setTabOrder(comboBoxes.at(i-1),comboBoxes.at(i));
        }
        setTabOrder(comboBoxes.at(comboBoxes.size()-1),ui->textEdit);
    }
    else if(comboBoxes.size()==1){
        setTabOrder(ui->pushButton,comboBoxes.at(0));
        setTabOrder(comboBoxes.at(0),ui->textEdit);
    }
    else    {setTabOrder(ui->pushButton,ui->textEdit);}
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
    //     setTabOrder(ui->CustomerCombo, comboBoxes.at(0));

    // }


}



void DeviceForm::on_checkBox_stateChanged(int arg1)
{
    ui->spinBox->setDisabled(!arg1);
    // addBulk();
}

void DeviceForm::addBulk(){
    emit setPBRange(ui->spinBox->text().toInt());
    handleStarted();
    // ui->progressBar->setRange(0,ui->spinBox->text().toInt());
        QSqlQuery query(db.getConnection());
        QString serialno = ui->lineEdit->text();
        setColumns();
        setChecks();
        setCombos();
            for(int i=0;i<ui->spinBox->value();i++){
            submit(serialno,2);
            emit setPBVal(i);
            unsigned int a = MyFunctions::reverseSN(serialno).toUInt();
            a +=1;
            serialno = MyFunctions::intToStr(a);
        }
        handleFinished();
    checked = true;


}
bool DeviceForm::checkBulkSN(){
    QSqlQuery query(db.getConnection());

    QStringList res;
    QString serialno = ui->lineEdit->text();
    for(int i=0;i<ui->spinBox->text().toInt();i++){

        query.prepare("SELECT SerialNO FROM ProductInfo WHERE SerialNO LIKE ?");
        query.addBindValue(MyFunctions::reverseSN(serialno));  // Use wildcards for partial match

        // Execute the query
        if (query.exec()) {

            while (query.next()) {
                res.append( query.value(0).toString());
            }
        } else {
            qDebug() << "Query execution failed:" << query.lastError().text();
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
    query.prepare("SELECT * FROM ProductSecInfo WHERE SerialNO = :serialNumber");
    query.bindValue(":serialNumber", QString::number(id));
    //    qDebug() << "Executing query for ProductSecInfo with Serialnum:" << Serialnum;

    if (!query.exec()) {
        qDebug() << "Database query error:" << query.lastError().text();
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
            qDebug() << "No data found for serial number:" << id;
        }
    }
}

void DeviceForm::on_pushButton_3_clicked()
{
    emit editItem(currentDevice);
}

