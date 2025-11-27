#include "model.h"
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <stdio.h>

void initSQLConn(SQLHDBC *dbConn)
{
    SQLHENV env;
    SQLHSTMT stmt;
    SQLRETURN ret;
    SQLSMALLINT columns;
    char dsn[120];

    readDBDsn(dsn);
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, env, dbConn);
    ret = SQLDriverConnect(*dbConn, NULL, dsn, SQL_NTS,
                           NULL, 0, NULL, SQL_DRIVER_COMPLETE);

    if (SQL_SUCCEEDED(ret))
    {
        printf("Connected to SQL Server!\n");
    }
    else
    {
        printf("Gagal connect ser!\n");
    }
}

void disconnectDb(SQLHDBC *dbConn)
{
    SQLDisconnect(*dbConn);
}

void readDBDsn(char target[])
{
    FILE *dsnFile;

    dsnFile = fopen(".env", "r");
    fscanf(dsnFile, "%s", target);

    fclose(dsnFile);
}