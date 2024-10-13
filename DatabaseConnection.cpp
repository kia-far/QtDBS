#include "DatabaseConnection.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

DatabaseConnection::DatabaseConnection() {
    QString adr = qApp->applicationDirPath();
    QString dbPathFile = adr+"/DBPath";

    QFile file(dbPathFile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString dbPath = in.readLine();  // Read the database path from the file
        file.close();

        if (!dbPath.isEmpty()) {
            openDatabase(dbPath);  // Open the database using the path from the file
        } else {
            qDebug() << "Database path file is empty!";
        }
    } else {
        qDebug() << "Failed to open database path file:" << file.errorString();
    }
}

DatabaseConnection::~DatabaseConnection() {
    closeDatabase();
}

DatabaseConnection& DatabaseConnection::getInstance() {
    static DatabaseConnection instance; // Guaranteed to be destroyed.
    return instance;                    // Instantiated on first use.
}

bool DatabaseConnection::openDatabase(const QString &dbName) {
    if (db.isOpen()) {
        return true; // Already open
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbName);

        if (!db.open()) {
            qDebug() << "Failed to open database:" << db.lastError().text();
            return false;
        }
    }
    return true;
}

void DatabaseConnection::closeDatabase() {
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    }
}

QSqlError DatabaseConnection::lastError() const {
    return db.lastError();
}
