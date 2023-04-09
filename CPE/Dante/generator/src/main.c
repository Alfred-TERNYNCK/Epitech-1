/*
** EPITECH PROJECT, 2023
** antman
** File description:
** main
*/

#include "proto_generator.h"

void if_open_maze(struct data * d, int i, int j)
{
    if (d->maze[i][j] == 'X' && (rand() % 25 == 0))
        d->maze[i][j] = '*';
}

char ** open_maze(struct data * d)
{
    for (int i = 0; i < d->y; i++)
        for (int j = 0; j < d->x; j++)
            if_open_maze(d, i, j);
    return d->maze;
}

int main(int ac, char ** av)
{
    if (ac < 3)
        return 84;
    struct data * d;
    d = malloc(sizeof(struct data));
    d->perfect = (ac == 4) ? 1 : 0;
    d->ac = ac;
    d->av = av;
    d->x = atoi(av[1]);
    d->y = atoi(av[2]);
    d->nb_unvisited_last = d->x * d->y;
    d->maze = create_empty_maze(d->x, d->y);
    d->maze = create_maze(d);
    if (d->perfect == 1)
        d->maze = verifie_last_square(d);
    else
        d->maze = open_maze(d);
    print_maze(d->maze);
}
