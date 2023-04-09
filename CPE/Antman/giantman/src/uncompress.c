/*
** EPITECH PROJECT, 2023
** antman
** File description:
** giantman
*/

#include "proto.h"

char *uncompress2(char *str)
{
    char *new_str = NULL;
    new_str = malloc(sizeof(char) * my_strlen(str) * 2 + 1);
    int i = 0;
    int j = 0;
    for (; str[i + 1] != '\0'; i++, j++) {
        if (str[i] == '&') {
            new_str[j] = str[i];
            j++;
            i++;
            new_str[j] = str[i];
            j++;
            new_str[j] = ' ';
        } else
            new_str[j] = str[i];
    }
    new_str[j] = '\0';
    return new_str;
}

char *uncompress(char *str)
{
    char *new_str = NULL;
    new_str = malloc(sizeof(char) * my_strlen(str) * 2 + 1);
    int i = 0;
    int j = 0;
    for (; str[i + 1] != '\0'; i++, j++) {
        if (str[i] == '@' && str[i + 1] != ' ') {
            new_str[j] = str[i];
            j++;
            new_str[j] = ' ';
        } else
            new_str[j] = str[i];
    }
    new_str[j] = '\0';
    return new_str;
}
