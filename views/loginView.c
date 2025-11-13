#include "loginView.h"

void drawLogin(windowModel *window)
{
    WINDOW *loginWindow = newwin(10, 70, LINES - 14, COLS / 2 - 35);
    wborder(loginWindow, '|', '|', '-', '-', '+', '+', '+', '+');
    FIELD *loginInput[5];
    FORM *loginForm;
    int centerCol = COLS / 2;
    int centerRow = LINES - 12;

    loginInput[0] = new_field(1, 8, 0, 0, 0, 0);
    loginInput[1] = new_field(1, 40, 0, 9, 0, 0);
    loginInput[2] = new_field(1, 8, 2, 0, 0, 0);
    loginInput[3] = new_field(1, 40, 2, 9, 0, 0);
    loginInput[4] = NULL;

    set_field_buffer(loginInput[0], 0, "Email");
    set_field_buffer(loginInput[1], 0, "");
    set_field_buffer(loginInput[2], 0, "Password");
    set_field_buffer(loginInput[3], 0, "");

    set_field_opts(loginInput[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
    set_field_opts(loginInput[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
    set_field_opts(loginInput[2], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
    set_field_opts(loginInput[3], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
    set_field_back(loginInput[1], A_UNDERLINE);
    set_field_back(loginInput[3], A_UNDERLINE);

    loginForm = new_form(loginInput);
    set_form_win(loginForm, loginWindow);
    set_form_sub(loginForm, derwin(loginWindow, 18, 76, 1, 1));
    post_form(loginForm);

    refresh();
    wrefresh(loginWindow);
    wrefresh(stdscr);
}