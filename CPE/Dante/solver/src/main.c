/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "solver.h"

int main (int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./solver maze.txt\n");
        return 84;
    }
    return solver(argv[1]);
}
