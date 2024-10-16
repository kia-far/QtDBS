#ifndef CHANGEDB_H
#define CHANGEDB_H

#include <QDialog>

namespace Ui {
class ChangeDB;
}

class ChangeDB : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeDB(QWidget *parent = nullptr);
    ~ChangeDB();

private:
    Ui::ChangeDB *ui;
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // CHANGEDB_H
