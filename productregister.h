#ifndef PRODUCTREGISTER_H
#define PRODUCTREGISTER_H

#include <QWidget>
#include <QSqlDatabase>
#include <DatabaseConnection.h>
#include <QCloseEvent>
#include <QKeyEvent>

namespace Ui {
class ProductRegister;
}

class ProductRegister : public QWidget
{
    Q_OBJECT

public:
    explicit ProductRegister(QWidget *parent = nullptr);
    ~ProductRegister();
    void regOn();
    void regSubmit();
    void editOn(unsigned int serial);
    void editSubmit();
    void setup();
    void trigger(unsigned int serialnum);
    void addTrigger();
    void loadProductInfo();
    void loadProductSecInfo();
    void updateProductInfo();
    void updateProductSecInfo();
    bool registerProductInfo();
    bool registerProductSecInfo();
    void closeEvent(QCloseEvent *event) override;
signals :
    void devicePage();
    void pageUpdate();
    void addAbr();
    void callHelpPop(QString text);
private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_devBtn_clicked();

    void adminMode();




    void on_pushButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);
    void showHelpPop();

private:
    Ui::ProductRegister *ui;
    void keybinds();
//    QSqlDatabase db;
    QString Mode;
    unsigned int Serialnum;
    DatabaseConnection &db;
    bool admiMode;
    void loadLastSN(QString device);
    unsigned int max;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // PRODUCTREGISTER_H
