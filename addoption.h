#ifndef ADDOPTION_H
#define ADDOPTION_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class AddOption;
}

class AddOption : public QWidget
{
    Q_OBJECT

public:
    explicit AddOption(QWidget *parent = nullptr);
    ~AddOption();
    void setupBelonging(QString deviceName);
    void showError(const QString errorMessage);
    void setupDevice();
    void setupItem(QString deviceName);
    void setupOption(QString deviceName , QString itemName);

signals:
    void updatePage(QString device);
    void addAbr();

private slots:
void on_pushButton_clicked();

    void on_AddOption_destroyed();

private:
    Ui::AddOption *ui;
    QString device;
    QString item;
    QString func;
    QLineEdit *lineEdit_2; // Member variable for QLineEdit
    QPushButton *editButton = nullptr;
    void cleanupDevice();
    bool devCalled;
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // ADDOPTION_H
