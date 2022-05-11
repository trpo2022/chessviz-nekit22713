#include <lib/move.h>
#include <lib/print.h>

void translate(char* step, motion* motion)
{
    switch (strlen(step)) {
    case 5:
        motion->y1 = desk_size - ((int)step[1] - (int)'0');
        motion->x1 = (int)step[0] - (int)'a';
        motion->y2 = desk_size - ((int)step[4] - (int)'0');
        motion->x2 = (int)step[3] - (int)'a';
        break;
    case 6:
        if (step[5] != '#') {
            motion->y1 = desk_size - ((int)step[2] - (int)'0');
            motion->x1 = (int)step[1] - (int)'a';
            motion->y2 = desk_size - ((int)step[5] - (int)'0');
            motion->x2 = (int)step[4] - (int)'a';
        } else {
            motion->y1 = desk_size - ((int)step[1] - (int)'0');
            motion->x1 = (int)step[0] - (int)'a';
            motion->y2 = desk_size - ((int)step[4] - (int)'0');
            motion->x2 = (int)step[3] - (int)'a';
        }
        break;
    case 7:
        motion->y1 = desk_size - ((int)step[2] - (int)'0');
        motion->x1 = (int)step[1] - (int)'a';
        motion->y2 = desk_size - ((int)step[5] - (int)'0');
        motion->x2 = (int)step[4] - (int)'a';
    default:
        break;
    }
}

bool moveKing(char desk[desk_size][desk_size], motion motion, bool error_output)
{
    if (!((desk[motion.y1][motion.x1] == 'K')
          || (desk[motion.y1][motion.x1] == 'k'))) {
        if (error_output == true)
            printf("\nError: Wrong body\n");
        return false;
    }
    if ((abs(motion.y2 - motion.y1) > 1) || (abs(motion.x2 - motion.x1) > 1)
        || ((motion.x2 - motion.x1 == 0) && (motion.y2 - motion.y1 == 0))) {
        if (error_output == true)
            printf("\nError: Wrong move\n");
        return false;
    }
    return true;
}

bool moveQueen(
        char desk[desk_size][desk_size], motion motion, bool error_output)
{
    if (!((desk[motion.y1][motion.x1] == 'Q')
          || (desk[motion.y1][motion.x1] == 'q'))) {
        if (error_output == true)
            printf("\nError: Wrong body\n");
        return false;
    }
    if (!((abs(motion.x1 - motion.x2) == abs(motion.y1 - motion.y2))
          || ((motion.y2 - motion.y1 == 0) && (abs(motion.x1 - motion.x2) > 0))
          || ((motion.x2 - motion.x1 == 0)
              && (abs(motion.y1 - motion.y2) > 0)))) {
        if (error_output == true)
            printf("\nError: Wrong move\n");
        return false;
    }
    if ((motion.y2 - motion.y1 == 0) && (abs(motion.x1 - motion.x2) > 0)) {
        if (motion.x2 > motion.x1) {
            motion.x1++;
            while (motion.x2 > motion.x1) {
                if (desk[motion.y1][motion.x1] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot move like that\n");
                    return false;
                }
                motion.x1++;
            }
        }
        if (motion.x1 > motion.x2) {
            motion.x2++;
            while (motion.x1 > motion.x2) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x2++;
            }
        }
    }
    if ((motion.x2 - motion.x1 == 0) && (abs(motion.y1 - motion.y2) > 0)) {
        if (motion.y2 > motion.y1) {
            motion.y1++;
            while (motion.y2 > motion.y1) {
                if (desk[motion.y1][motion.x1] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.y1++;
            }
        }
        if (motion.y1 > motion.y2) {
            motion.y2++;
            while (motion.y1 > motion.y2) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.y2++;
            }
        }
    }
    if (abs(motion.x1 - motion.x2) == abs(motion.y1 - motion.y2)) {
        if ((motion.x1 > motion.x2) && (motion.y1 > motion.y2)) {
            motion.x2++;
            motion.y2++;
            while ((motion.x1 > motion.x2) && (motion.y1 > motion.y2)) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x2++;
                motion.y2++;
            }
        }
        if ((motion.x1 > motion.x2) && (motion.y1 < motion.y2)) {
            motion.x2++;
            motion.y2--;
            while ((motion.x1 > motion.x2) && (motion.y1 < motion.y2)) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x2++;
                motion.y2--;
            }
        }
        if ((motion.x1 < motion.x2) && (motion.y1 > motion.y2)) {
            motion.x2--;
            motion.y2++;
            while ((motion.x1 < motion.x2) && (motion.y1 > motion.y2)) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x2--;
                motion.y2++;
            }
        }
        if ((motion.x1 < motion.x2) && (motion.y1 < motion.y2)) {
            motion.x1++;
            motion.y1++;
            while ((motion.x1 < motion.x2) && (motion.y1 < motion.y2)) {
                if (desk[motion.y1][motion.x1] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that");
                    return false;
                }
                motion.x1++;
                motion.y1++;
            }
        }
    }
    return true;
}

