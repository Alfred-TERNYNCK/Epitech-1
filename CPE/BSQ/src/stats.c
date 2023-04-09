/*
** EPITECH PROJECT, 2022
** tetst
** File description:
** s
*/

#include "my.h"
#include "utils.h"
#include "proto.h"

void call_stats(map_t *map)
{
    int i = 0;
    map->first_line = 0;
    while (map->buff[i] != '\n') {
        map->first_line += 1;
        i++;
    }
    i = 0;
    map->max_line = 0;
    while (map->buff[i]) {
        if (map->buff[i] == '\n')
            map->max_line += 1;
        i++;
    }
    map->max_line -= 1;
    map->unprintable_char = map->max_line + map->first_line;
    map->max_col = (map->file_size - map->unprintable_char) / map->max_line;
}

void square_stats(map_t *map, int x, int y)
{
    if (map->square_size < map->tab_int[x][y]) {
        map->x = x;
        map->y = y;
        map->square_size = map->tab_int[x][y];
    }
}
