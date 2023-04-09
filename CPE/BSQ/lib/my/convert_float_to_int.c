/*
** EPITECH PROJECT, 2022
** lib/my/convert_float_to_int
** File description:
** if you code on paper, you're not a real programmer
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"


int abs_function(int len)
{
    if (len < 0) {
        return len * - 1;
    } else {
        return len;
    }
}

char *convert_float_to_int(float f, int second)
{
    int result = 0; int a = 0; int len = 0; int i = 0;
    int power = 1;
    char *retur = NULL;
    len = second + get_len((int)(f)) + 1;
    retur = malloc(sizeof(char *) * len + 1);
    f = f / (power_function(get_len((int)(f))) * 10);
    if (f < 0) {
        retur[i] = 45;
        i++;
        a = 1;
    }
    for (; (a == 0 && i - 1 < len) || (a == 1 && i - 1 <= len); i++) {
        f = f * 10;
        retur[i] = (abs_function((int) (f / 1)) + 48);
        f = f - (int)(f);
    }
    return retur;
}
