/*
** EPITECH PROJECT, 2023
** my_print_comb2
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
