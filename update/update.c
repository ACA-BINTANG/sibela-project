#include "update.h"

void updateView(windowModel *window)
{
    int ch = getch();
    switch (ch)
    {
    case 'q':
        window->shouldClose = 1;
        break;
    }
    switch (window->currWindow)
    {
    case HOME:
        switch (ch)
        {
        case 'w':
        case KEY_UP:
            window->curPos -= 1;
            break;
        case 's':
        case KEY_DOWN:
            window->curPos += 1;
            break;
        case '2':
            window->currWindow = ADMINSTUDENT;
            break;

        case ' ':
        case '\n':
            window->currWindow = window->curPos;
            window->curPos = 0;
            break;
        }
        break;
    case LOGIN:

        break;
    }
}