/*
** EPITECH PROJECT, 2022
** init_calc.c
** File description:
** init_calc
*/

#include "../include/my.h"
#include "../include/list.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void calc(list_t *l)
{
    while (check_sort(l) != 1) {
        while (l->size_a != 1)
            clac_list_a(l);
        while (l->size_b != 0)
            calc_list_b(l);
    }
}

void init_calc(int ac, char **av)
{
    int i = (ac - 1);
    int x = 0;
    list_t *l = malloc(sizeof(list_t));
    l->list_a = malloc(sizeof(int) * (ac - 1));
    l->list_b = malloc(sizeof(int) * (ac - 1));

    l->size_a = i;
    l->size_b = 0;
    for (int j = 0 ; j < i ; j++)
        l->list_a[j] = my_getnbr(av[j + 1]);

    if (check_sort(l) == 1 && x == 0) {
        my_putchar('\n');
        return;
    }
    x++;
    calc(l);
    if (check_sort(l) == 1)
        my_putstr("sa sa");
}
