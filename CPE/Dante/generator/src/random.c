/*
** EPITECH PROJECT, 2023
** dante
** File description:
** random
*/

#include "proto_generator.h"

int * get_random_pos(void)
{
    int * pos = malloc(sizeof(int) * 2);
    srand(time(NULL));
    pos[0] = 0;
    pos[1] = 0;
    return pos;
}

int nb_valide_move(struct data * d)
{
    int nb = 0;
    d->list_move_pos = full_zero(d);
    if (d->pos[0] - 1 >= 0 && d->maze[d->pos[0] - 1][d->pos[1]] == '.') {
        d->list_move_pos[0] = 1;
        nb++;
    }
    if (d->pos[0] + 1 < d->y && d->maze[d->pos[0] + 1][d->pos[1]] == '.'){
        d->list_move_pos[1] = 1;
        nb++;
    }
    if (d->pos[1] - 1 >= 0 && d->maze[d->pos[0]][d->pos[1] - 1] == '.'){
        d->list_move_pos[2] = 1;
        nb++;
    }
    if (d->pos[1] + 1 < d->x && d->maze[d->pos[0]][d->pos[1] + 1] == '.'){
        d->list_move_pos[3] = 1;
        nb++;
    }
    return nb;
}

int * get_random_move(struct data * d)
{
    int move = 0;
    do {
        move = rand() % 4;
    } while (d->list_move_pos[move] == 0);
    d->last_pos_x = d->pos[0];
    d->last_pos_y = d->pos[1];
    if (move == 0)
        d->pos[0] -= 1;
    if (move == 1)
        d->pos[0] += 1;
    if (move == 2)
        d->pos[1] -= 1;
    if (move == 3)
        d->pos[1] += 1;
    return d->pos;
}
