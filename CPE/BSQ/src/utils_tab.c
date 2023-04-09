/*
** EPITECH PROJECT, 2022
** main for stumper
** File description:
** Final stumper C pool
*/

#include "my.h"
#include "utils.h"
#include "proto.h"

int feed_b(map_t *map, int fd, char **av)
{
    struct stat s;

    stat(av[1], &s);
    map->file_size = s.st_size;
    if (map->file_size == 0) {
        write(2, "File is empty.\n", 15);
        return 1;
    }
    if ((map->buff = malloc(map->file_size + 1)) == NULL)
        return 1;
    read(fd, map->buff, map->file_size);
    close(fd);
    map->buff[map->file_size] = '\0';
    return 0;
}

int help(map_t *map, int i, int j)
{
    if (map->buff[i] == '.')
        map->c[j] = '.';
    else if (map->buff[i] == 'o')
        map->c[j] = 'o';
    else
        j--;
    j++;
    return j;
}

int feed_tab_char(map_t *map, int ac, char **av)
{
    int j = 0;
    int i = 0;
    if (ac == 3) {
        map->file_size = my_getnbr(av[1]) * my_getnbr(av[1]) + my_getnbr(av[1]);
    }
    if ((map->c = malloc(map->file_size - map->unprintable_char + 1)) == NULL)
        return 1;
    i = map->first_line;
    while (map->buff[i]) {
        j = help(map, i, j);
        i++;
    }
    if (j == 1)
        map->max_col = 1;
    map->c[j] = '\0';
    return 0;
}

void check_char_int(map_t *map, int x, int y, int j)
{
    if (map->c[j] == '.')
        map->tab_int[x][y] = 1;
    else if (map->c[j] == 'o')
        map->tab_int[x][y] = 0;
}

int feed_tab_int(map_t *map)
{
    int x = 0; int y = 0; int j = 0; int i = 0;

    if ((map->tab_int = malloc(sizeof(int*) * map->max_line)) == NULL)
        return 1;
    while (i < map->max_line) {
        if ((map->tab_int[i] = malloc(sizeof(int) * map->max_col)) == NULL)
            return 1;
        i++;
    }
    while (x < map->max_line) {
        for (y = 0; y < map->max_col; y++) {
            check_char_int(map, x, y, j);
            j++;
        }
        x++;
    }
    return 0;
}
