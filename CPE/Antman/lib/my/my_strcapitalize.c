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

int is_not_alphanum(char c)
{
    if (c >= 'a' && c <= 'z')
        return 0;
    if (c >= 'A' && c <= 'Z')
        return 0;
    if (c >= '0' && c <= '9')
        return 0;
    return 1;
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] == ' ' || i == 0)) {
            str[i] = str[i] - 32;
            i++;
        }
        if (str[i] >= 'A' && str[i] <= 'Z' && (is_not_alphanum(str[i]) == 0)) {
            str[i] = str[i] + 32;
            i++;
        }
    }
    return str;
}
