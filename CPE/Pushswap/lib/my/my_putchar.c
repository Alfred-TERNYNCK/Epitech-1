/*
** EPITECH PROJECT, 2023
** my_print_comb2
** File description:
** print a char into console
*/

#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
