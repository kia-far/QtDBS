#include "proxyview.h"
#include "myfunctions.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>



QString intToBinary(int number) {
    return QString::number(number, 2).rightJustified(14, '0');
}

ProxyView::ProxyView(QObject *parent)
    : QAbstractTableModel(parent), m_searchParam("SerialNum"), m_searchText(""), rows(), columns(),currentDevice(""),
      db(DatabaseConnection::getInstance())
{
    loadData(currentDevice,m_searchParam, m_searchText);
}
void ProxyView::setSearchParameters(QString device ,const QString &searchParam, const QString &searchText)
{
    m_searchParam = searchParam;
    m_searchText = searchText;
    currentDevice = device;
    loadData(currentDevice,m_searchParam,m_searchText);
}

void ProxyView::sort(int column, Qt::SortOrder order) {
    if (column < 0 || column >= columnCount()) {
        return;  // Invalid column
    }

    // Lambda function to compare rows based on the given column
    std::sort(rows.begin(), rows.end(), [column, order](const QVector<QVariant> &a, const QVector<QVariant> &b) {
        if (order == Qt::AscendingOrder) {
            return a[column] < b[column];  // Ascending order comparison
        } else {
            return a[column] > b[column];  // Descending order comparison
        }
    });

    emit dataChanged(index(0, 0), index(rowCount() - 1, columnCount() - 1));
    emit layoutChanged();  // Notify view about the sorted data
}

void ProxyView::loadData(QString device ,QString searchParam,QString searchText) {
    QSqlQuery query(db.getConnection());
    QString res;
    QString context;
    QString space;
    if (searchParam=="SerialNumber"){
        res = MyFunctions::searchHandler("*",device,searchParam,searchText);

    }
    else {res = "SELECT * FROM "+ device +" WHERE "+searchParam+" LIKE '%"+searchText+"%'";}

    QStringList columnsToExclude = {/*"column_name_1", "column_name_2", "column_name_3"*/};

    query.exec(res);
//    qDebug() << res;
    QSqlRecord record = query.record();
    int numCols = record.count();

    rows.clear();
    columns.clear();
//_____________________________________________________________________________________________________________
    for (int i = 0; i < numCols; ++i) {
        QString columnName = record.fieldName(i);
//        if (!columnsToExclude.contains(columnName)) {
            columns.append(columnName);
//        }
    }
    columns.append("تاریخ خرید");
    columns.append("تاریخ انقضای گارانتی");

    while (query.next()) {
        QVector<QVariant> row;
        for (int i = 0; i < numCols; ++i) {
            row.append(query.value(i));
        }
        QString serialNo = query.value(record.indexOf("SerialNumber")).toString();
        QSqlQuery dateQuery(db.getConnection());
        dateQuery.prepare("SELECT PurchaseDate, GuarantyExp FROM ProductSecInfo WHERE SerialNO = :serialNo");
        dateQuery.bindValue(":serialNo", serialNo);
        dateQuery.exec();

        if (dateQuery.next()) {
            row.append(dateQuery.value("PurchaseDate"));
            row.append(dateQuery.value("GuarantyExp")); // Append the GuarantyExp value
        } else {
            row.append(QVariant());  // Append null for PurchaseDate if not found
            row.append(QVariant());  // Append null for GuarantyExp if not found
        }

        rows.append(row);
    }

    if (!rows.isEmpty()) {
        for (int i = 0; i < rows.size(); ++i) {
            rows[i][0] = MyFunctions::intToStr(rows[i][0].toUInt());
        }
    }

    int descriptionIndex = columns.indexOf("description");
        if (descriptionIndex != -1) {
            // Move the "description" column to the end of the columns list
            QString descriptionColumn = columns.takeAt(descriptionIndex);
            columns.append(descriptionColumn);
            for (auto &row : rows) {
                QVariant descriptionData = row.takeAt(descriptionIndex);
                row.append(descriptionData);
            }
        }


    emit layoutChanged();
}





QVariant ProxyView::headerData(int section, Qt::Orientation orientation, int role) const {
    QStringList customColumnNames = QStringList({"شماره سریال", "نام مشتری", "متعلقات"});

    // Check if role is for display
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    // Handle horizontal headers
    if (orientation == Qt::Horizontal) {
        // For the first few columns, use custom names
        if (section < customColumnNames.size()) {
            return customColumnNames.at(section);
        }

        // If the column is "description", return a custom header label
        int descriptionIndex = columns.indexOf("description");
        if (descriptionIndex != -1 && section == descriptionIndex) {
            return "توضیحات";  // Your custom label for "description"
        }

        // For all other columns, use the column names from the database
        int adjustedIndex = section - customColumnNames.size();
        if (adjustedIndex >= 0 && adjustedIndex < columns.size()) {
            return columns.at(adjustedIndex + customColumnNames.size());
        } else {
            return QVariant();  // Invalid section or out of bounds
        }
    } else {
        // For vertical headers (row numbers), return the section number
        return QString::number(section + 1);
    }
}



bool ProxyView::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
    if (orientation == Qt::Horizontal && role == Qt::EditRole) {
        if (section >= 0 && section < columns.size()) {
            columns[section] = value.toString();
            emit headerDataChanged(orientation, section, section);
            return true;
        }
    }
    return false;
}

QModelIndex ProxyView::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent)) {
        return QModelIndex();
    }
    return createIndex(row, column);
}

QModelIndex ProxyView::parent(const QModelIndex &index) const {
    return QModelIndex();
}

int ProxyView::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return rows.size();
}

int ProxyView::columnCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return columns.size();
}

bool ProxyView::hasChildren(const QModelIndex &parent) const {
    return !parent.isValid() ? rowCount(parent) > 0 : false;
}

//bool ProxyView::canFetchMore(const QModelIndex &parent) const {
//    return false;
//}

void ProxyView::fetchMore(const QModelIndex &parent) {
    // No additional data to fetch
}

QVariant ProxyView::data(const QModelIndex &index, int role) const {
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

bool ProxyView::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (data(index, role) != value) {
        rows[index.row()][index.column()] = value;
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ProxyView::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

bool ProxyView::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(parent, row, row + count - 1);
    rows.insert(row, count, QVector<QVariant>(columnCount()));
    endInsertRows();
    return true;
}

bool ProxyView::insertColumns(int column, int count, const QModelIndex &parent) {
    beginInsertColumns(parent, column, column + count - 1);
    for (auto &row : rows) {
        row.insert(column, count, QVariant());
    }
    endInsertColumns();
    return true;
}

bool ProxyView::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row + count - 1);
    rows.remove(row, count);
    endRemoveRows();
    return true;
}

bool ProxyView::removeColumns(int column, int count, const QModelIndex &parent) {
    beginRemoveColumns(parent, column, column + count - 1);
    for (auto &row : rows) {
        row.remove(column, count);
    }
    endRemoveColumns();
    return true;
}
