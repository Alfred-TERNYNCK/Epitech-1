/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include "../include/list.h"

list_t *swap_sa(list_t *l)
{
    int a = l->list_a[0];
    l->list_a[0] = l->list_a[1];
    l->list_a[1] = a;
    my_putstr("sa ");
    return l;
}
