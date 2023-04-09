/*
** EPITECH PROJECT, 2023
** my_put_nbr_base
** File description:
** print a number
*/
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void my_putchar(char c);

int my_strlen(char const *str);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int my_put_nbr_base(int nb, char *base)
{
    int size = my_strlen(base);
    int result, i = 0;
    char test[10000]; int alpha;

    if (size > 10 && base[10] == 'a')
        alpha = 87;
    else
        alpha = 55;
    while (nb != 0) {
        if (nb % size + 48 >= '0' && nb % size + 48 <= '9')
            test[i] = (nb % size) + 48;
        else
            test[i] = (nb % size) + alpha;
        nb = nb / size;
        i++;
    }
    test[i + 1] = '\0';
    my_revstr(test);
    my_putstr(test);
    return i;
}
