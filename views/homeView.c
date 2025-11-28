#include "homeView.h"

typedef struct
{
    char nama[50];
    int selected;
} Menus;

void drawHome(windowModel *windowM)
{
    Menus opsi[] = {
        (Menus){"Staff", 1},
        (Menus){"Murid", 0},
        (Menus){"Pembayaran", 0},
        (Menus){"Kelas", 0},
        (Menus){"Pertemuan", 0},
        (Menus){"Pengajar", 0},
        (Menus){"Mata pelajaran", 0},
    };
    int gap = 50;
    int startX = 35;
    int startY = 375;

    // DrawTextEx(*windowM->font, "ID\taw\tyes", (Vector2){1920 / 2, 1080 / 2 - 100}, 120, 0, WHITE);
    DrawRectangle(0, 0, 300, 1080, SECONDARY);
    DrawTextEx(*windowM->fontStyle.mediumItalic, "SIBELA", (Vector2){50, 64}, 80, 0, SIBELAWHITE);

    for (int i = 0; i < sizeof(opsi) / sizeof(opsi[0]); i++)
    {
        if (i == windowM->curPos)
            DrawRectangleRounded((Rectangle){.x = startX - 8, .y = startY + i * gap - 7, .width = MeasureTextEx(*windowM->fontStyle.medium, opsi[i].nama, 32, 0).x + 20, .height = 44}, 0.2, 0, SIBELAWHITE);
        DrawTextEx(*windowM->fontStyle.medium, opsi[i].nama, (Vector2){startX, startY + i * gap}, 32, 0, i == windowM->curPos ? SECONDARY : SIBELAWHITE);
    }
    DrawTextEx(*windowM->fontStyle.medium, TextFormat("Halo, %s!", windowM->authUser.nama), (Vector2){1920 / 2, 300}, 40, 0, SIBELAWHITE);
}
