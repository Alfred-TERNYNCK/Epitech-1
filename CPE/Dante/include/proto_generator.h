/*
** EPITECH PROJECT, 2023
** dante
** File description:
** proto_generator
*/

#include "struct.h"

#ifndef PROTO_GENERATOR_H_
    #define PROTO_GENERATOR_H_

int main(int ac, char ** av);
void print_maze(char ** maze);
char ** create_empty_maze(int x, int y);
int * get_random_pos(void);
int * full_zero(struct data * d);
int nb_valide_move(struct data * d);
int * get_random_move(struct data * d);
int get_direction(struct data * d);
char ** x_around_dir_ver(struct data * d, int dir);
char ** x_around_dir_hor(struct data * d, int dir);
char ** x_around_last_pos(struct data * d);
void advance(struct data * d);
int nb_unvisited_square(struct data * d);
int is_close_star(struct data * d, int i, int j);
int is_close_path(struct data * d, int i, int j);
int get_new_start_pos_second(struct data * d, int * pos, int i);
int * get_new_start_pos(struct data * d);
char ** create_maze(struct data * d);
char ** verifie_last_square(struct data * d);
char ** remove_point(struct data * d);

#endif /* !PROTO_GENERATOR_H_ */
