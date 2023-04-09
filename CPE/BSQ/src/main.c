/*
** EPITECH PROJECT, 2022
** main for stumper
** File description:
** Final stumper C pool
*/

#include "my.h"
#include "proto.h"
#include "utils.h"

int start(map_t *map, int fd, char **av, int ac)
{
    if (ac == 3)
        map->file_size = (my_getnbr(av[1]) + 1) *
        my_getnbr(av[1]) + my_getnbr(av[1]);
    if (ac == 2)
        if (feed_b(map, fd, av) == 1)
            return 1;
    call_stats(map);
    if (feed_tab_char(map, ac, av) == 1)
        return 1;
    if (feed_tab_int(map) == 1)
        return 1;
    int_tab_to_char_tab(map); find_biggest_square(map);
    if (ac == 2)
        if (display_map(map) == 1)
            return 1;
    if (ac == 3)
        if (display_map_generator(map) == 1)
            return 1;
    return 0;
}

int second(char **av, int ac)
{
    if (ac == 3) {
        if (my_getnbr(av[1]) <= 0)
            return 1;
        if (str_is_x(av) == 1)
            return 1;
        if (av[2][0] == '\0')
            return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t));
    int fd = open(av[1], O_RDONLY);
    if (second(av, ac) == 1)
        return 84;
    if (ac == 3 && is_a_number(av[1]) == 0) {
        map->buff = map_generator(map, av);
        start(map, fd, av, ac);
        return 0;
    }
    if (fd == -1)
        return 84;
    if (fd_file(av[1]) == 84)
        return 84;
    if (ac == 2) {
        if (start(map, fd, av, ac) == 1)
            return 84;
    }
    free_all_free(map);
    return 0;
}
