/*
** EPITECH PROJECT, 2022
** lib/my/power_of_10
** File description:
** vim-epitech made by x4m3
*/

int power_function(int p)
{
    int total = 1;

    while (p != 0) {
        total = total * 10;
        p--;
    }
    return total;
}
