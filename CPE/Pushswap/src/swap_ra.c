/*
** EPITECH PROJECT, 2022
** ra.c
** File description:
** ra
*/

#include "../include/my.h"
#include "../include/list.h"

list_t *swap_ra(list_t *l)
{
    int i = 0;
    int a = l->list_a[0];
    while (i < l->size_a) {
        l->list_a[i] = l->list_a[i + 1];
        i++;
    }
    l->list_a[l->size_a - 1] = a;
    my_putstr("ra ");
    return l;
}
