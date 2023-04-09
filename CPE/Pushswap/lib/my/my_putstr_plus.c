/*
** EPITECH PROJECT, 2022
** lib/my/my_putstr_plus
** File description:
** :wq
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void my_putchar(char c);

int my_putstr_plus(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (my_char_isprintable(str[i]) == 0)
            my_putchar(str[i]);
        else
            my_put_nbr_base_hex(str[i], "01234567");
    return i;
}
