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

int check_char(char c)
{
    if (c != '*' && c != 'X' && c != '\n') {
        printf("The maze must only contain *, X and \\n\n");
        return 84;
    }
    return 0;
}

int check_loop(char **maze, int i)
{
    for (int j = 0; maze[i][j] != '\0'; j++) {
        if (check_char(maze[i][j]) == 84)
            return 84;
    }
    return i;
}

int check_maze(char **maze)
{
    int x = 0; int y = 0;
    if (maze[0][0] != '*') {
        printf("The maze must start with a *\n");
        return 84;
    }
    for (int i = 0; maze[i] != NULL; i++) {
        for (int j = 0; maze[i][j] != '\0'; j++)
        x = j;
        y = i;
    }
    if (maze[y][x] != '*') {
        printf("The maze must end with a *\n");
        return 84;
    }
    for (int i = 0; maze[i] != NULL; i++) {
        i = check_loop(maze, i);
        if (i == 84)
            return 84;
    }
    return 0;
}
