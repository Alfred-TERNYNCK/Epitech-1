/*
** EPITECH PROJECT, 2022
** display_result.c
** File description:
** display_result
*/

#include "../include/my.h"
#include "../include/list.h"

void display_result(list_t *l)
{
    int i = 0;
    my_putchar('\n');
    while (i < l->size_a) {
        my_put_nbr(l->list_a[i]);
        my_putchar(' ');
        i++;
    }
}
