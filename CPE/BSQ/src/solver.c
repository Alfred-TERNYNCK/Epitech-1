/*
** EPITECH PROJECT, 2022
** tetst
** File description:
** s
*/

#include "my.h"
#include "utils.h"
#include "proto.h"

void int_tab_to_char_tab(map_t *map)
{
    int temp = 0;

    for (int x = 1; x < map->max_line; x++) {
        for (int y = 1; y < map->max_col; y++)
            small_int(map, temp, x, y);
    }
}

void find_biggest_square(map_t *map)
{
    map->square_size = 0;
    for (int x = 0; x < map->max_line; x++) {
        for (int y = 0; y < map->max_col; y++)
            square_stats(map, x, y);
    }
    for (int x = map->x; x > map->x - map->square_size ; x--) {
        for (int y = map->y; y > map->y - map->square_size; y--) {
            map->tab_int[x][y] = -1;
        }
    }
}

int display_map_generator(map_t *map)
{
    int j = 0;

    if ((map->final = malloc(map->file_size - map->first_line)) == NULL)
        return (1);
    for (int i = map->first_line + 1; map->buff[i]; i++) {
        map->final[j] = map->buff[i];
        j++;
    }
    map->final[j] = '\0';
    for (int x = 0; x < map->max_line; x++) {
        for (int y = 0; y < map->max_col; y++)
            convertion_pos(map, x, y);
    }
    write(1, map->final, map->file_size - map->first_line +
    map->descriptor - 1);
    return 0;
}

int display_map(map_t *map)
{
    int j = 0;

    if ((map->final = malloc(map->file_size - map->first_line)) == NULL)
        return (1);
    for (int i = map->first_line + 1; map->buff[i]; i++) {
        map->final[j] = map->buff[i];
        j++;
    }
    map->final[j] = '\0';
    for (int x = 0; x < map->max_line; x++) {
        for (int y = 0; y < map->max_col; y++)
            convertion_pos(map, x, y);
    }
    write(1, map->final, map->file_size - map->first_line - 1);
    return 0;
}
