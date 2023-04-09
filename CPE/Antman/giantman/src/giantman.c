/*
** EPITECH PROJECT, 2023
** antman
** File description:
** giantman
*/

#include "proto.h"

void open_the_file(struct data *d)
{
    struct stat st;
    d->fd = open(d->file_path, O_RDONLY);
    stat(d->file_path, &st);
    d->file = malloc(sizeof(char) * st.st_size);
    read(d->fd, d->file, st.st_size - 1);
    close(d->fd);
}

char *add_spaces(char *str)
{
    char *new_str = NULL;
    new_str = malloc(sizeof(char) * my_strlen(str) * 2 + 1);
    int i = 0;
    int j = 0;
    int x = 0;
    for (; str[i] != '\0'; i++, j++) {
        if (str[i] == '$')
            x++;
        if (str[i] == '.' || str[i] == ',' || str[i] == '?'
        || str[i] == '!' && x == 0) {
            new_str[j] = str[i];
            j++;
            new_str[j] = ' ';
        } else
            new_str[j] = str[i];
    }
    new_str[j] = '\0';
    return new_str;
}

char *add_spaces2(char *str)
{
    char *new_str = NULL;
    new_str = malloc(sizeof(char) * my_strlen(str) * 2 + 1);
    int i = 0;
    int j = 0;
    for (; str[i] != '\0'; i++, j++) {
        if ((str[i + 1] == '@' || str[i + 1] == '&') && str[i] != ' ') {
            new_str[j] = str[i];
            j++;
            new_str[j] = ' ';
        } else
            new_str[j] = str[i];
    }
    new_str[j] = '\0';
    return new_str;
}

int giantman(char **av)
{
    struct data * d;
    d = malloc(sizeof(struct data));
    d->file_path = av[1];
    open_the_file(d);
    d->file = add_spaces(d->file);
    d->file = add_spaces2(d->file);
    d->file = uncompress(d->file);
    d->file = uncompress2(d->file);
    d->file = convert_index(d->file);
    d->words = my_str_to_word_array(d->file);
    my_putstr(d->file);
    return 0;
}
