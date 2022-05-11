#pragma once
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define desk_size 8

typedef struct motion {
    int y1;
    int x1;
    int y2;
    int x2;
} motion;

void printdesk(char desk[desk_size][desk_size]);

void translate(char* step, motion* motion);

bool moveKing(
        char desk[desk_size][desk_size], motion motion, bool error_output);

bool moveQueen(
        char desk[desk_size][desk_size], motion motion, bool error_output);

bool moveRook(
        char desk[desk_size][desk_size], motion motion, bool error_output);

bool moveKnight(
        char desk[desk_size][desk_size], motion motion, bool error_output);

bool moveBishop(
        char desk[desk_size][desk_size], motion motion, bool error_output);

bool movePawn(
        char* step,
        motion motion,
        char desk[desk_size][desk_size],
        bool moveW,
        bool error_output);

bool movecheck(
        char* step,
        motion motion,
        char desk[desk_size][desk_size],
        bool moveW,
        bool output);

int turn(
        char* step, motion motion, char desk[desk_size][desk_size], bool moveW);
