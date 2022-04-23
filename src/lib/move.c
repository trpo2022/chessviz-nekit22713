#include <lib/Print.h>
#include <lib/move.h>
char turn[5];

void yfcheck(int* yf)
{
    switch (turn[3]) {
    case 'a':
        *yf = 1;
        break;
    case 'b':
        *yf = 2;
        break;
    case 'c':
        *yf = 3;
        break;
    case 'd':
        *yf = 4;
        break;
    case 'e':
        *yf = 5;
        break;
    case 'f':
        *yf = 6;
        break;
    case 'g':
        *yf = 7;
        break;
    case 'h':
        *yf = 8;
        break;
    default:
        *yf = 0;
    }
}

void yscheck(int* ys)
{
    switch (turn[0]) {
    case 'a':
        *ys = 1;
        break;
    case 'b':
        *ys = 2;
        break;
    case 'c':
        *ys = 3;
        break;
    case 'd':
        *ys = 4;
        break;
    case 'e':
        *ys = 5;
        break;
    case 'f':
        *ys = 6;
        break;
    case 'g':
        *ys = 7;
        break;
    case 'h':
        *ys = 8;
        break;
    default:
        *ys = 0;
    }
}

void printerror()
{
    printf("Wrong numbers.\n");
}

void move(char board[9][9], int xs, int xf, int ys, int yf)
{
    board[xf][yf] = board[xs][ys];
    board[xs][ys] = ' ';
}

int movecheck(char desk[9][9], int color)
{
    int xs, ys, xf, yf;
    if (color == 0) {
        xs = 56 - turn[1];
        xf = 56 - turn[4];
    } else {
        xs = 56 - turn[1];
        xf = 56 - turn[4];
    }
    yscheck(&ys);
    yfcheck(&yf);
    if (ys == 0) {
        printerror();
        return 0;
    }
    if (yf == 0) {
        printerror();
        return 0;
    }
    if (((desk[xs][ys] == 'P' || desk[xs][ys] == 'p') && abs(xf - xs) == 1
         && ys == yf)
        || ((desk[xs][ys] == 'P' || desk[xs][ys] == 'p')
            && (desk[xf][yf] == 'P' || desk[xf][yf] == 'p') && abs(xf - xs) == 1
            && abs(ys - yf) == 1)
        || ((desk[xs][ys] == 'P' || desk[xs][ys] == 'p') && abs(xf - xs) == 2
            && ys == yf)
        || ((desk[xs][ys] == 'P' || desk[xs][ys] == 'p')
            && (desk[xf][yf] == 'P' || desk[xf][yf] == 'p') && abs(xf - xs) == 2
            && abs(ys - yf) == 2))
        move(desk, xs, xf, ys, yf);
    else {
        printerror();
        printdesk(desk);
        return 0;
    }
    printdesk(desk);
    return 1;
}

void readmove(char desk[9][9], int finish, int turnp)
{
    if (desk[1][1] == 0) {
    }
    while (finish != 1) {
        if (turnp == 0)
            printf("Turn white\n");
        else
            printf("Turn black\n");
        scanf("%s", turn);
        if ((turn[0] >= 97 && turn[0] <= 104)) {
            if ((turn[3] >= 97 && turn[3] <= 104)) {
                if ((turn[1] >= 49 && turn[1] <= 56)) {
                    if ((turn[4] >= 49 && turn[4] <= 56)) {
                        if (turnp == 1) {
                            if (movecheck(desk, turnp) == 1)
                                turnp = 0;
                        } else {
                            if (movecheck(desk, turnp) == 1)
                                turnp = 1;
                        }
                    } else {
                        void printerror();
                    }
                } else {
                    void printerror();
                }
            } else {
                void printerror();
            }
        } else {
            void printerror();
        }
    }
}
