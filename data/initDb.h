#ifndef initDb
#define initDb

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
// #include "../libs/headers/raylib.h"
#include "../types/dbTypes.h"
#include "../model/model.h"
#include "../libs/utils.h"
// #include "../components/header.h"

#define MURIDPATH "dat/murid.dat"
#define STAFPATH "dat/staf.dat"

void initDatabases(void);

#endif