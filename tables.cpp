#include "tables.h"
#include "ui_tables.h"
#include "myfunctions.h"
#include "mainwindow.h"
#include "MyTableProxy.h"
#include <QApplication>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QtDebug>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QAction>
#include <QMessageBox>
#include "logger.h"
#include <QKeyEvent>
#include "exporttoexcel.h"
#include <QVariant>
#include <QSpacerItem>


unsigned int lastClicked =4294967294;
int currentTable =0;
int editSelect =0;
unsigned int clickedID =4294967294;
//bool inSearch=false;
QString searchParam;

Tables::Tables(MainWindow *mainWin,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tables),
    View(new ProxyView(this)),
    Product(new ProductProxy(this)),
//    MyTableProxy(new MyTableProxy(this)),
    db(DatabaseConnection::getInstance()),
    mainwindow(mainWin)

{

    ui->setupUi(this);
    ui->toolButton->setFixedHeight(30);
    ui->progressBar->setHidden(true);
    ui->label->setHidden(true);
//    ui->Edit->hide();
//    QSqlDatabase db;
//    db = QSqlDatabase ::addDatabase("QSQLITE");
//    db.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
//    db.open();
    ui->comboBox_2->addItems(ItemHandler::loadDevices());
    // qDebug() << "loadDevice result :"<<ItemHandler::loadDevices();
    QString addr = qApp->applicationDirPath();
    QFile file(addr+"/style/Style.qss"); // Use resource system or provide a direct path
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
        file.close();
        keybinds();
    }

    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->resizeColumnsToContents();
//    currentTable = 3;
}

Tables::~Tables()
{
    delete ui;
}

