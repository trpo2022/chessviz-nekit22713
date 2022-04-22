#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void yfcheck(int* yf);
void yscheck(int* ys);
void printerror();
void move(char desk[9][9], int xs, int xf, int ys, int yf);
int movecheck(char desk[9][9], int color);
void readmove(char desk[9][9], int finish, int turnp);
