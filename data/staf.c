#include "staf.h"

void createStaf(int lastIndex)
{
    FILE *stafDb = fopen(STAFPATH, "ab");

    time_t now;
    char ID[30];
    localtime(&now);
    parseID("KAR", lastIndex, &ID);

    Staf newStaf = {.nama = "sukardi", .alamat = "jl. makan", .no_hp = "086920201202", .email = "atmin@gmail.com", .password = "admin123@", .role = FRONTDESK, .tanggal_lahir = parseDate("02-10-2007"), .tanggal_masuk = now};
    strcpy(newStaf.id, ID);

    fwrite(&newStaf, sizeof(Staf), 1, stafDb);
    fclose(stafDb);
}

Staf findStafbyEmail(char email[])
{
    FILE *stafDb = fopen(STAFPATH, "rb");
    Staf res;
    Staf foundRecord;

    while (fread(&foundRecord, sizeof(Staf), 1, stafDb) == 1)
    {
        if (strcmp(foundRecord.email, email) == 0)
        {
            res = foundRecord;
            break;
        }
    }

    fclose(stafDb);
    return res;
}