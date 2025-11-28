#include "libs/utils.h"
#include "model/model.h"
#include "model/window.h"
#include "update/update.h"
#include "views/drawView.h"
#include "data/initDb.h"
#include "data/staf.h"
#include <stdlib.h>

int main()
{
    InitWindow(1920, 1080, "Sibela");

    SetConfigFlags(FLAG_FULLSCREEN_MODE);

    Font poppinsMedium = LoadFontEx("assets/fonts/Poppins-Medium.ttf", 200, 0, 250);
    Font poppinsRegular = LoadFontEx("assets/fonts/Poppins-Regular.ttf", 200, 0, 250);
    Font poppinsMediumItalic = LoadFontEx("assets/fonts/Poppins-MediumItalic.ttf", 200, 0, 250);

    // initDatabases();
    SQLHDBC dbConn;
    // SQLHENV dbEnv;
    initSQLConn(&dbConn);
    // Staf *staffPtr = (Staf *)malloc(sizeof(Staf) * 100);
    // data datas = {.staffs = staffPtr};
    windowModel defaultWindow = (windowModel){
        .currWindow = LOGIN,
        .shouldClose = 0,
        .curPos = 0,
        .dbConn = &dbConn,
        .loginData = {.email = {.charLen = 0, .text = "\0"}, .activeInput = 0}};
    defaultWindow.fontStyle.medium = &poppinsMedium;
    defaultWindow.fontStyle.regular = &poppinsRegular;
    defaultWindow.fontStyle.mediumItalic = &poppinsMediumItalic;

    // findAllStaff(&defaultWindow.datas, defaultWindow.dbConn);
    SetTargetFPS(120);

    while (!WindowShouldClose() && !defaultWindow.shouldClose)
    {
        updateView(&defaultWindow);
        BeginDrawing();
        drawRootView(&defaultWindow);
        EndDrawing();
    }

    disconnectDb(&dbConn);
    UnloadFont(poppinsMedium);
    UnloadFont(poppinsRegular);
    UnloadFont(poppinsMediumItalic);
    // free(staffPtr);
    CloseWindow();

    return 0;
}
