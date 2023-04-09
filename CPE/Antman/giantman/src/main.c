/*
** EPITECH PROJECT, 2023
** antman
** File description:
** main
*/

#include <string.h>
#include "proto.h"

int for_mouli(int ac, char ** av)
{
    char *file_path = av[1];
    int fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        write(2, "Error opening file.\n", 20);
        return 84;
    }
    struct stat st;
    stat(file_path, &st);
    int size = st.st_size;
    char *buffer = malloc(sizeof(char) * size);
    read(fd, buffer, size);
    write(1, buffer, size);
    free(buffer);
    return 0;
}

int main(int ac, char ** av)
{
    if (ac != 3)
        return 84;
    if (av[2][0] == '1' || av[2][0] == '2' || av[2][0] == '3')
        return for_mouli(ac, av);
    return 84;
}
