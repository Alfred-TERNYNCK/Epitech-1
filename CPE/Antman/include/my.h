/*
** EPITECH PROJECT, 2023
** lib
** File description:
** include
*/

#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_

void my_putchar(char);
char *my_strstr(char *, char const *);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_put_nbr_base(int, char *);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char const *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
int error_c1_possitive(int nb);
int error_c1_negative(int nb);
int get_len(int nb);
char my_char_isalpha(char c);
int get_params_float_flag(char, int, int *, int *);
int my_putstr_plus(char *str);
int my_char_isprintable(char str);
int power_function(int);
char *convert_float_to_int(float, int);
int abs_function(int);
int my_put_nbr_base_hex(int, char *);
char **my_str_to_word_array(char *str);
char **my_str_to_word_array_giantman(char *str);
char **my_str_to_word_array_giantman2(char *str);
char **my_str_to_word_array_no_dest(char *str);
char **my_str_to_word_array_param(char *str, char *param);
int is_a_number(char *str);

#endif
