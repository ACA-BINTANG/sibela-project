#ifndef utils
#define utils

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <time.h>

void gotoXy(int x, int y);
void clrScr(void);
// int getMaxX(void);
// int getMaxY(void);
void readAscii(char name[], char dest[]);
time_t parseDate(char strDate[]);
void parseID(char prefix[], int lastIdx, char (*outputID)[]);
// void readDBDsn(char target[]);

#endif