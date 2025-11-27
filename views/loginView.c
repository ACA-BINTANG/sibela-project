#include "loginView.h"

void drawLogin(windowModel *windowM)
{

    // int key = GetCharPressed();

    // Check if more characters have been pressed on the same frame

    const int screenWidth = 1920;
    const int screenHeight = 1080;
    // Rectangle textBox = {screenWidth / 2.0f - 100, 180, 225, 50};
    Rectangle textBox = {
        screenWidth / 2.0f - 300,
        180,
        600,
        63,
    };
    Rectangle textBoxPass = {
        screenWidth / 2.0f - 300,
        180 + 63 + 40,
        600,
        63,
    };
    // DrawRectangleRec(textBox, LIGHTGRAY);
    DrawRectangleRoundedLines(textBox, 0.3, 0, windowM->loginData.activeInput == 0 ? PRIMARY : SIBELAWHITE);
    DrawTextEx(*windowM->font, windowM->loginData.email.text, (Vector2){(int)textBox.x + 5, (int)textBox.y + 8}, 40, 0, SIBELAWHITE);
    DrawText(TextFormat("INPUT CHARS: %i/%i", windowM->loginData.email.charLen, 100), 315, 250, 20, DARKGRAY);
    DrawRectangleRoundedLines(textBoxPass, 0.3, 0, windowM->loginData.activeInput == 1 ? PRIMARY : SIBELAWHITE);
    DrawTextEx(*windowM->font, windowM->loginData.password.text, (Vector2){(int)textBoxPass.x + 5, (int)textBoxPass.y + 8}, 40, 0, SIBELAWHITE);
}