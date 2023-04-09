/*
** EPITECH PROJECT, 2023
** dante
** File description:
** place_maze
*/

#include "proto_generator.h"

char ** remove_point(struct data * d)
{
    for (int i = 0; i < d->y; i++)
        for (int j = 0; j < d->x; j++)
            d->maze[i][j] = (d->maze[i][j] == '.') ? 'X' : d->maze[i][j];
    return d->maze;
}

char ** x_around_dir_ver(struct data * d, int dir)
{
    if (d->last_pos_y + dir < d->x && d->last_pos_y + dir >= 0
    && d->maze[d->last_pos_x][d->last_pos_y + dir] == '.')
        d->maze[d->last_pos_x][d->last_pos_y + dir] = 'X';
    if (d->last_pos_x + 1 < d->y
    && d->maze[d->last_pos_x + 1][d->last_pos_y] == '.')
        d->maze[d->last_pos_x + 1][d->last_pos_y] = 'X';
    if (d->last_pos_x - 1 >= 0
    && d->maze[d->last_pos_x - 1][d->last_pos_y] == '.')
        d->maze[d->last_pos_x - 1][d->last_pos_y] = 'X';
    if (d->last_pos_x + 1 < d->y && d->last_pos_x + dir >= 0
    && d->maze[d->last_pos_x + 1][d->last_pos_y + dir] == '.')
        d->maze[d->last_pos_x + 1][d->last_pos_y + dir] = 'X';
    if (d->last_pos_x - 1 >= 0 && d->last_pos_y + dir >= 0
    && d->maze[d->last_pos_x - 1][d->last_pos_y + dir] == '.')
        d->maze[d->last_pos_x - 1][d->last_pos_y + dir] = 'X';
    return d->maze;
}

char ** x_around_dir_hor(struct data * d, int dir)
{
    if (d->last_pos_x + dir < d->y && d->last_pos_x + dir >= 0
    && d->maze[d->last_pos_x + dir][d->last_pos_y] == '.')
        d->maze[d->last_pos_x + dir][d->last_pos_y] = 'X';
    if (d->last_pos_y + 1 < d->x
    && d->maze[d->last_pos_x][d->last_pos_y + 1] == '.')
        d->maze[d->last_pos_x][d->last_pos_y + 1] = 'X';
    if (d->last_pos_y - 1 >= 0
    && d->maze[d->last_pos_x][d->last_pos_y - 1] == '.')
        d->maze[d->last_pos_x][d->last_pos_y - 1] = 'X';
    if (d->last_pos_x + dir < d->y && d->last_pos_x + dir >= 0
    && d->last_pos_y + 1 < d->x
    && d->maze[d->last_pos_x + dir][d->last_pos_y + 1] == '.')
        d->maze[d->last_pos_x + dir][d->last_pos_y + 1] = 'X';
    if (d->last_pos_x + dir < d->y && d->last_pos_x + dir >= 0
    && d->last_pos_y - 1 >= 0
    && d->maze[d->last_pos_x + dir][d->last_pos_y - 1] == '.')
        d->maze[d->last_pos_x + dir][d->last_pos_y - 1] = 'X';
    return d->maze;
}

char ** x_around_last_pos(struct data * d)
{
    int direction = get_direction(d);
    if (direction == 0 || direction == 1)
        d->maze = x_around_dir_hor(d, (direction == 0) ? -1 : 1);
    if (direction == 2 || direction == 3)
        d->maze = x_around_dir_ver(d, (direction == 2) ? -1 : 1);
    return d->maze;
}

void advance(struct data * d)
{
    while (nb_valide_move(d) > 0) {
        d->pos = get_random_move(d);
        d->maze[d->pos[0]][d->pos[1]] = '*';
        d->maze = x_around_last_pos(d);
    }
}
