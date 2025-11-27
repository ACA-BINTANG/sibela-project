#include "drawView.h"

void drawRootView(windowModel *windowM)
{
    ClearBackground(TERTIARY);
    switch (windowM->currWindow)
    {
    case HOME:
        drawHeader();
        drawHome(windowM);
        break;
    case LOGIN:
        // drawHeader();
        drawLogin(windowM);
        break;
    case ADMINSTUDENT:
        break;
    }
}