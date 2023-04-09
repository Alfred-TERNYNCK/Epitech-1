/*
** EPITECH PROJECT, 2023
** lib
** File description:
** include
*/

#include <stdlib.h>

#ifndef UTILS_H_
    #define UTILS_H_

typedef struct map {
    int x;
    int y;
    int max_line;
    int max_col;
    char *buff;
    char *c;
    int **tab_int;
    char *final;
    int file_size;
    int first_line;
    int unprintable_char;
    int square_size;
    int size;
    char **map;
    int descriptor;
} map_t;

#endif
