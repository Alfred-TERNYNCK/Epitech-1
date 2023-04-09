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

void print_maze(char ** maze)
{
    for (int i = 0; maze[i]; i++)
        printf("%s\n", maze[i]);
}

int nb_line(char * file)
{
    FILE *fd = fopen(file, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int nb_line = 0;
    while ((read = getline(&line, &len, fd)) != -1) {
        nb_line++;
    }
    fclose(fd);
    return nb_line;
}

char ** open_file(char *file, struct solver *s)
{
    s->y = nb_line(file);
    struct stat st;
    stat(file, &st);
    FILE *fd = fopen(file, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **maze = malloc(sizeof(char *) * (s->y + 1));
    int i = 0;
    s->x = st.st_size / s->y - 1;
    while ((read = getline(&line, &len, fd)) != -1) {
        maze[i] = malloc(sizeof(char) * s->x + 1);
        for (int j = 0; j < s->x; j++) {
            maze[i][j] = line[j];
        }
        maze[i][s->x] = '\0';
        i++;
    }
    maze[i] = NULL;
    return maze;
}

int nb_point(struct solver *s)
{
    int nb = 0;
    for (int i = 0; i < s->y; i++)
        for (int j = 0; j < s->x; j++)
            nb += (s->maze[i][j] == '*') ? 1 : 0;
    return nb;
}

int nb_option(struct solver *s, int x, int y)
{
    int nb = 0;
    if (x + 1 < s->x && s->maze[y][x + 1] == '*')
        nb++;
    if (x - 1 >= 0 && s->maze[y][x - 1] == '*')
        nb++;
    if (y + 1 < s->y && s->maze[y + 1][x] == '*')
        nb++;
    if (y - 1 >= 0 && s->maze[y - 1][x] == '*')
        nb++;
    return nb;
}
