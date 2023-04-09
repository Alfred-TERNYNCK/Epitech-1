/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void my_putchar(char c);

int my_put_nbr(int nb);

int my_is_prime(int nb)
{
    int loop;
    int prime = 1;

    if (nb == 1 || nb == 0) {
        my_put_nbr(0);
        return 0;
    }
    for (loop = 2; loop < nb; loop++) {
        if ((nb % loop) == 0) {
            prime = 0;
        }
    }
    if (prime == 1)
        my_put_nbr(1);
    else
        my_put_nbr(0);
    return 0;
}
