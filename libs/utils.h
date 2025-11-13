#ifndef utils
#define utils

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>

void gotoXy(int x, int y);
void clrScr(void);
int getMaxX(void);
int getMaxY(void);
void readAndDrawAscii(char name[], int x, int y);
time_t parseDate(char strDate[]);
void parseID(char prefix[], int lastIdx, char (*outputID)[]);

#endif