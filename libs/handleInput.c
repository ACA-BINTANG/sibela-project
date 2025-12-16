#include "handleInput.h"

void handleInput(int *ch, int *destLen, char destText[], InputType fieldType, int maxLen, mutationFunc func, InputField fields[], fetcherFunc dataFetcher, windowModel *windowM)
{

    switch (fieldType)
    {
    case LONGTEXTINPUT:
    case TEXTINPUT:
        *ch = GetCharPressed();
        while (*ch > 0)
        {
            if ((*ch >= 32) && (*ch <= 125) && (*destLen < maxLen))
            {
                destText[*destLen] = (char)*ch;
                destText[(*destLen) + 1] = '\0';
                (*destLen)++;
            }

            *ch = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            (*destLen)--;
            if ((*destLen) < 0)
                (*destLen) = 0;
            destText[*destLen] = '\0';
        }
        break;
    case NUMERICINPUT:
        *ch = GetCharPressed();
        while (*ch > 0)
        {
            if ((*ch >= '0') && (*ch <= '9') && (*destLen < maxLen))
            {
                destText[*destLen] = (char)*ch;
                destText[(*destLen) + 1] = '\0';
                (*destLen)++;
            }

            *ch = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            (*destLen)--;
            if ((*destLen) < 0)
                (*destLen) = 0;
            destText[*destLen] = '\0';
        }
        break;
    case BUTTONINPUT:
        switch (*ch)
        {
        case KEY_ENTER:
            if (windowM->currWindow == PENGAJARHOME)
            {
                strcpy(windowM->forms.pengajarPage[windowM->selectedPage].fields[1].value.text, windowM->selectByPage.staffPage[windowM->selectedPage].selected.value);
                windowM->selectByPage.staffPage[windowM->selectedPage].selected = (SelectProp){};
            }
            if (func != NULL && dataFetcher != NULL)
            {
                func(fields, windowM->dbConn);
                dataFetcher(&windowM->datas, &windowM->datas.totalPages, windowM->dbConn);
                clearFields(fields);
            }
            windowM->activeSubWindow = READ;
            break;
        }
        break;
    }
}