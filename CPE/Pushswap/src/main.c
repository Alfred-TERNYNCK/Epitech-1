/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include "../include/list.h"

int is_a_number(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            i++;
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int is_arg_is_number(int ac, char **av)
{
    while (ac > 1) {
        if (is_a_number(av[ac - 1]) == 0)
            return 84;
        ac--;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    if (ac == 2 && is_arg_is_number(ac, av) == 0) {
        my_putchar('\n');
        return 0;
    }
    if (ac == 3 && is_arg_is_number(ac, av) == 0) {
        if (my_getnbr(av[1]) > my_getnbr(av[2])) {
            my_putstr("sa");
            my_putchar('\n');
        }
        return 0;
    }
    if (ac > 3 && is_arg_is_number(ac, av) == 0) {
        init_calc(ac, av);
        return 0;
    } else
        return 84;
}
