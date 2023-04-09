/*
** EPITECH PROJECT, 2023
** dante
** File description:
** generator
*/

#include "proto_generator.h"

int get_new_start_pos_second(struct data * d, int * pos, int i)
{
    for (int j = 0; j < d->x; j++)
        if (is_close_star(d, i, j) == 1 && is_close_path(d, i, j) == 1
        && d->maze[i][j] == 'X') {
            pos[0] = i;
            pos[1] = j;
            return 1;
        }
    return 0;
}

int * get_new_start_pos(struct data * d)
{
    int * pos = malloc(sizeof(int) * 2);
    for (int i = 0; i < d->y; i++)
        if (get_new_start_pos_second(d, pos, i) == 1)
            return pos;
    return pos;
}

char ** main2(struct data * d)
{
    d->perfect = 1;
    d->nb_unvisited_last = d->x * d->y;
    d->maze = create_empty_maze(d->x, d->y);
    d->maze = create_maze(d);
    return d->maze;
}

char ** verifie_last_square(struct data * d)
{
    if (d->maze[d->y - 1][d->x - 1] == 'X') {
        d->maze[d->y - 1][d->x - 1] = '*';
        d->maze[d->y - 2][d->x - 2] = 'X';
    }
    return d->maze;
}

char ** create_maze(struct data * d)
{
    d->list_move_pos = malloc(sizeof(int *) * 4);
    d->pos = get_random_pos();
    d->maze[d->pos[0]][d->pos[1]] = '*';
    while ((d->nb_unvisited = nb_unvisited_square(d)) > 0) {
        if (d->nb_unvisited == d->nb_unvisited_last && d->perfect == 1)
            return main2(d);
        if (d->nb_unvisited == d->nb_unvisited_last && d->perfect == 0)
            return remove_point(d);
        d->nb_unvisited_last = d->nb_unvisited;
        advance(d);
        d->pos = get_new_start_pos(d);
        d->maze[d->pos[0]][d->pos[1]] = '*';
    }
    return d->maze;
}
