#include "utils.h"

void gotoXy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void clrScr()
{
    printf("\e[1;1H\e[2J");
}

// int getMaxX()
// {
//     struct winsize w;
//     if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) < 0)
//     {
//         perror("Error getting terminal dimensions");
//         return 1;
//     }
//     return w.ws_col;
// }

// int getMaxY()
// {
//     struct winsize w;
//     if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) < 0)
//     {
//         perror("Error getting terminal dimensions");
//         return 1;
//     }
//     return w.ws_row;
// }

void readAscii(char name[], char dest[])
{
    FILE *ascii_file;
    char line[256];
    const char filename[150];

    sprintf(filename, "assets/ascii/%s", name);

    ascii_file = fopen(filename, "r");
    if (ascii_file == NULL)
    {
        perror(filename);
        perror("Error opening file");
    }

    while (fgets(line, sizeof(line), ascii_file) != NULL)
    {
        strcat(dest, line);
    }

    fclose(ascii_file);
}

time_t parseDate(char strDate[])
{
    struct tm tm_info = {0};

    sscanf(strDate, "%d-%d-%d 0:0:0", &tm_info.tm_mday, &tm_info.tm_mon, &tm_info.tm_year, &tm_info.tm_hour, &tm_info.tm_min, &tm_info.tm_sec);
    tm_info.tm_year -= 1900;
    tm_info.tm_mon -= 1;

    return mktime(&tm_info);
}

void parseID(char prefix[], int lastIdx, char (*outputID)[])
{
    char ID[50];
    sprintf(ID, "%s%05d", prefix, lastIdx + 1);

    strcpy(*outputID, ID);
}
