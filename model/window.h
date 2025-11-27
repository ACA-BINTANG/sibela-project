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
    WINDOWS currWindow;
    int shouldClose;
    int curPos;
    SQLHDBC *dbConn;
    Font *font;
    data datas;
    LoginScreen loginData;
} windowModel;

#endif