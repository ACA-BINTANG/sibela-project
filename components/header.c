#include "header.h"

void drawHeader(windowModel *windowM)
{
    DrawTextureEx(windowM->images.logo, (Vector2){1920 / 2 - windowM->images.logo.width * 0.7f / 2, 100}, 0, 0.7, SIBELAWHITE);
}