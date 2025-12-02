#ifndef dbTypes
#define dbTypes

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <time.h>
// #include "../model/model.h"

typedef enum
{
    X,
    XI,
    XII
} tingkat_enum;
typedef enum
{
    MANAJER,
    FRONTDESK
} staf_role_enum;

typedef struct
{
    char id[30];
    char nama[50];
    time_t tanggal_lahir;
    tingkat_enum tingkat;
    time_t tanggal_masuk;
    char no_hp[20];
    char alamat[150];
} Murid;

typedef struct
{
    int id_num;
    char id_staff[30];
    char role[20];
    char nama[255];
    time_t tanggal_lahir;
    time_t tanggal_masuk;
    char no_hp[20];
    char password[100];
    char email[100];
} Staf;

// typedef struct
//     {
//         SQLINTEGER id_num;
//         SQLVARCHAR id_staff;
//         SQLVARCHAR role;
//         SQLVARCHAR nama;
//         SQLDATE tanggal_lahir;
//         SQLINTEGER tingat;
//         SQLDATE tanggal_masuk;
//         SQLVARCHAR no_hp;
//         SQLVARCHAR password;
//     } stafSQL;

#endif