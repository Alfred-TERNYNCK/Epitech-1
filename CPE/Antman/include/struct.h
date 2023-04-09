/*
** EPITECH PROJECT, 2023
** antman
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

struct data {
    char * file_path;
    char * file;
    char ** words;
    char ** index;
    char ** words_set;
    char ** index_set;
    char * buffer;
    int * info;
    int fd;
};

#endif /* !STRUCT_H_ */