void Tables::setupTable(QString table){
    ui->comboBox_2->hide();
    if (table == "محصولات"){
        logger::log("producgt proxy laoded ");
        ui->deleteBtn->setHidden(false);
//        qDebug () << "product opened -------------------------------";
        currentTable = 3;
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->setModel(Product);
        ui->tableView->resizeColumnsToContents();
        logger::log("product proxy loaded into table");
    }
    else if(table == "دستگاه ها") {
        ui->deleteBtn->setHidden(false);
        ui->comboBox_2->show();
        currentDevice=ui->comboBox_2->currentText();
//        qDebug () << "device opened -------------------------------";
        QString searchParam = "SerialNumber";
        QString searchText = "";
        View->setSearchParameters(currentDevice,searchParam, searchText);
        currentTable = 2;
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->setModel(View);
        hideColumns();
        ui->tableView->resizeColumnsToContents();

    }
    else if(table == "خدمات") {
        ui->deleteBtn->setHidden(true);
//        qDebug () << "service opened -------------------------------";
        QStringList columnNames = {"شناسه","محصول","مشتری","تاریخ","مسئول","نوع خدمات","قطعه مشکل دار","توضیحات"}; // Example list
        QSqlDatabase a = (db.getConnection());
        MyTableProxy *Services = new MyTableProxy(columnNames,a,this);
        Services->loadData("SELECT * FROM ServiceInfo");
        ui->tableView->setModel(Services);
        currentTable =1;
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->resizeColumnsToContents();

    }
    else if(table == "مشتریان") {
        ui->deleteBtn->setHidden(true);
//        qDebug () << "customer opened -------------------------------";
//        QSqlQuery q(db.getConnection());
//        q.exec("SELECT * FROM CustomerInfo");
//        QSqlQueryModel *m = new QSqlQueryModel;
//        m -> setQuery(q);
//        currentTable = 0;
//        ui->tableView->setModel(m);
//+++++++++++++++++++++++++
        QStringList columnNames = {"شناسه", "نام", "شماره تماس", "نام نماینده"}; // Example list
        QSqlDatabase a = (db.getConnection());
        MyTableProxy *Customer = new MyTableProxy(columnNames,a,this);
        Customer->loadData("SELECT * FROM CustomerInfo");
        ui->tableView->setModel(Customer);
        ui->tableView->resizeColumnsToContents();
        currentTable=0;
        ui->comboBox->setCurrentIndex(currentTable);


}
    else {qDebug() << "wrong input";}
this->showMaximized();
this->activateWindow();

}
void Tables::searchInfo(QString currentSearchParam,QString searchText){
    searchParam = currentSearchParam;
//    qDebug()<<QString::number(currentTable)+"  "  + "  "+ searchParam+ "   " +searchText;
    if(currentTable==0){




//        QSqlQuery query;
        QString res;
        if (searchText==""){res = "SELECT * FROM CustomerInfo";}
        else{res = "SELECT * FROM CustomerInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
        QStringList columnNames = {"شناسه", "نام", "شماره تماس", "نام نماینده"}; // Example list
        QSqlDatabase a = (db.getConnection());
        MyTableProxy *Customer = new MyTableProxy(columnNames,a,this);
        Customer->loadData(res);
        ui->tableView->setModel(Customer);
        ui->tableView->resizeColumnsToContents();
        // qDebug() << "hiiiiiii 1";
        showColumns();


    }
    else if (currentTable==1) {
        QString res;
        if(searchText==""){res = "SELECT * FROM ServiceInfo";}
        else{res = "SELECT * FROM ServiceInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
        QStringList columnNames = {"شناسه","محصول","مشتری","تاریخ","مسئول","نوع خدمات","قطعه مشکل دار","توضیحات"}; // Example list
        QSqlDatabase a = (db.getConnection());
        MyTableProxy *Services = new MyTableProxy(columnNames,a,this);
        Services->loadData(res);
        ui->tableView->setModel(Services);
        ui->tableView->resizeColumnsToContents();
        // qDebug() << "hiiiiiii 2";
        showColumns();
    }
    else if(currentTable==2){

        View->setSearchParameters(currentDevice,searchParam, searchText);
        ui->tableView->setModel(View);
        ui->tableView->resizeColumnsToContents();
        // qDebug() << "hiiiiiii 3";
        hideColumns();


    }
    else {
        logger::log("producgt proxy laoded ");
        ui->deleteBtn->setHidden(false);
        //        qDebug () << "product opened -------------------------------";
        // currentTable = 3;
        Product->setSearchParameters(searchParam,searchText);
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->setModel(Product);
        ui->tableView->resizeColumnsToContents();
        logger::log("product proxy loaded into table");
        showColumns();
    }
}
void Tables::on_comboBox_currentIndexChanged(const QString &arg1)
{
    logger::log("product proxy called");
    clickedID = 4294967294;
    lastClicked = 4294967294;
    currentDevice = "";
    ui->comboBox_2->hide();
    if(arg1 == "محصولات"){
        logger::log("producgt proxy laoded ");
        ui->deleteBtn->setHidden(false);
        //        qDebug () << "product opened -------------------------------";
        currentTable = 3;
        Product->setSearchParameters("ProductInfo.SerialNO","");
        ui->tableView->setModel(Product);
        ui->tableView->resizeColumnsToContents();
        logger::log("product proxy loaded into table");

        showColumns();
        currentTable =3;
        ui->widget->setHidden(true);
    }
    else if(arg1 == "مشتریان"){
        ui->deleteBtn->setHidden(true);
        QStringList columnNames = {"شناسه", "نام", "شماره تماس", "نام نماینده"}; // Example list
        QSqlDatabase a = (db.getConnection());
        MyTableProxy *Customer = new MyTableProxy(columnNames,a,this);
        Customer->loadData("SELECT * FROM CustomerInfo");
        ui->tableView->setModel(Customer);
        currentTable =0;
        ui->tableView->resizeColumnsToContents();
        ui->widget->setHidden(true);
        showColumns();

    }
    else if (arg1 == "خدمات"){
        ui->deleteBtn->setHidden(true);
        QStringList columnNames = {"شناسه","محصول","مشتری","تاریخ","مسئول","نوع خدمات","قطعه مشکل دار","توضیحات"}; // Example list
        QSqlDatabase a = (db.getConnection());
        MyTableProxy *Services = new MyTableProxy(columnNames,a,this);
        Services->loadData("SELECT * FROM ServiceInfo");
        ui->tableView->setModel(Services);
        currentTable =1;
        ui->tableView->resizeColumnsToContents();
        ui->widget->setHidden(true);
        showColumns();

    }
    else if (arg1 == "دستگاه ها") {
        ui->deleteBtn->setHidden(false);
        ui->comboBox_2->show();
        currentDevice=ui->comboBox_2->currentText();
        QString searchParam = "SerialNumber";
        QString searchText = "";
        View->setSearchParameters(currentDevice,searchParam, searchText);
        ui->tableView->setModel(View);

        currentTable = 2;
        hideColumns();
        ui->tableView->resizeColumnsToContents();
        setupWidget();
        ui->widget->setHidden(false);



    }
    Tables::on_RefreshBtn_clicked();
}


void Tables::on_EditBtn_clicked()
{
    if(clickedID!=4294967294&&lastClicked!=4294967294){
        // qDebug() << "clickedID :" << clickedID <<"lastClicked :" << lastClicked;
        if (currentTable == 0){emit editCustomer(clickedID);}
        else if (currentTable == 1){emit editService(clickedID);}
        else if (currentTable == 2){emit editDevice(currentDevice,lastClicked);}
        else {emit editProduct(lastClicked );}
    }
    else{
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Error");
        msgBox.setText("خانه ای انتخاب نشده است");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}


void Tables::on_tableView_clicked(const QModelIndex &index)
{
    int selectedRow = index.row();
//    qDebug() << "Selected row:" << selectedRow;
    QVariant data = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow, 0));
//    qDebug() << "Data in the first column of the selected row:" << data.toString();
    lastClicked = (MyFunctions ::reverseSN(data.toString())).toUInt();
    clickedID = data.toUInt();
    if(currentTable == 2){currentDevice = ui->comboBox_2->currentText();
        populateLabel(index.row());
    }
    else if(currentTable == 3){

        currentDevice = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow,1)).toString();
        // qDebug() << "currentDevice : "  << currentDevice;
    }
}


