/*
** EPITECH PROJECT, 2023
** dante
** File description:
** utils
*/

#include "proto_generator.h"

void print_maze(char ** maze)
{
    for (int i = 0; maze[i]; i++)
        printf("%s\n", maze[i]);
}

char ** create_empty_maze(int x, int y)
{
    char ** maze = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y; i++) {
        maze[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j < x; j++)
            maze[i][j] = '.';
        maze[i][x] = '\0';
    }
    maze[y] = NULL;
    return maze;
}

int * full_zero(struct data * d)
{
    d->list_move_pos[0] = 0;
    d->list_move_pos[1] = 0;
    d->list_move_pos[2] = 0;
    d->list_move_pos[3] = 0;
    return d->list_move_pos;
}
