#ifndef EXPORTEXCEL_H
#define EXPORTEXCEL_H

#include <QObject>
#include <QTableView>
#include <QList>
#include <QVariant>

class ExportExcel : public QObject {
    Q_OBJECT
public:
    explicit ExportExcel(QObject *parent = nullptr);

    // Method to export data to an Excel file
    void exportToXlsx(QTableView *tableView);

    // Method to get data from a specific row
    QList<QVariant> getRowData(QTableView *tableView, int row);

signals:
    void exportSuccess(const QString &filePath);
    void exportError(const QString &errorMessage);
    void loadEmpty();

private:
    QString getSaveFilePath();
};

#endif // EXPORTEXCEL_H
