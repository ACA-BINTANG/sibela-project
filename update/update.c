#include "update.h"

void updateView(windowModel *windowM)
{
    int ch = GetKeyPressed();
    switch (ch)
    {
    case KEY_Q:
        windowM->shouldClose = 1;
        break;
    }
    switch (windowM->currWindow)
    {
    case HOME:
        switch (ch)
        {
        case KEY_W:
        case KEY_UP:
            windowM->curPos -= 1;
            break;
        case KEY_S:
        case KEY_DOWN:
            windowM->curPos += 1;
            break;
        case KEY_KP_2:
            windowM->currWindow = ADMINSTUDENT;
            break;

        case KEY_SPACE:
        case KEY_ENTER:
            windowM->currWindow = windowM->curPos;
            windowM->curPos = 0;
            break;
        }
        break;
    case LOGIN:

        break;
    }
}