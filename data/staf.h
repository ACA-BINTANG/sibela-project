#ifndef staf
#define staf

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <ncurses.h>
#include "initDb.h"
#include "../model/model.h"
#include "../libs/utils.h"
#include "../types/dbTypes.h"
#include "../components/header.h"

void createStaf(int lastIndex);
Staf findStafbyEmail(char email[]);

#endif