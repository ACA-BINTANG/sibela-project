#include "staf.h"
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <stdio.h>
#include <string.h>

// void createStaf(int lastIndex)
// {
//     FILE *stafDb = fopen(STAFPATH, "ab");

//     time_t now;
//     char ID[30];
//     localtime(&now);
//     parseID("KAR", lastIndex, &ID);

//     Staf newStaf = {.nama = "sukardi", .alamat = "jl. makan", .no_hp = "086920201202", .email = "atmin@gmail.com", .password = "admin123@", .role = FRONTDESK, .tanggal_lahir = parseDate("02-10-2007"), .tanggal_masuk = now};
//     strcpy(newStaf.id, ID);

//     fwrite(&newStaf, sizeof(Staf), 1, stafDb);
//     fclose(stafDb);
// }

Staf findStafbyEmail(char email[])
{
    FILE *stafDb = fopen(STAFPATH, "rb");
    Staf res;
    Staf foundRecord;

    while (fread(&foundRecord, sizeof(Staf), 1, stafDb) == 1)
    {
        if (strcmp(foundRecord.email, email) == 0)
        {
            res = foundRecord;
            break;
        }
    }

    fclose(stafDb);
    return res;
}

void findAllStaff(data *datas, SQLHDBC *dbConn)
{

    if (datas->nStaf > 0)
        return;

    SQLHSTMT stmt;
    SQLRETURN ret;
    SQLUSMALLINT rowStatus[100];

    SQLLEN rowsFetched = 0;
    SQLAllocHandle(SQL_HANDLE_STMT, *dbConn, &stmt);
    ret = SQLExecDirect(stmt, (SQLCHAR *)"SELECT * FROM staff", SQL_NTS);
    while (SQL_SUCCEEDED(ret = SQLFetch(stmt)))
    {
        printf("Successfully fetched %lld rows\n", rowsFetched);
        char dateBuff[50];
        int i = (int)rowsFetched;

        SQLGetData(stmt, 1, SQL_C_LONG,
                   &datas->staffs[i].id_num, sizeof(datas->staffs[i].id_num), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR,
                   &datas->staffs[i].id_staff, sizeof(datas->staffs[i].id_staff), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR,
                   &datas->staffs[i].role, sizeof(datas->staffs[i].role), NULL);
        SQLGetData(stmt, 4, SQL_C_CHAR,
                   &datas->staffs[i].nama, sizeof(datas->staffs[i].nama), NULL);
        SQLGetData(stmt, 5, SQL_C_CHAR,
                   dateBuff, sizeof(dateBuff), NULL);
        datas->staffs[rowsFetched].tanggal_lahir = parseDate(dateBuff);
        SQLGetData(stmt, 6, SQL_C_LONG,
                   &datas->staffs[i].tingkat, sizeof(datas->staffs[i].tingkat), NULL);
        SQLGetData(stmt, 7, SQL_C_CHAR,
                   dateBuff, sizeof(dateBuff), NULL);
        datas->staffs[rowsFetched].tanggal_masuk = parseDate(dateBuff);
        SQLGetData(stmt, 8, SQL_C_CHAR,
                   &datas->staffs[i].no_hp, sizeof(datas->staffs[i].no_hp), NULL);
        SQLGetData(stmt, 9, SQL_C_CHAR,
                   &datas->staffs[i].password, sizeof(datas->staffs[i].password), NULL);
        SQLGetData(stmt, 10, SQL_C_CHAR,
                   &datas->staffs[i].email, sizeof(datas->staffs[i].email), NULL);
        rowsFetched++;
    }
    datas->nStaf = rowsFetched;
    SQLFreeHandle(SQL_HANDLE_STMT, *dbConn);
}