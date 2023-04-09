/*
** EPITECH PROJECT, 2023
** dante
** File description:
** get_info
*/

#include "proto_generator.h"

int get_direction(struct data * d)
{
    if (d->last_pos_x == d->pos[0] - 1)
        return 0;
    if (d->last_pos_x == d->pos[0] + 1)
        return 1;
    if (d->last_pos_y == d->pos[1] - 1)
        return 2;
    if (d->last_pos_y == d->pos[1] + 1)
        return 3;
    return 0;
}

int nb_unvisited_square(struct data * d)
{
    int nb = 0;
    for (int i = 0; i < d->y; i++)
        for (int j = 0; j < d->x; j++)
            nb += (d->maze[i][j] == '.') ? 1 : 0;
    return nb;
}

int is_close_star(struct data * d, int i, int j)
{
    if (i - 1 >= 0 && d->maze[i - 1][j] == '.')
        return 1;
    if (i + 1 < d->y && d->maze[i + 1][j] == '.')
        return 1;
    if (j - 1 >= 0 && d->maze[i][j - 1] == '.')
        return 1;
    if (j + 1 < d->x && d->maze[i][j + 1] == '.')
        return 1;
    return 0;
}

int is_close_path(struct data * d, int i, int j)
{
    if (i - 1 >= 0 && d->maze[i - 1][j] == '*')
        return 1;
    if (i + 1 < d->y && d->maze[i + 1][j] == '*')
        return 1;
    if (j - 1 >= 0 && d->maze[i][j - 1] == '*')
        return 1;
    if (j + 1 < d->x && d->maze[i][j + 1] == '*')
        return 1;
    return 0;
}
