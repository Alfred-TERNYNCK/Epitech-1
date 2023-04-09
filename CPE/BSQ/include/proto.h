/*
** EPITECH PROJECT, 2022
** proto
** File description:
** final stumper C pool
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "utils.h"

#ifndef PROTO_H_
    #define PROTO_H_

char *open_file(char *file);
int display_file(char **map);
int check_file(char **map);
int check_line(char **map);
int check_column(char **map);
int check_square(char **map);
int fd_file(char *file);
int start(map_t *map, int fd, char **av, int ac);
int feed_tab_int(map_t *map);
int feed_tab_char(map_t *map, int ac, char **av);
int feed_b(map_t *map, int fd, char **av);
int display_map(map_t *map);
void call_stats(map_t *map);
void check_char(map_t *map, int x);
void free_all_free(map_t *map);
void int_tab_to_char_tab(map_t *map);
void find_biggest_square(map_t *map);
void check_char_int(map_t *map, int x, int y, int j);
void square_stats(map_t *map, int x, int y);
void convertion_pos(map_t *map, int x, int y);
void small_int(map_t *map, int temp, int x, int y);
int feed_by_generator(map_t *map, char **av);
char *map_generator(map_t *map, char **av);
int display_map_generator(map_t *map);
int str_is_x(char **av);
char *map_generator(map_t *map, char **av);

#endif
