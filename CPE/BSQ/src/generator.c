/*
** EPITECH PROJECT, 2022
** main for stumper
** File description:
** Final stumper C pool
*/

#include "my.h"
#include "proto.h"
#include "utils.h"

int reset(int l, char *pattern)
{
    if (l == my_strlen(pattern))
        l = 0;
    return l;
}

char *first_line(char **av, char *map)
{
    int i = 0; int j = 0;
    int len_arg = my_strlen(av[1]);
    while (len_arg >= 0) {
        map[i] = av[1][j];
        i++;
        j++;
        len_arg--;
    }
    map[i - 1] = '\n';
    map[i] = '\0';
    return map;
}

char *map_generator(map_t *map, char **av)
{
    int size = my_getnbr(av[1]); char *pattern = av[2];
    char *mapp = malloc(sizeof(char) * (size * size + size));
    mapp = first_line(av, mapp); int j = 0; int k = my_strlen(mapp);
    int i = 0; int l = 0; map->descriptor = k;
    while (i < size) {
        while (j < size) {
            mapp[k] = pattern[l];
            k++;
            l++;
            l = reset(l, pattern);
            j++;
        }
        mapp[k] = '\n';
        k++;
        j = 0;
        i++;
    }
    mapp[k] = '\0';
    return mapp;
}
