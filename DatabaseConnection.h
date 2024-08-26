#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QDebug>


class DatabaseConnection {
public:
    static DatabaseConnection& getInstance() {
        static DatabaseConnection instance; // Guaranteed to be destroyed.
        return instance;                    // Instantiated on first use.
    }

    QSqlDatabase& getConnection() {
        return db;
    }

    bool openDatabase(const QString& dbName) {
        if (db.isOpen()) {
            return true; // Already open
        }
        else{
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
            db.open();
        }

//        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbName);

        if (!db.open()) {
            qDebug() << "Failed to open database:" << db.lastError().text();
            return false;
        }
        return true;
    }

    void closeDatabase() {
        if (db.isOpen()) {
            db.close();
            QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        }
    }

private:
    DatabaseConnection() {} // Private constructor
    ~DatabaseConnection() {
        closeDatabase();
    }

    DatabaseConnection(DatabaseConnection const&) = delete; // Prevent copies
    void operator=(DatabaseConnection const&) = delete;    // Prevent assignments

    QSqlDatabase db;
};

#endif // DATABASECONNECTION_H
