#include <lib/move.h>
#include <lib/print.h>

void printdesk(char desk[desk_size][desk_size])
{
    int i = 0, j = 0;
    printf("\n");
    for (i = 0; i < desk_size; i++) {
        printf("%d ", desk_size - i);
        for (j = 0; j < desk_size; j++) {
            printf("%c ", desk[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h \n");
}
