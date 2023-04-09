/*
** EPITECH PROJECT, 2022
** error_case.c
** File description:
** error_case
*/

#include "../include/my.h"
#include "../include/list.h"

int check_sort(list_t *l)
{
    int i = 0;
    if (l->size_b > 0)
        return 0;
    while (i < l->size_a - 1) {
        if (l->list_a[i] > l->list_a[i + 1]) {
            return 0;
        }
        i++;
    }
    return 1;
}
