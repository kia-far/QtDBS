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
    : QAbstractTableModel(parent), m_searchParam("SerialNum"), m_searchText(""), rows(), columns(),
      db(DatabaseConnection::getInstance())
{
    loadData(m_searchParam, m_searchText);
}
void ProxyView::setSearchParameters(const QString &searchParam, const QString &searchText)
{
    m_searchParam = searchParam;
    m_searchText = searchText;
    loadData(m_searchParam,m_searchText);
}
void ProxyView::loadData(QString searchParam,QString searchText) {
//    QSqlDatabase dbpv = QSqlDatabase::addDatabase("QSQLITE");
//    dbpv.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
//    if (!dbpv.open()) {
//        qDebug() << "Error: Unable to open database.";
//        return;
//    }
//    QString res;
//    if(searchParam=="SerialNum"){/*searchText=MyFunctions::reverseSN(searchText);*/
//        if(searchText==""){res = "SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
//        else if(searchText.at(0).isLetter()){
//            if(searchText.at(0)=="B"||searchText.at(0)=="N"||searchText.at(0)=="S"){
//                res="SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '"+MyFunctions::reverseSN(searchText)+"%' OR "+searchParam+" LIKE '___"+MyFunctions ::smallSN(searchText)+"%'";
//            }
//            else{res = "SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '___"+MyFunctions ::smallSN(searchText)+"%'";}
//        }
//        else{
//            if(searchText.length()<3) {res="SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '_"+searchText+"%' OR "+searchParam+" LIKE '_____%"+searchText+"%'";}
//            else{res = "SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '_____%"+searchText+"%'";}}
//    }
//    else {res = "SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
    QSqlQuery query(db.getConnection());
    QString res;
    QString context;
    QString space;
    if (searchParam=="SerialNum"){
        if (searchText==""){res = "SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
        else{
            if(searchText.at(0).toUpper()=="B"||searchText.at(0).toUpper()=="S"||searchText.at(0).toUpper()=="N"){res = "SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '"+MyFunctions::reverseSN( searchText)+"%' OR "+searchParam+" LIKE '___"+MyFunctions ::smallSN(searchText)+"%'";}
            else{
                context = MyFunctions::smallSN(searchText);
                space = MyFunctions::querySolver();
                if(!(space=="-1")){res = "SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '"+space+context+"%'";
                qDebug()<<"LIKE debug try '"+space+context+"%'";}
                else{
                    res = "SELECT * FROM DeviceInfo WHERE (("+searchParam+" LIKE '_%"+context+"%______') OR ("+searchParam+" LIKE '_____%"+context+"%'))";
                                    qDebug()<<"LIKE debug try '"+space+context+"%'";
                }
            }
        }
    }
    else {res = "SELECT * FROM DeviceInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}



    query.exec(res);
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
            rows[i][0] =  MyFunctions::intToStr(rows[i][0].toInt());
        }

        // Process the last column into 14-bit binary string and add new columns
        for (int i = 0; i < rows.size(); ++i) {
            QVector<QVariant> row = rows[i];
            QString binaryStr = intToBinary(row[8].toInt()).rightJustified(14, '0'); // Ensure 14-bit binary
            row.remove(8); // Remove the original 9th column
            for (QChar bit : binaryStr) {
                row.append(bit);
            }
            rows[i] = row; // Update the row with the new columns
        }

        // Add custom column headers
        // Replace these names with your desired names
        QStringList originalColumnNames = {
            "SerialNumber", "Cell", "Power", "Charger", "Battery", "ACCBoard", "MotherBoard", "Ram"
        };
        QStringList binaryColumnNames = {
            "Pactos USB", "Metec USB", "USB Cable", "Bag", "زیر کیبرد", "Navid",
            "Pacjaws", "سامانه", "Extended Stereo Cable", "Lan Cable", "Braille Guide", "2 Mono Stereo",
            "HDMI Cable", "Instruction DVD"
        };

        // Add original column names
        for (const QString &name : originalColumnNames) {
            columns.append(name);
        }

        // Add binary column names
        for (const QString &name : binaryColumnNames) {
            columns.append(name);
        }
    }

    qDebug() << "Rows loaded:" << rows.size();
    qDebug() << "Columns loaded:" << columns.size();

    emit layoutChanged();
}



QVariant ProxyView::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        return columns.at(section);
    } else {
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
