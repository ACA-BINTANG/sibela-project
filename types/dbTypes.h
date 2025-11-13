#ifndef dbTypes
#define dbTypes

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>
#include "../model/model.h"
#include "../libs/utils.h"
#include "../components/header.h"

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
    char id[30];
    char nama[50];
    time_t tanggal_lahir;
    staf_role_enum role;
    char email[100];
    char password[100];
    time_t tanggal_masuk;
    char no_hp[20];
    char alamat[150];
} Staf;

#endif