bool moveRook(char desk[desk_size][desk_size], motion motion, bool error_output)
{
    if (!((desk[motion.y1][motion.x1] == 'R')
          || (desk[motion.y1][motion.x1] == 'r'))) {
        if (error_output == true)
            printf("\nError: Wrong body\n");
        return false;
    }
    if (!(((motion.y2 - motion.y1 == 0) && (abs(motion.x1 - motion.x2) > 0))
          || ((motion.x2 - motion.x1 == 0)
              && (abs(motion.y1 - motion.y2) > 0)))) {
        if (error_output == true)
            printf("\nError: Wrong move\n");
        return false;
    }
    if ((motion.y2 - motion.y1 == 0) && (abs(motion.x1 - motion.x2) > 0)) {
        if (motion.x2 > motion.x1) {
            motion.x1++;
            while (motion.x2 > motion.x1) {
                if (desk[motion.y1][motion.x1] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x1++;
            }
        }
        if (motion.x1 > motion.x2) {
            motion.x2++;
            while (motion.x1 > motion.x2) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x2++;
            }
        }
    }
    if ((motion.x2 - motion.x1 == 0) && (abs(motion.y1 - motion.y2) > 0)) {
        if (motion.y2 > motion.y1) {
            motion.y1++;
            while (motion.y2 > motion.y1) {
                if (desk[motion.y1][motion.x1] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.y1++;
            }
        }
        if (motion.y1 > motion.y2) {
            motion.y2++;
            while (motion.y1 > motion.y2) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.y2++;
            }
        }
    }
    return true;
}

bool moveKnight(
        char desk[desk_size][desk_size], motion motion, bool error_output)
{
    if (!((desk[motion.y1][motion.x1] == 'N')
          || (desk[motion.y1][motion.x1] == 'n'))) {
        if (error_output == true)
            printf("\nError: Wrong body\n");
        return false;
    }
    if (!(((abs(motion.y2 - motion.y1) == 2)
           && (abs(motion.x1 - motion.x2) == 1))
          || ((abs(motion.x2 - motion.x1) == 2)
              && (abs(motion.y1 - motion.y2) == 1)))) {
        if (error_output == true)
            printf("\nError: Wrong move\n");
        return false;
    }
    return true;
}

