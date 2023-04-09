/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char my_char_isalpha(char c)
{
    if (c < 'A' || c > 'Z' && c < 'a' || c > 'z')
        return 1;
    return 0;
}
