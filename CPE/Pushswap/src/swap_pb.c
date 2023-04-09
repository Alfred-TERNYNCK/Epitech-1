/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include "../include/list.h"

list_t *swap_pb(list_t *l)
{
    int i = l->size_b;
    l->size_b++;
    l->size_a--;
    while (i != 0) {
        l->list_b[i] = l->list_b[i - 1];
        i--;
    }
    l->list_b[0] = l->list_a[0];
    my_putstr("pb ");
    i = 0;
    while (i < l->size_a) {
        l->list_a[i] = l->list_a[i + 1];
        i++;
    }
    return l;
}