bool moveBishop(
        char desk[desk_size][desk_size], motion motion, bool error_output)
{
    if (!((desk[motion.y1][motion.x1] == 'B')
          || (desk[motion.y1][motion.x1] == 'b'))) {
        if (error_output == true)
            printf("\nError: Wrong body\n");
        return false;
    }
    if (!(abs(motion.x1 - motion.x2) == abs(motion.y1 - motion.y2))) {
        if (error_output == true)
            printf("\nError: Wrong move\n");
        return false;
    }
    if (abs(motion.x1 - motion.x2) == abs(motion.y1 - motion.y2)) {
        if ((motion.x1 > motion.x2) && (motion.y1 > motion.y2)) {
            motion.x2++;
            motion.y2++;
            while ((motion.x1 > motion.x2) && (motion.y1 > motion.y2)) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x2++;
                motion.y2++;
            }
        }
        if ((motion.x1 > motion.x2) && (motion.y1 < motion.y2)) {
            motion.x2++;
            motion.y2--;
            while ((motion.x1 > motion.x2) && (motion.y1 < motion.y2)) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x2++;
                motion.y2--;
            }
        }
        if ((motion.x1 < motion.x2) && (motion.y1 > motion.y2)) {
            motion.x2--;
            motion.y2++;
            while ((motion.x1 < motion.x2) && (motion.y1 > motion.y2)) {
                if (desk[motion.y2][motion.x2] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x2--;
                motion.y2++;
            }
        }
        if ((motion.x1 < motion.x2) && (motion.y1 < motion.y2)) {
            motion.x1++;
            motion.y1++;
            while ((motion.x1 < motion.x2) && (motion.y1 < motion.y2)) {
                if (desk[motion.y1][motion.x1] != ' ') {
                    if (error_output == true)
                        printf("Error: You cannot step like that\n");
                    return false;
                }
                motion.x1++;
                motion.y1++;
            }
        }
    }
    return true;
}

bool movePawn(
        char* step,
        motion motion,
        char desk[desk_size][desk_size],
        bool moveW,
        bool error_output)
{
    if (!((step[2] == '-') || (step[2] == 'x'))) {
        if (error_output == true)
            printf("\nError: Unknown step\n");
        return false;
    }
    if ((motion.x1 > 7) || (motion.x1 < 0) || (motion.x2 > 7) || (motion.x2 < 0)
        || (motion.y1 > 7) || (motion.y1 < 0) || (motion.y2 > 7)
        || (motion.y2 < 0)) {
        if (error_output == true)
            printf("\nError: Going off the board\n");
        return false;
    }
    if (desk[motion.y1][motion.x1] == ' ') {
        if (error_output == true)
            printf("\nError: The cell is empty\n");
        return false;
    }
    if (!((desk[motion.y1][motion.x1] == 'p')
          || (desk[motion.y1][motion.x1] == 'P'))) {
        if (error_output == true)
            printf("\nError: The input must move pawns\n");
        return false;
    }
    if (step[2] == '-') {
        if (motion.x1 != motion.x2) {
            if (error_output == true)
                printf("\nError: Pawns only move straight\n");
            return false;
        }
        if (desk[motion.y2][motion.x2] != ' ') {
            if (error_output == true)
                printf("\n\n %d %d \n\n", motion.y2, motion.x2);
            printf("\nError: You cannot make a silent move\n");
            return false;
        }
        if (desk[motion.y1][motion.x1] == 'P') {
            if (moveW == false) {
                if (error_output == true)
                    printf("\nError: Black turn\n");
                return false;
            }
            if (motion.y1 == 6) {
                if ((motion.y1 - motion.y2 > 2)
                    || (motion.y1 - motion.y2 < 1)) {
                    if (error_output == true)
                        printf("\nError: At first move pawns can move 1-2 "
                               "squares\n");
                    return false;
                }
                if ((motion.y1 - motion.y2 == 2)
                    && (desk[(motion.y1 + motion.y2) / 2][motion.x1] != ' ')) {
                    if (error_output == true)
                        printf("\nError: You can't step like that\n");
                    return false;
                }
            } else {
                if (motion.y1 - motion.y2 != 1) {
                    if (error_output == true)
                        printf("\nError: After the first move pawns can move 1 "
                               "square\n");
                    return false;
                }
            }
        }
        if (desk[motion.y1][motion.x1] == 'p') {
            if (moveW == true) {
                if (error_output == true)
                    printf("\nError: White turn\n");
                return false;
            }
            if (motion.y1 == 1) {
                if ((motion.y2 - motion.y1 > 2)
                    || (motion.y2 - motion.y1 < 1)) {
                    if (error_output == true)
                        printf("\nError: At first move pawns can move 1-2 "
                               "squares\n");
                    return false;
                }
                if ((motion.y2 - motion.y1 == 2)
                    && (desk[(motion.y1 + motion.y2) / 2][motion.x1] != ' ')) {
                    if (error_output == true)
                        printf("\nError: You can't step like that\n");
                    return false;
                }

            } else {
                if (motion.y2 - motion.y1 != 1) {
                    if (error_output == true)
                        printf("\nError: After the first move pawns can move 1 "
                               "square\n");
                    return false;
                }
            }
        }
    }
    if (step[2] == 'x') {
        if (desk[motion.y2][motion.x2] == ' ') {
            if (error_output == true)
                printf("\nError: You can't take an empty cell\n");
            return false;
        }
        if (abs(motion.x1 - motion.x2) != 1) {
            if (error_output == true)
                printf("\nError: You can only take diagonally 1 cell to "
                       "the sides\n");
            return false;
        }
        if ((desk[motion.y1][motion.x1] == 'P')
            && (motion.y1 - motion.y2 != 1)) {
            if (error_output == true)
                printf("\nError: You can only take diagonally 1 cell to "
                       "the sides\n");
            return false;
        }
        if ((desk[motion.y1][motion.x1] == 'p')
            && (motion.y2 - motion.y1 != 1)) {
            if (error_output == true)
                printf("\nError: You can only take diagonally 1 cell to "
                       "the sides\n");
            return false;
        }
        if ((moveW == true) && (desk[motion.y1][motion.x1] == 'p')) {
            if (error_output == true)
                printf("\nError: White turn\n");
            return false;
        }
        if ((moveW == false) && (desk[motion.y1][motion.x1] == 'P')) {
            if (error_output == true)
                printf("\nError: Black turn\n");
            return false;
        }
        if (((moveW == true)
             && ((desk[motion.y2][motion.x2] >= 65)
                 && (desk[motion.y2][motion.x2] <= 90)))
            || ((moveW == false)
                && ((desk[motion.y2][motion.x2] >= 97)
                    && (desk[motion.y2][motion.x2] <= 122)))) {
            if (error_output == true)
                printf("\nError: You can't attack your pieces\n");
            return false;
        }
    }

    return true;
}

