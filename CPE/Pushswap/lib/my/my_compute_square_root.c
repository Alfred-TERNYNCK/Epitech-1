/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    if (nb <= 0)
        return 0;
    for (int i = 1; i < nb; i++)
        if (i * i == nb)
            return i;
    return 0;
}
