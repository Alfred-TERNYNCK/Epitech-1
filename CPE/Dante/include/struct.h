/*
** EPITECH PROJECT, 2023
** dante
** File description:
** struct
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <time.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

    struct data {
        int x;
        int y;
        char ** maze;
        int last_pos_x;
        int last_pos_y;
        int * pos;
        int * list_move_pos;
        int perfect;
        int ac;
        char ** av;
        int nb_unvisited;
        int nb_unvisited_last;
    };

    struct list_chained {
        int x;
        int y;
        int last_opt;
        int current_opt;
        struct list_chained * prev;
        struct list_chained * next;
    };

    struct solver {
        struct list_chained * list;
        char ** maze;
        int x;
        int y;
        int cx;
        int cy;
    };

#endif /* !STRUCT_H_ */
