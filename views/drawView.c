#include "drawView.h"

void drawRootView(windowModel *window)
{
    switch (window->currWindow)
    {
    case HOME:
        drawHeader();
        drawHome(window);
        break;
    case LOGIN:
        drawHeader();
        drawLogin(window);
        break;
    case ADMINSTUDENT:
        break;
    }
}