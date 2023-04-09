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

void return_last_node(struct solver *s)
{
    while (nb_option(s, s->cx, s->cy) == 0) {
        advance_return(s);
    }
}

void del_last_node(struct solver *s)
{
    struct list_chained *tmp = s->list;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->prev->next = NULL;
    free(tmp);
}

void create_new_node(struct solver *s)
{
    struct list_chained *new = malloc(sizeof(struct list_chained));
    struct list_chained *last = s->list;
    for (; last->next != NULL; last = last->next);
    new->x = s->cx;
    new->y = s->cy;
    new->next = NULL;
    new->prev = last;
    new->last_opt = nb_option(s, s->cx, s->cy);
    new->current_opt = 1;
    last->next = new;
}
