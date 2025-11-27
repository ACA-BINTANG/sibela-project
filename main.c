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

    Font poppins = LoadFontEx("assets/fonts/Poppins-Medium.ttf", 120, 0, 250);

    // initDatabases();
    SQLHDBC dbConn;
    // SQLHENV dbEnv;
    // initSQLConn(&dbConn);
    // Staf *staffPtr = (Staf *)malloc(sizeof(Staf) * 100);
    // data datas = {.staffs = staffPtr};
    windowModel defaultWindow = (windowModel){
        .currWindow = HOME,
        .shouldClose = 0,
        .curPos = 0,
        .dbConn = &dbConn,
    };
    defaultWindow.font = &poppins;

    // findAllStaff(&defaultWindow.datas, defaultWindow.dbConn);

    while (!WindowShouldClose() && !defaultWindow.shouldClose)
    {
        BeginDrawing();
        drawRootView(&defaultWindow);
        updateView(&defaultWindow);
        EndDrawing();
    }

    disconnectDb(&dbConn);
    UnloadFont(poppins);
    // free(staffPtr);
    CloseWindow();

    return 0;
}
