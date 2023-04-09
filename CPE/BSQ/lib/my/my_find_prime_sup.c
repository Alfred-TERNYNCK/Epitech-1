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

int my_find_prime_sup(int nb)
{
    int i = 0;
    int prime = 1;

    if (nb == 1 || nb == 0) {
        my_put_nbr(2);
        return 0;
    }
    for (i = 2; i < nb; i++) {
        if ((nb % i) == 0) {
            prime = 0;
        }
    }
    if (prime == 1)
        my_put_nbr(nb);
    else
        my_find_prime_sup(nb + 1);
    return 0;
}
