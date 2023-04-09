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

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len = my_strlen(to_find);

    for (i = 0; str[i + len] != '\0'; i++) {
        if (my_strncmp(&str[i], to_find, len) == 0) {
            return &str[i];
        }
    }
    return NULL;
}