void Tables::on_SearchBtn_clicked()
{
    emit searchActive(currentTable);
}


void Tables::on_AddBtn_clicked()
{
    if (currentTable==3){emit addProduct();}
    else if(currentTable==2){emit addDevice(currentDevice);}
    else if(currentTable==1){emit addService();}
    else{emit addCustomer();}
}


void Tables::on_RefreshBtn_clicked()
{
    emit refreshActive(currentTable);
}

void Tables::pageRefresh(){
    emit refreshActive(currentTable);

}

void Tables::on_mainWindowBtn_clicked()
{
    this->hide();
    mainwindow->show();
}





void Tables::on_comboBox_2_currentIndexChanged(const QString &arg1)
{

    clickedID = 4294967294;
    lastClicked =4294967294;
    currentDevice = arg1;
    QString searchParam = "SerialNumber";
    QString searchText = "";
    View->setSearchParameters(currentDevice,searchParam, searchText);
    ui->tableView->setModel(View);
    hideColumns();
    ui->tableView->resizeColumnsToContents();
    Tables::on_RefreshBtn_clicked();
    hideColumns();
    setupWidget();
}


void Tables::on_tableView_doubleClicked(const QModelIndex &index)
{
    // qDebug() << "index :" << index<< "clickedID :" << clickedID <<"lastClicked :" << lastClicked;
    if (currentTable == 0){emit editCustomer(clickedID);}
    else if (currentTable == 1){emit editService(clickedID);}
    else if (currentTable == 2){emit editDevice(currentDevice,lastClicked);}
    else {emit editProduct(lastClicked );}
}

void Tables::keybinds(){
    QAction *f0 = new QAction(this);
    f0->setShortcut(Qt::Key_Q | Qt::CTRL);

    connect(f0, SIGNAL(triggered()), this, SLOT(on_mainWindowBtn_clicked()));
    this->addAction(f0);
    QAction *f1 = new QAction(this);
    f1->setShortcut(Qt::Key_R | Qt::CTRL);

    connect(f1, SIGNAL(triggered()), this, SLOT(on_RefreshBtn_clicked()));
    this->addAction(f1);
    QAction *f2 = new QAction(this);
    f2->setShortcut(Qt::Key_F | Qt::CTRL);

    connect(f2, SIGNAL(triggered()), this, SLOT(on_SearchBtn_clicked()));
    this->addAction(f2);
    QAction *f3 = new QAction(this);
    f3->setShortcut(Qt::Key_N | Qt::CTRL);

    connect(f3, SIGNAL(triggered()), this, SLOT(on_AddBtn_clicked()));
    this->addAction(f3);
   QAction *f4 = new QAction(this);
   f4->setShortcut(Qt::Key_E | Qt::CTRL);

   connect(f4, SIGNAL(triggered()), this, SLOT(getExport()));
   this->addAction(f4);
//    QAction *f5 = new QAction(this);
//    f5->setShortcut(Qt::Key_C | Qt::CTRL);

//    connect(f5, SIGNAL(triggered()), this, SLOT(on_comboBox_currentIndexChanged("Customers")));
//    this->addAction(f5);
//    QAction *f6 = new QAction(this);
//    f6->setShortcut(Qt::Key_S | Qt::CTRL);

//    connect(f6, SIGNAL(triggered()), this, SLOT(on_comboBox_currentIndexChanged("Services")));
//    this->addAction(f6);
}

