// #include <QFile>
// #include <QTextStream>
// #include <QFileDialog>
// #include <qtableview.h>
// #include <QMessageBox>

// void exportToCSV(QTableView *tableView) {
//     QString filePath = QFileDialog::getSaveFileName(nullptr, "Save as CSV File", "", "CSV Files (*.csv)");
//     if (filePath.isEmpty()) return;

//     QFile file(filePath);
//     if (file.open(QIODevice::WriteOnly)) {
//         QTextStream stream(&file);
//         QAbstractItemModel *model = tableView->model();

//         // Write headers
//         for (int col = 0; col < model->columnCount(); ++col) {
//             stream << model->headerData(col, Qt::Horizontal).toString();
//             if (col < model->columnCount() - 1)
//                 stream << ",";
//         }
//         stream << "\n";

//         // Write data
//         for (int row = 0; row < model->rowCount(); ++row) {
//             for (int col = 0; col < model->columnCount(); ++col) {
//                 stream << model->data(model->index(row, col)).toString();
//                 if (col < model->columnCount() - 1)
//                     stream << ",";
//             }
//             stream << "\n";
//         }
//         file.close();
//         QMessageBox::information(nullptr, "Export Complete", "Data exported successfully to " + filePath);
//     } else {
//         QMessageBox::warning(nullptr, "Error", "Could not open file for writing");
//     }
// }
