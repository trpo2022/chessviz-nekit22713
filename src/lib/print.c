#include <lib/Print.h>

void printdesk(char desk[9][9])
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}
