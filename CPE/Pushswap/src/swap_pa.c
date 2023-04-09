/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include "../include/list.h"

list_t *swap_pa(list_t *l)
{
    int i = 0;
    i = l->size_a;
    while (i > 0) {
        l->list_a[i] = l->list_a[i - 1];
        i--;
    }
    l->size_a++;
    l->list_a[0] = l->list_b[0];
    my_putstr("pa ");
    i = 0;
    while (i < l->size_b) {
        l->list_b[i] = l->list_b[i + 1];
        i++;
    }
    l->size_b--;
    return l;
}
