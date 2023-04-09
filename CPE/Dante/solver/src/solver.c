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

void advance_return(struct solver *s)
{
    if (s->cx + 1 < s->x && s->maze[s->cy][s->cx + 1] == 'o')
        s->cx++;
    if (s->cx - 1 >= 0 && s->maze[s->cy][s->cx - 1] == 'o')
        s->cx--;
    if (s->cy + 1 < s->y && s->maze[s->cy + 1][s->cx] == 'o')
        s->cy++;
    if (s->cy - 1 >= 0 && s->maze[s->cy - 1][s->cx] == 'o')
        s->cy--;
    s->maze[s->cy][s->cx] = '.';
    return;
}

void advance(struct solver *s)
{
    if (s->cx + 1 < s->x && s->maze[s->cy][s->cx + 1] == '*')
        s->cx++;
    if (s->cx - 1 >= 0 && s->maze[s->cy][s->cx - 1] == '*')
        s->cx--;
    if (s->cy + 1 < s->y && s->maze[s->cy + 1][s->cx] == '*')
        s->cy++;
    if (s->cy - 1 >= 0 && s->maze[s->cy - 1][s->cx] == '*')
        s->cy--;
    s->maze[s->cy][s->cx] = 'o';
    return;
}

char ** explore(struct solver *s)
{
    s->cx = s->list->x;
    s->cy = s->list->y;
    while (nb_point(s) > 0) {
        int opt = nb_option(s, s->cx, s->cy);
        if (s->cx == s->x - 1 && s->cy == s->y - 1)
            return s->maze;
        if (opt == 0) {
            return_last_node(s);
        }
        if (opt != 0)
            advance(s);
    }
    return s->maze;
}

int solver(char *file)
{
    struct solver *s = malloc(sizeof(struct solver));
    s->list = malloc(sizeof(struct list_chained));
    s->list->x = 0;
    s->list->y = 0;
    s->list->last_opt = 0;
    s->list->current_opt = 0;
    s->list->prev = NULL;
    s->list->next = NULL;
    s->maze = open_file(file, s);
    if (s->maze == NULL || check_maze(s->maze) == 84)
        return 84;
    s->maze = explore(s);
    print_maze(s->maze);
    return 0;
}
