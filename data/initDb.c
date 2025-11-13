#include "initDb.h"

void initDatabases()
{
    FILE *murid = fopen(MURIDPATH, "ab");

    if (murid == NULL)
        murid = fopen(MURIDPATH, "wb");

    FILE *staf = fopen(STAFPATH, "ab");
    if (staf == NULL)
        staf = fopen(STAFPATH, "wb");

    fclose(murid);
    fclose(staf);
}