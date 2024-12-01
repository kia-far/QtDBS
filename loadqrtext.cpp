#include "loadqrtext.h"
#include "ui_loadqrtext.h"
#include <QKeyEvent>
#include <QFile>
#include <QDebug>
#include <QMessageBox>


LoadQRText::LoadQRText(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoadQRText)
{
    ui->setupUi(this);
}

LoadQRText::~LoadQRText()
{
    delete ui;
}


QString LoadQRText::loadText(const QString& path) {
    QString filePath = path;
    qDebug() << "This is the path:" << path;

    if (filePath.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Info");
        msgBox.setText("Provided path is empty. Opening local text file.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        filePath = getDefaultFilePath();
        qDebug() << "Using default file path:" << filePath;
    }

    // Open the first file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return QString();
    }

    QTextStream in(&file);
    in.setCodec("UTF-8"); // Ensure UTF-8 encoding
    QString content = in.readLine();
    file.close();

    qDebug() << "This is content:" << content;

    // Open the second file (QRText.txt)
    QFile textFile(content + "\\QRText.txt");
    if (!textFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open QRText.txt file:" << textFile.errorString();
        return QString();
    }

    QTextStream secin(&textFile);
    secin.setCodec("UTF-8"); // Ensure UTF-8 encoding
    content = secin.readAll();
    textFile.close();

    return content;
}

QString LoadQRText::getDefaultFilePath() {
    QString applicationPath = qApp->applicationDirPath();
    return applicationPath + "/QRText"; // Default local file name
}
void LoadQRText::keyPressEvent(QKeyEvent *event){
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

void LoadQRText::setup(){
    loadText();
    this->show();
}

void LoadQRText::loadText() {
    QString text = "";
    QString adr = qApp->applicationDirPath();
    QString QRPathFile = adr + "/QRPath";

    // Load the text from the file
    text = loadText(QRPathFile);

    // Set the text in QTextEdit
    ui->textEdit->setText(text);
}

void LoadQRText::on_buttonBox_accepted()
{
    QString newtext =QString::fromUtf8( ui->textEdit->toPlainText().toUtf8());
    if(newtext.contains("serialnumber")&&newtext.contains("xxxx/xx/xx")&&newtext.contains("yyyy/yy/yy")&&newtext.contains("devicename")&&newtext.contains("customername")){
    QString adr = qApp->applicationDirPath();
    QString QRPathFile = adr+"/QRPath";
    saveText(QRPathFile,newtext.toUtf8());
    this->close();
    }
    else{
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Info");
        msgBox.setText("متن QR code باید عبارات زیر را داشته باشد :\
serialnumber, devicename, customername, xxxx/xx/xx, yyyy/yy/yy");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}


void LoadQRText::on_buttonBox_rejected()
{
    this->close();
}

void LoadQRText::saveText(const QString& path, const QString& text) {
    QString filePath = path;
    qDebug() << "This is the path:" << path;

    // Handle empty file path by providing a default path
    if (filePath.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Info");
        msgBox.setText("Provided path is empty. Using local text file.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        filePath = getDefaultFilePath();
        qDebug() << "Using default file path:" << filePath;
    }

    // Open the first file to read the path to QRText.txt
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8"); // Ensure proper encoding for reading
    QString content = in.readLine();
    file.close();

    qDebug() << "This is content:" << content;

    // Construct the full path for QRText.txt
    QFile textFile(content + "\\QRText.txt");
    if (!textFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open QRText.txt file:" << textFile.errorString();
        return;
    }

    // Write the new content to the file
    QTextStream out(&textFile);
    out.setCodec("UTF-8"); // Ensure proper encoding for writing
    out << text;
    textFile.close();

    qDebug() << "Text successfully saved to QRText.txt";
}

