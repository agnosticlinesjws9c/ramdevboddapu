#ifndef QQTSQLDEFINE_H
#define QQTSQLDEFINE_H

#include <QWidget>
#include <QUuid>
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QMutex>
#include <QDateTime>
#include <QTextStream>
#include <QElapsedTimer>
#include <QDesktopWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <qqt-local.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum
{
    Auth_Id = 0,
    Auth_Name,
    Auth_Passwd,
    Auth_Authrity,
    Auth_Creater,
    Auth_CreateTime,
    Auth_Comment,
};

enum
{
    Authority_Id = 0,
    Authority_Level,
};

enum
{
    Auth_Admin = 0,
    Auth_Manager,
    Auth_User,
    Auth_Max
};

enum
{
    Event_ID,
    Event_Name,
    Event_Time,
    Event_User,
    Event_Content,
};

#define DB_TYPE "QSQLITE"
#define DB_PINYIN "PinYin.db"
#define DB_MANAGER "Manager.db"
#define DB_EVENT "SysEvent.db"

#define TABLE_USERINFO "User"
#define TABLE_AUTHORITY "Authority"
#define TABLE_EVENT "Event"

extern QSqlDatabase managerDB;

#ifdef __cplusplus
}
#endif  /* __cplusplus */

typedef QSqlDatabase QQtSqlDatabaseConnection;

QQTSHARED_EXPORT QSqlDatabase newDatabaseConnection();

/*已经将数据库打开，不必重复打开*/
QQTSHARED_EXPORT void setDatabaseName ( QSqlDatabase& dbinst, QString dbName );
//=setDatabaseName
QQTSHARED_EXPORT void useDatabase ( QSqlDatabase& dbinst, QString dbName );

QQTSHARED_EXPORT void openDatabase ( QSqlDatabase& dbinst );
QQTSHARED_EXPORT void closeDatabase ( QSqlDatabase& dbinst );

QQTSHARED_EXPORT void deleteDatabaseConnection ( QString connectionName );
QQTSHARED_EXPORT void deleteDatabaseConnection ( QSqlDatabase& dbinst );

#endif // QQTSQLDEFINE_H
