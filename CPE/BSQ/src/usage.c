/*
** EPITECH PROJECT, 2022
** main for stumper
** File description:
** Final stumper C pool
*/

#include "my.h"
#include "utils.h"
#include "proto.h"

int usage(int ac, char **av)
{
    if (ac == 1) {
        write(2, "USAGE: \tmap <file>\n\tmap <size> <pattern>", 41);
        return 1;
    }
    if (ac > 3) {
        write(2, "Too many arguments.\n", 20);
        return 1;
    }
    if (ac == 3) {
        if (my_str_isalpha(av[1]) == 1) {
            write(2, "Invalid size.\n", 13);
            return 1;
        }
    }
    return 0;
}
