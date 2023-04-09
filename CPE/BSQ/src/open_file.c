/*
** EPITECH PROJECT, 2022
** main for stumper
** File description:
** Final stumper C pool
*/

#include "my.h"
#include "proto.h"
#include "utils.h"

int fd_file(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        my_putstr("File not found\n");
        return 84;
    }
    return fd;
}

char *open_file(char *file)
{
    struct stat sb;
    stat(file, &sb);
    int buf_size = sb.st_size;
    char *buffer = malloc(sizeof(char) * buf_size + 1);
    int fd = fd_file(file);
    read(fd, buffer, buf_size - 1);
    buffer[buf_size] = '\0';
    close(fd);
    return buffer;
}
