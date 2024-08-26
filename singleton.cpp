#include "singleton.h"

singleton::singleton(QObject *parent)
    : QAbstractItemModel(parent)
{
}

//QSqlDatabase db(){
//    QSqlDatabase db;
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
//    return db;
//}
/*
class S
{
    public:
        static S& getInstance()
        {
            static S    instance;
            return instance;
        }
    private:
        S() {}
        S(S const&);              // Don't Implement.
        void operator=(S const&); // Don't implement
 };*/
