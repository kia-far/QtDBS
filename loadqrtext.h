#ifndef LOADQRTEXT_H
#define LOADQRTEXT_H

#include <QWidget>

namespace Ui {
class LoadQRText;
}

class LoadQRText : public QWidget
{
    Q_OBJECT

public:
    explicit LoadQRText(QWidget *parent = nullptr);
    static QString loadText(const QString& path);
    static void saveText(const QString& path,const QString& text);
    static QString getDefaultFilePath();
    void setup();
    ~LoadQRText();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::LoadQRText *ui;
    void keyPressEvent(QKeyEvent *event) override;
    void loadText();
};

#endif // LOADQRTEXT_H
