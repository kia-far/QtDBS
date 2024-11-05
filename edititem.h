#ifndef EDITITEM_H
#define EDITITEM_H

#include <QWidget>
#include <QListWidget>
namespace Ui {
class EditItem;
}

class EditItem : public QWidget
{
    Q_OBJECT

public:
    explicit EditItem(QWidget *parent = nullptr);
    ~EditItem();
    void setup(QString device);
    void closeForm();
signals:
    void updateForms(QString device);
    void refreshTable();
private slots:

    void on_pushButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::EditItem *ui;
    QString device;
    QString item;
};

#endif // EDITITEM_H