void Tables::on_deleteBtn_clicked()
{

    if(clickedID!=4294967294&&lastClicked!=4294967294){
        // qDebug() << "clickedID :" << clickedID <<"lastClicked :" << lastClicked;

        if (currentTable == 2){/*emit editDevice(currentDevice,lastClicked);*/
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Error");
            msgBox.setText("آیا از پاک کردن این دستگاه مطمئنید؟");
            msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int res = msgBox.exec();
            switch(res) {
            case QMessageBox::Yes :{
                // qDebug() << "delete device";
                deleteRow(lastClicked,currentDevice);
                pageRefresh();
                // submit();
                break;
            }
            case QMessageBox::No :{
                break;
            }
            default :
                break;

            }
        }
        else if(currentTable == 3){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Error");
            msgBox.setText("آیا از پاک کردن این محصول مطمئنید؟");
            msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int res = msgBox.exec();
            switch(res) {
            case QMessageBox::Yes :{
                // qDebug() << "delete product" ;
                deleteRow(lastClicked,currentDevice);
                pageRefresh();
                // submit();
                break;
            }
            case QMessageBox::No :{
                break;
            }
            default :
                break;

            }
        }
        else{}
    }
    else{
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Error");
        msgBox.setText("خانه ای انتخاب نشده است");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }

}

void Tables::deleteRow(unsigned int ID, QString device) {
    QSqlDatabase db = QSqlDatabase::database();  // Assuming db connection is already established
    QSqlQuery query(db);

    // Enable foreign key constraints (especially important for SQLite)
    query.exec("PRAGMA foreign_keys = ON;");

    // Begin transaction
    if (!db.transaction()) {
        qDebug() << "Failed to start transaction:" << db.lastError().text();
        return;
    }

    // Delete from ProductSecInfo first (child table)
    query.prepare("DELETE FROM ProductSecInfo WHERE SerialNO = ?");
    query.addBindValue(ID);

    if (!query.exec()) {
        qDebug() << "Error in deleting from ProductSecInfo:" << query.lastError().text();
        db.rollback();
        return;
    }

    // Now delete from ProductInfo (parent table)
    query.prepare("DELETE FROM ProductInfo WHERE SerialNO = ?");
    query.addBindValue(ID);

    if (!query.exec()) {
        qDebug() << "Error in deleting from ProductInfo:" << query.lastError().text();
        db.rollback();
        return;
    }

    // Finally, delete from the device-specific table
    query.prepare(QString("DELETE FROM %1 WHERE SerialNumber = ?").arg(device));
    query.addBindValue(ID);

    if (!query.exec()) {
        qDebug() << "Error in deleting from" << device << ":" << query.lastError().text();
        db.rollback();
        return;
    }

    // Commit transaction if all deletes succeed
    if (!db.commit()) {
        qDebug() << "Failed to commit transaction:" << db.lastError().text();
        db.rollback();
    } else {
        // qDebug() << "Rows successfully deleted from all tables";
    }
    Product->setSearchParameters("ProductInfo.SerialNO", "");
    ui->tableView->setModel(Product);
    ui->tableView->resizeColumnsToContents();

}


