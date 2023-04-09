/*
** EPITECH PROJECT, 2022
** init_calc.c
** File description:
** init_calc
*/

#include "../include/my.h"
#include "../include/list.h"
#include <stdio.h>
#include <fcntl.h>

void clac_list_a(list_t *l)
{
    if (l->list_a[0] > l->list_a[1] && l->size_a != 1)
        swap_sa(l);
    if ((l->list_a[0] > l->list_a[l->size_a - 1]) && l->size_a != 1)
        swap_ra(l);
    else
        swap_pb(l);
}

void calc_list_b(list_t *l)
{
    if (l->list_b[0] < l->list_b[1] && l->size_b != 1)
        swap_sb(l);
    if ((l->list_b[0] < l->list_b[l->size_b - 1]) && l->size_b != 1)
        swap_rb(l);
    else
        swap_pa(l);
}
