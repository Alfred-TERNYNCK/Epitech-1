/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** struct.h
*/

#include <stdlib.h>

#ifndef LIST_H_
    #define LIST_H_

typedef struct list {
    int *list_a;
    int *list_b;
    int size_a;
    int size_b;
    int j;
    int s;
    int x;
    int cmp;
} list_t;

int check_sort(list_t *l);
int is_arg_is_number(int ac, char **av);
void calc(list_t *l);
void clac_list_a(list_t *l);
void calc_list_b(list_t *l);
void init_calc(int ac, char **av);
void display_result(list_t *l);
list_t *swap_pa(list_t *l);
list_t *swap_pb(list_t *l);
list_t *swap_sa(list_t *l);
list_t *swap_ra(list_t *l);
list_t *swap_rb(list_t *l);
list_t *swap_sb(list_t *l);

#endif
