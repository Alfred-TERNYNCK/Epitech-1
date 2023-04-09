/*
** EPITECH PROJECT, 2023
** my_print_comb2
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void my_putchar(char c);

int error_c1_possitive(int nb)
{
    int len = 0;

    while (0 == 0) {
        if (nb <= 9) {
            return len;
        }
        len++;
        nb = nb / 10;
    }
}

int error_c1_negative(int nb)
{
    int len = 0;

    while (0 == 0) {
        if (nb >= -9) {
            return len;
        }
        len ++;
        nb = nb / 10;
    }
}

int get_len(int nb)
{
    int len = 0;

    if (nb >= 0) {
        len = error_c1_possitive(nb);
        return len;
    } else {
        len = error_c1_negative(nb);
        return len;
    }
}

int my_put_nbr(int nb)
{
    int len = get_len(nb);

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        if (nb == -2147483648) {
            write(1, "2147483648", 10);
            return 0;
        }
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    } else {
        my_putchar(nb + 48);
    }
    return len;
}
