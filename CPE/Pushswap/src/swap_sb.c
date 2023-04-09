/*
** EPITECH PROJECT, 2022
** sb.c
** File description:
** sb
*/

#include "../include/my.h"
#include "../include/list.h"

list_t *swap_sb(list_t *l)
{
    int a = l->list_b[0];
    l->list_b[0] = l->list_b[1];
    l->list_b[1] = a;
    my_putstr("sb ");
    return l;
}
