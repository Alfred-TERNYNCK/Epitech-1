/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

int my_str_isupper(char const *str)
{
    int i = 0;
    if (str == NULL)
        return 1;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
    return 1;
}
