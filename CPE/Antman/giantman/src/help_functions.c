/*
** EPITECH PROJECT, 2023
** antman
** File description:
** giantman
*/

#include <math.h>
#include "proto.h"

int is_number(int x)
{
    if (x >= 0 && x <= 9)
        return 1;
    else
        return 0;
}

char *my_realloc(char *str, int size)
{
    char *new_str = malloc(sizeof(char) * size);
    int i = 0;
    for (; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return new_str;
}

int my_intlen(int i)
{
    int j = 0;
    for (; i != 0; j++)
        i = i / 10;
    return j;
}

char *my_itoa(int nb)
{
    int i = 0;
    int j = 0;
    int nb2 = nb;
    char *str = NULL;
    for (; nb2 != 0; i++)
        nb2 = nb2 / 10;
    str = malloc(sizeof(char) * i + 1);
    for (; nb != 0; j++) {
        str[j] = nb % 10 + '0';
        nb = nb / 10;
    }
    str[j] = '\0';
    str = my_revstr(str);
    return str;
}

int base62_to_decimal(char* base62)
{
    int decimal = 0;
    int len = my_strlen(base62);
    for (int i = 0; i < len; i++) {
        int digit = base62[i];
        if (digit >= '0' && digit <= '9')
            digit = digit - '0';
        if (digit >= 'A' && digit <= 'Z')
            digit = digit - 'A' + 10;
        if (digit >= 'a' && digit <= 'z')
            digit = digit - 'a' + 36;
        decimal += digit * pow(62, len - i - 1);
    }
    return decimal;
}
