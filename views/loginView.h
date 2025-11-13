#ifndef loginView
#define loginView

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <ncurses.h>
#include <form.h>
#include "../model/model.h"
#include "../libs/utils.h"
#include "../components/header.h"
#include "../data/staf.h"

void drawLogin(windowModel *window);

#endif