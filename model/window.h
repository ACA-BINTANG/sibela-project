#ifndef window
#define window

#include "model.h"
#include "../types/dbTypes.h"
#include "../libs/headers/raylib.h"

typedef enum
{
    HOME,
    LOGIN,
    ADMINSTUDENT
} WINDOWS;

typedef struct
{
    char text[100];
    int charLen;
} InputParams;

typedef struct
{
    InputParams email;
    InputParams password;
    int activeInput;
} LoginScreen;

typedef struct
{
    Font *regular;
    Font *medium;
    Font *mediumItalic;
} FontStyles;

typedef struct
{
    char id[20];
    char nama[100];
    char role[20];
} user;

typedef struct
{
    WINDOWS currWindow;
    int shouldClose;
    int curPos;
    SQLHDBC *dbConn;
    FontStyles fontStyle;
    data datas;
    user authUser;
    LoginScreen loginData;
} windowModel;

#endif