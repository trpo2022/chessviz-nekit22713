#include <lib/move.h>
#include <lib/print.h>

int main()
{
    char desk[desk_size][desk_size]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    motion motion;
    printdesk(desk);
    char step[10];
    float turnnumber = 1;
    bool moveW = true;
    while (true) {
        printf("%d. ", (int)turnnumber);
        turnnumber += 0.5;
        scanf("%s", step);
        if (turn(step, motion, desk, moveW) != 0) {
            printf("Try again\n");
            turnnumber -= 0.5;
            continue;
        };
        printdesk(desk);
        printf("\n");
        if ((step[6] == '#') || (step[5] == '#')) {
            if (moveW == true)
                printf("Black Wins!\n");
            ;
            if (moveW == false)
                printf("White Wins!\n");
            break;
        }
        moveW = !moveW;
    }
    return 0;
}
