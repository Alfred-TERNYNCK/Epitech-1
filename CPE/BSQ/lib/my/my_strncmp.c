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

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    for (i = 0; s1[i] != '\0' || s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i] && s1[i] > s2[i] && i < n)
            return 1;
        if (s1[i] != s2[i] && s1[i] < s2[i] && i < n)
            return -1;
        if (s1[i] == s2[i] && i + 1 == n) {
            return 0;
        }
    }
}
