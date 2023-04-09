/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int is_a_number(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i++;
    }
    return 0;
}
