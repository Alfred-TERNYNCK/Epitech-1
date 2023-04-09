/*
** EPITECH PROJECT, 2022
** main for stumper
** File description:
** Final stumper C pool
*/

#include "my.h"
#include "proto.h"
#include "utils.h"

int display_file(char **map)
{
    if (map[0] == NULL) {
        my_putstr("File is empty\n");
        return 84;
    }
    int i = 0;
    int j = 0;
    for (i = 1; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\0'; j++) {
            my_putchar(map[i][j]);
        }
        my_putchar('\n');
    }
    return 0;
}
