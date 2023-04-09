/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    if (p < 0)
        return 0;
    return nb * my_compute_power_rec(nb, p - 1);
}
