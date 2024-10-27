#include "exporttoexcel.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QAbstractItemModel>
#include "xlsxdocument.h"

ExportExcel::ExportExcel(QObject *parent) : QObject(parent) {}

void ExportExcel::exportToXlsx(QTableView *tableView) {
    // Get the model from the table view
    QAbstractItemModel *model = tableView->model();
    if (!model) {
        emit exportError("No model found in the table view.");
        return;
    }

    // Get file path to save the Excel file
    QString filePath = getSaveFilePath();
    if (filePath.isEmpty()) {
        emit exportError("No file selected for export.");
        return;
    }

    // Create an xlsx document
    QXlsx::Document xlsx;

    // Write headers to the first row
    for (int col = 0; col < model->columnCount(); ++col) {
        QString headerText = model->headerData(col, Qt::Horizontal).toString();
        xlsx.write(1, col + 1, headerText); // Headers in the first row
    }

    // Write data rows
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QVariant cellData = model->data(model->index(row, col));
            xlsx.write(row + 2, col + 1, cellData); // Data starts from the second row
        }
    }

    // Save the document and check success
    if (xlsx.saveAs(filePath)) {
        emit exportSuccess(filePath);
        QMessageBox::information(nullptr, "Export", "Data exported successfully to " + filePath);
    } else {
        emit exportError("Failed to save the file.");
        QMessageBox::warning(nullptr, "Export", "Failed to save the file.");
    }
}

QString ExportExcel::getSaveFilePath() {
    // Show file dialog to get the desired file path for the Excel file
    return QFileDialog::getSaveFileName(nullptr, "Save as Excel", "", "Excel files (*.xlsx)");
}
