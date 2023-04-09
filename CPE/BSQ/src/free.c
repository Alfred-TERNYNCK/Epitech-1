/*
** EPITECH PROJECT, 2022
** main for stumper
** File description:
** Final stumper C pool
*/

#include "my.h"
#include "proto.h"
#include "utils.h"

void free_all_free(map_t *map)
{
    int i = 0;
    while (i < map->max_line) {
        free(map->tab_int[i]);
        i++;
    }
    free(map->final);
    free(map->tab_int);
    free(map->c);
    free(map->buff);
    free(map);
}
