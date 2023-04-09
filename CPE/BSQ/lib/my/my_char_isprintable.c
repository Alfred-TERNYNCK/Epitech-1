/*
** EPITECH PROJECT, 2022
** lib/my/my_char_isprintable
** File description:
** there's a problem: the intra is not down
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

int my_char_isprintable(char str)
{
    if (str < 32 || str == 127)
        return 1;
    return 0;
}
