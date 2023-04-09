/*
** EPITECH PROJECT, 2022
** main for stumper
** File description:
** Final stumper C pool
*/

#include "my.h"
#include "utils.h"
#include "proto.h"

int minimum(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

void small_int(map_t *map, int temp, int x, int y)
{
    if (map->tab_int[x][y] != 0) {
        temp = map->tab_int[x - 1][y];
        if (temp > map->tab_int[x][y - 1])
            temp = map->tab_int[x][y - 1];
        if (temp > map->tab_int[x - 1][y - 1])
            temp = map->tab_int[x - 1][y - 1];
        map->tab_int[x][y] += temp;
    }
}

void convertion_pos(map_t *map, int x, int y)
{
    if (map->tab_int[x][y] == -1)
        map->final[x * map->max_col + y + x] = 'x';
}

int str_is_x(char **av)
{
    int i = 0;
    while (av[2][i] != '\0') {
        if (av[2][i] != 'o' && av[2][i] != '.' && av[2][i] != 'x')
            return 1;
        i++;
    }
    if (i == 0)
        return 1;
    return 0;
}
