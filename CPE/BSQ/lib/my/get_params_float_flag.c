/*
** EPITECH PROJECT, 2022
** lib/my/get_params_float_flag
** File description:
** vim > emacs
*/

int get_params_float_flag(char format, int current, int *first, int *second)
{
    if (format >= '0' && format <= '9') {
        if (current == 0) {
            *first = *first * 10 + (format - 48);
        }
        if (current == 1) {
            *second = *second *10 + (format -48);
        }
    }
    if (format == '.') {
        current = 1;
        *second = 0;
    }
    return current;
}
