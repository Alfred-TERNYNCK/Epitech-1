/*
** EPITECH PROJECT, 2022
** rb.c
** File description:
** rb
*/

#include "../include/my.h"
#include "../include/list.h"

list_t *swap_rb(list_t *l)
{
    int i = 0;
    int a = l->list_b[0];
    while (i < l->size_b) {
        l->list_b[i] = l->list_b[i + 1];
        i++;
    }
    l->list_b[l->size_b - 1] = a;
    my_putstr("rb ");
    return l;
}
