#ifndef model
#define model

typedef void *SQLHANDLE;
typedef SQLHANDLE SQLHDBC;
typedef short SQLSMALLINT;
#include "../types/dbTypes.h"
typedef struct
{
    Staf staffs[100];
    SQLSMALLINT nStaf;
} data;

void readDBDsn(char target[]);
void initSQLConn(SQLHDBC *dbConn);
void disconnectDb(SQLHDBC *dbConn);

#endif