bool movecheck(
        char* step,
        motion motion,
        char desk[desk_size][desk_size],
        bool moveW,
        bool output)
{
    bool error_output;
    if (output == false)
        error_output = false;
    else
        error_output = true;
    switch (strlen(step)) {
    case 5:
        if (movePawn(step, motion, desk, moveW, error_output) == false)
            return false;
        break;
    case 6:
        if (step[5] != '#') {
            if (!((step[3] == '-') || (step[3] == 'x'))) {
                if (output == true)
                    printf("\nError: Unknown step\n");
                return false;
            }
            if ((motion.x1 > 7) || (motion.x1 < 0) || (motion.x2 > 7)
                || (motion.x2 < 0) || (motion.y1 > 7) || (motion.y1 < 0)
                || (motion.y2 > 7) || (motion.y2 < 0)) {
                if (output == true)
                    printf("\nError: Going off\n");
                return false;
            }
            if (desk[motion.y1][motion.x1] == ' ') {
                if (output == true)
                    printf("\nError: The starting cell is empty\n");
                return false;
            }
            if ((desk[motion.y2][motion.x2] != ' ') && (step[3] == '-')) {
                if (output == true)
                    printf("\nError: You cannot make a silent move\n");
                return false;
            }
            if ((desk[motion.y2][motion.x2] == ' ') && (step[3] == 'x')) {
                if (output == true)
                    printf("\nError: You can't take an empty cell\n");
                return false;
            }
            if ((moveW == false)
                && ((desk[motion.y1][motion.x1] >= 65)
                    && (desk[motion.y1][motion.x1] <= 90))) {
                if (output == true)
                    printf("\nError: Black turn\n");
                return false;
            }
            if ((moveW == true)
                && ((desk[motion.y1][motion.x1] >= 97)
                    && (desk[motion.y1][motion.x1] <= 122))) {
                if (output == true)
                    printf("\nError: White turn\n");
                return false;
            }
            if (((moveW == true)
                 && ((desk[motion.y2][motion.x2] >= 65)
                     && (desk[motion.y2][motion.x2] <= 90)))
                || ((moveW == false)
                    && ((desk[motion.y2][motion.x2] >= 97)
                        && (desk[motion.y2][motion.x2] <= 122)))) {
                if (output == true)
                    printf("\nError: You can't attack your pieces\n");
                return false;
            }
            if (step[0] == 'K') { // King
                if (moveKing(desk, motion, error_output) == false)
                    return false;
            } else if (step[0] == 'n') {
                if (output == true)
                    printf("\nError: Body type is capitalized\n");
                return false;
            }
            if (step[0] == 'Q') { // Queen
                if (moveQueen(desk, motion, error_output) == false)
                    return false;
            } else if (step[0] == 'n') {
                if (output == true)
                    printf("\nError: Body type is capitalized\n");
                return false;
            }
            if (step[0] == 'R') { // Rook
                if (moveRook(desk, motion, error_output) == false)
                    return false;
            } else if (step[0] == 'n') {
                if (output == true)
                    printf("\nError: Body type is capitalized\n");
                return false;
            }
            if (step[0] == 'N') { // kNight
                if (moveKnight(desk, motion, error_output) == false)
                    return false;
            } else if (step[0] == 'n') {
                if (output == true)
                    printf("\nError: Body type is capitalized\n");
                return false;
            }
            if (step[0] == 'B') { // Bishop
                if (moveBishop(desk, motion, error_output) == false)
                    return false;
            } else if (step[0] == 'n') {
                if (output == true)
                    printf("\nError: Body type is capitalized\n");
                return false;
            }
        }
        if (step[5] == '#') {
            if (step[2] != 'x') {
                if (output == true)
                    printf("\nError: Wrong mate\n");
                return false;
            }
            if (movePawn(step, motion, desk, moveW, error_output) == false)
                return false;
        }
        break;
    case 7:
        error_output = false;
        if (step[6] != '#') {
            if (output == true)
                printf("\nError: Wrong step\n");
            return false;
        }
        if (step[3] != 'x') {
            if (output == true)
                printf("\nError: Wrong mate\n");
            return false;
        }
        if ((moveW == false)
            && ((desk[motion.y1][motion.x1] >= 65)
                && (desk[motion.y1][motion.x1] <= 90))) {
            if (output == true)
                printf("\nError: Black turn\n");
            return false;
        }
        if ((moveW == true)
            && ((desk[motion.y1][motion.x1] >= 97)
                && (desk[motion.y1][motion.x1] <= 122))) {
            if (output == true)
                printf("\nError: White turn\n");
            return false;
        }
        if (((moveW == true)
             && ((desk[motion.y2][motion.x2] >= 65)
                 && (desk[motion.y2][motion.x2] <= 90)))
            || ((moveW == false)
                && ((desk[motion.y2][motion.x2] >= 97)
                    && (desk[motion.y2][motion.x2] <= 122)))) {
            if (output == true)
                printf("\nError: You can't attack your pieces\n");
            return false;
        }
        if ((moveKnight(desk, motion, error_output) == false)
            && (moveKing(desk, motion, error_output) == false)
            && (moveQueen(desk, motion, error_output) == false)
            && (moveRook(desk, motion, error_output) == false)
            && (moveKnight(desk, motion, error_output) == false))
            return false;
        break;
    default:
        return false;
        break;
    }
    return true;
}

int turn(char* step, motion motion, char desk[desk_size][desk_size], bool moveW)
{
    char type;
    bool output = true;
    translate(step, &motion);
    if (movecheck(step, motion, desk, moveW, output) == true) {
        type = desk[motion.y1][motion.x1];
        desk[motion.y1][motion.x1] = ' ';
        desk[motion.y2][motion.x2] = type;
        return 0;
    } else
        return 1;
}
