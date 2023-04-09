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

int alphax(char *base, int nb, int size, int alpha)
{
    if (size > 10 && base[10] == 'a')
        return alpha = 87;
    else
        return alpha = 55;
}

void display(char *test, int len)
{
    my_revstr(test);
    my_putchar('\\');
    len = my_strlen(test);
    for (len; len < 3; len++)
        my_putchar('0');
    my_putstr(test);
}

int my_put_nbr_base_hex(int nb, char *base)
{
    int size = my_strlen(base);
    int result, i = 0;
    int len = 0;
    char test[10000];
    int alpha;

    alpha = alphax(base, nb, size, alpha);
    while (nb != 0) {
        if (nb % size + 48 >= '0' && nb % size + 48 <= '9')
            test[i] = (nb % size) + 48;
        else
            test[i] = (nb % size) + alpha;
        nb = nb / size;
        i++;
    }
    test[i + 1] = '\0';
    display(test, len);
    return i;
}
