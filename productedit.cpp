#include "productedit.h"
#include "myfunctions.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>



ProductEdit::ProductEdit(QObject *parent)
    : QAbstractTableModel(parent), rows(), columns(),
      db(DatabaseConnection::getInstance())
{
}

void ProductEdit::loadData(int serialNum) {
//    QSqlDatabase dbpe = QSqlDatabase::addDatabase("QSQLITE");
//    dbpe.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
//    if (!dbpe.open()) {
//        qDebug() << "Error: Unable to open database.";
//        return;
//    }

    QSqlQuery query(db.getConnection());
    query.prepare("SELECT ProductInfo.*, ProductSecInfo.GuarantyExp, ProductSecInfo.PurchaseDate, ProductSecInfo.Description "
                  "FROM ProductInfo "
                  "INNER JOIN ProductSecInfo ON ProductInfo.SerialNO = ProductSecInfo.SerialNO "
                  "WHERE ProductInfo.SerialNO = :serialNum");
    query.bindValue(":serialNum", serialNum);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QSqlRecord record = query.record();
    int numCols = record.count();

    rows.clear();
    columns.clear();

    while (query.next()) {
        QVector<QVariant> row;
        for (int i = 0; i < numCols; ++i) {
            row.append(query.value(i));
        }
        rows.append(row);
    }

    if (!rows.isEmpty()) {
        // Convert the first column using intToStr()
        for (int i = 0; i < rows.size(); ++i) {
            rows[i][0] = MyFunctions::intToStr(rows[i][0].toInt());
        }

        // Add custom column headers
        QStringList columnNames = {
            "Serial Number", "Product Name", "Invoice", "Anydesk Number", "Guaranty Exp", "Purchase Date", "Description"
        };

        for (const QString &name : columnNames) {
            columns.append(name);
        }
    }

//    qDebug() << "Rows loaded:" << rows.size();
//    qDebug() << "Columns loaded:" << columns.size();

    emit layoutChanged();
}

QVariant ProductEdit::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        return columns.at(section);
    } else {
        return QString::number(section + 1);
    }
}

bool ProductEdit::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
    if (orientation == Qt::Horizontal && role == Qt::EditRole) {
        if (section >= 0 && section < columns.size()) {
            columns[section] = value.toString();
            emit headerDataChanged(orientation, section, section);
            return true;
        }
    }
    return false;
}

QModelIndex ProductEdit::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent)) {
        return QModelIndex();
    }
    return createIndex(row, column);
}

QModelIndex ProductEdit::parent(const QModelIndex &index) const {
    return QModelIndex();
}

int ProductEdit::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return rows.size();
}

int ProductEdit::columnCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return columns.size();
}

bool ProductEdit::hasChildren(const QModelIndex &parent) const {
    return !parent.isValid() ? rowCount(parent) > 0 : false;
}

bool ProductEdit::canFetchMore(const QModelIndex &parent) const {
    return false;
}

void ProductEdit::fetchMore(const QModelIndex &parent) {
    // No additional data to fetch
}

QVariant ProductEdit::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    int row = index.row();
    int column = index.column();

    if (row >= rows.size() || column >= columns.size()) {
        qDebug() << "Index out of bounds: row" << row << "column" << column;
        return QVariant();
    }

    return rows.at(row).at(column);
}

bool ProductEdit::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (data(index, role) != value) {
        rows[index.row()][index.column()] = value;
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ProductEdit::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

bool ProductEdit::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(parent, row, row + count - 1);
    rows.insert(row, count, QVector<QVariant>(columnCount()));
    endInsertRows();
    return true;
}

bool ProductEdit::insertColumns(int column, int count, const QModelIndex &parent) {
    beginInsertColumns(parent, column, column + count - 1);
    for (auto &row : rows) {
        row.insert(column, count, QVariant());
    }
    endInsertColumns();
    return true;
}

bool ProductEdit::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row + count - 1);
    rows.remove(row, count);
    endRemoveRows();
    return true;
}

bool ProductEdit::removeColumns(int column, int count, const QModelIndex &parent) {
    beginRemoveColumns(parent, column, column + count - 1);
    for (auto &row : rows) {
        row.remove(column, count);
    }
    endRemoveColumns();
    return true;
}
