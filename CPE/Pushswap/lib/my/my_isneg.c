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

int my_isneg(int n)
{
    char a = 'P';
    char b = 'N';

    if (n < 0)
        my_putchar(b);
    else if (n >= 0)
        my_putchar(a);
    return 0;
}
