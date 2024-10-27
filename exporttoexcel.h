#ifndef EXPORTEXCEL_H
#define EXPORTEXCEL_H

#include <QObject>
#include <QTableView>

class ExportExcel : public QObject {
    Q_OBJECT
public:
    explicit ExportExcel(QObject *parent = nullptr);

    // Method to export data to an Excel file
    void exportToXlsx(QTableView *tableView);

signals:
    void exportSuccess(const QString &filePath);
    void exportError(const QString &errorMessage);

private:
    QString getSaveFilePath();
};

#endif // EXPORTEXCEL_H
