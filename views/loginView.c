#include "loginView.h"

void drawLogin(windowModel *windowM)
{

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Rectangle textBox = {
        screenWidth / 2.0f - 300,
        180,
        600,
        63,
    };
    Rectangle textBoxPass = {
        screenWidth / 2.0f - 300,
        180 + 63 + 80,
        600,
        63,
    };
    Rectangle buttonBox = {
        screenWidth / 2.0f - 80,
        180 + 63 + 180,
        160,
        67,
    };

    DrawTextEx(*windowM->fontStyle.medium, "Email", (Vector2){(int)textBox.x, (int)textBox.y - 44}, 40, 0, SIBELAWHITE);
    DrawRectangleRoundedLines(textBox, 0.3, 0, windowM->loginData.activeInput == 0 ? PRIMARY : SIBELAWHITE);
    DrawTextEx(*windowM->fontStyle.regular, windowM->loginData.email.text, (Vector2){(int)textBox.x + 5, (int)textBox.y + 8}, 40, 0, SIBELAWHITE);
    DrawTextEx(*windowM->fontStyle.medium, "Password", (Vector2){(int)textBoxPass.x, (int)textBoxPass.y - 44}, 40, 0, SIBELAWHITE);
    DrawRectangleRoundedLines(textBoxPass, 0.3, 0, windowM->loginData.activeInput == 1 ? PRIMARY : SIBELAWHITE);
    DrawTextEx(*windowM->fontStyle.regular, windowM->loginData.password.text, (Vector2){(int)textBoxPass.x + 5, (int)textBoxPass.y + 8}, 40, 0, SIBELAWHITE);
    if (windowM->loginData.activeInput == 2)
    {
        DrawRectangleRounded(buttonBox, 0.3, 0, PRIMARY);
    }
    else
        DrawRectangleRoundedLines(buttonBox, 0.3, 0, SIBELAWHITE);
    DrawTextEx(*windowM->fontStyle.medium, "Login", (Vector2){(int)buttonBox.x + MeasureTextEx(*windowM->fontStyle.medium, "Login", 40, 0).x / 2, (int)buttonBox.y + MeasureTextEx(*windowM->fontStyle.medium, "Login", 40, 0).y / 2 - 8}, 40, 0, SIBELAWHITE);
}