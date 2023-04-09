/*
** EPITECH PROJECT, 2023
** my_print_comb2
** File description:
** print a char into console
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void my_sort_int_array_help(int j, int size, int i, int *array)
{
    int temp;

    while (j < size) {
        if (array[i] > array[j]) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        j++;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;

    while (i < size) {
        j = i + 1;
        my_sort_int_array_help(j, size, i, array);
        i++;
    }
}
