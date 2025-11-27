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
        drawHeader();
        // drawLogin(window);
        break;
    case ADMINSTUDENT:
        break;
    }
}