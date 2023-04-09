/*
** EPITECH PROJECT, 2023
** my_print_comb2
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int y = 0;
    int mul = 1;
    long nb = 0;

    for (int i = 0 ; str[i] == 43 || str[i] == 45 ; i++) {
        if (str[i] == 45)
            mul = -1;
        else
            mul = 1;
    }
    y = i;
    for (int y = 0 ; str[y] >= 48 && str[y] <= 57 ; y++) {
        nb = nb * 10;
        nb = nb + (str[y] - 48);
        if ((y - i) > 11 || nb > 2147483648)
            return 0;
    }
    return (nb * mul);
}
