#ifndef JADWALPERTEMUAN_H
#define JADWALPERTEMUAN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

#include "../model/model.h"
// #include "../libs/utils.h"
#include "../types/dbTypes.h"
#include "../types/form.h"

void findAllJadwalPertemuan(data *datas, int *nPage, SQLHDBC *dbConn);

#endif