void Tables::keyPressEvent(QKeyEvent *event){
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
void Tables::handlePBStarted(){
    ui->progressBar->setHidden(false);
    ui->label->setHidden(false);
    handleBtnEnable(true);
}
void Tables::handlePBFinished(){
    ui->progressBar->setHidden(true);
    ui->label->setHidden(true);
    handleBtnEnable(false);
}
void Tables::setPBValue(int val){
    ui->progressBar->setValue(val);
}
void Tables::setPBRange(int range){
    ui->progressBar->setRange(0,range);
}
void Tables::handleBtnEnable(bool a){
    ui->comboBox->setDisabled(a);
    ui->comboBox_2->setDisabled(a);
    ui->AddBtn->setDisabled(a);
    ui->EditBtn->setDisabled(a);
    ui->RefreshBtn->setDisabled(a);
    ui->SearchBtn->setDisabled(a);
    ui->deleteBtn->setDisabled(a);
    ui->mainWindowBtn->setDisabled(a);
    ui->tableView->setDisabled(a);
    ui->toolButton->setDisabled(a);
}
void Tables::getExport(){
    qDebug() << "exported";
    ExportExcel exporter;
    exporter.exportToXlsx(ui->tableView);
}


void Tables::on_toolButton_clicked()
{
    getExport();
}
void Tables::hideColumns(){

    int columnCount = View->columnCount();
    for (int i = 0; i < columnCount; ++i) {
        ui->tableView->setColumnHidden(i, false);}
    // int columnCount = View->columnCount();
        // qDebug()<<columnCount<<"this column countttt";
    for (int i = 2; i < columnCount-3; ++i) {
        // ui->tableView->setColumnHidden(i, true);
    }
    // ui->tableView->setColumnHidden(columnCount-2,true);
    // ui->tableView->setColumnHidden(columnCount-1,true);
    }
void Tables::showColumns(){
    int columnCount = View->columnCount();
    for (int i = 0; i < columnCount; ++i) {
        ui->tableView->setColumnHidden(i, false);
    }}
void Tables::populateLabel(int row) {
    qDebug() << lineEdits.size();
    ExportExcel exporter;
    QString text = "<div style='word-wrap: break-word;'>";
    int i = 0;
    QList<QVariant> data = exporter.getRowData(ui->tableView, row);

    for (QVariant variant : data) {
        // // if (i % 3 == 0 && i != 0) {
        // //     text.append("<br>");
        // // }
        // QString headerText = ui->tableView->model()->headerData(i, Qt::Horizontal).toString();

        // text.append(QString("<span style='font-size:%1pt;'><b>%2</b></span>")
        //                 .arg(ui->textBrowser->font().pointSize() + 2)
        //                 .arg(headerText));
        // text.append("<b> : </b>");
        // text.append(variant.toString());
        // if(i==0){text.append("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");}
        // if(i==1||i==2||i==data.size()-4||i==data.size()-2){text.append("<br>");}
        // else text.append("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"); // Adds spaces between each pair
        switch (i) {
        case 0:{ui->form_SN->setText(variant.toString());break;}
        case 1:{ui->form_Name->setText(variant.toString());break;}
        case 2:{
            for(QCheckBox *checkBox:checkBoxes){
                checkBox->setDisabled(false);
                checkBox->setChecked(variant.toString().contains(checkBox->text()));
                checkBox->setDisabled(true);
            }
            /*ui->form_pDate->setText(variant.toString());*/break;}
        // case 3:{ui->form_gDate->setText(variant.toString());break;}



        default:
            if(i==data.size()-3){ui->form_pDate->setText(variant.toString());}
            else if(i==data.size()-2){ui->form_gDate->setText(variant.toString());}
            else if(i==data.size()-1){ui->form_description->setText(variant.toString());}
            else{qDebug() << i;
                if(!lineEdits.isEmpty())lineEdits.at(i-3)->setText(variant.toString());}

            break;
        }
        i++;
    }
    text.append("</div>");
    // ui->form_description->setText(text);
}
void Tables::setupWidget(){
    clearLayout(ui->form_partHBox);
    clearLayout(ui->form_belHBox);
    checkBoxes.clear();
    lineEdits.clear();
    labels.clear();
    ui->form_dev->setText(currentDevice);
    // int index;
    for(int i=3;i<View->columnCount()-3;i++){
        QString itemName = ui->tableView->model()->headerData(i, Qt::Horizontal).toString();
        QLabel *label = new QLabel(itemName);
        QString labelName = QString("label_%1").arg(i);
        label->setObjectName(labelName);
        label->setText(itemName);
        label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        label->setAlignment(Qt::AlignCenter);
        label->adjustSize();

        labels.append(label);
        QString item = "";
        QLineEdit *lineEdit = new QLineEdit();
        QString lineEditName = QString("lineEdit_%1").arg(i);
        lineEdit->setText(item);
        lineEdit->setFixedSize(200,30);
        lineEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        lineEdit->adjustSize();

        lineEdits.append(lineEdit);
        QString hbName = QString("hb_%1").arg(i);
        QHBoxLayout *hb = new QHBoxLayout;
        hb->addWidget(label);
        hb->addWidget(lineEdit);
        QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        hb->addSpacerItem(spacer);
        ui->form_partHBox->addLayout(hb);

        QString headerText = ui->tableView->model()->headerData(i, Qt::Horizontal).toString();
    }
    int j=0;
    QStringList belongings = ItemHandler::loadbelongings(currentDevice);
    for(QString bel:belongings){
        QCheckBox *checkBox = new QCheckBox;
        QString CBName = QString("lineEdit_%1").arg(j);
        checkBox->setObjectName(CBName);
        checkBox->setText(bel);
        checkBox->setChecked(false);
        checkBox->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        checkBox->setDisabled(true);
        checkBoxes.append(checkBox);
        ui->form_belHBox->addWidget(checkBox);
        QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        ui->form_belHBox->addSpacerItem(spacer);
    }
}

void Tables::clearLayout(QLayout *layout) {

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
