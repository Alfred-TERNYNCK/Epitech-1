/*
** EPITECH PROJECT, 2023
** lib
** File description:
** include
*/

#include "struct.h"

#ifndef SOLVER_H
    #define SOLVER_H

void print_maze(char ** maze);
int nb_line(char * file);
char ** open_file(char *file, struct solver *s);
int nb_point(struct solver *s);
void advance_return(struct solver *s);
void advance(struct solver *s);
void return_last_node(struct solver *s);
char ** explore(struct solver *s);
int solver(char *file);
void del_last_node(struct solver *s);
void create_new_node(struct solver *s);
int nb_option(struct solver *s, int x, int y);
int check_maze(char **maze);

#endif
