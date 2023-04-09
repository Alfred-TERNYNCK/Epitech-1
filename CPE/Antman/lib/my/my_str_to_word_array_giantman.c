/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int my_strlen(char *str);

int is_printable2(char c)
{
    if (c != ' ' && c != '\t' && c != '\n' && c != '\0' &&
    c != '\r' && c != '\v' && c != '\f' && c != '&' && c != '@')
        return 1;
    return 0;
}

int nb_words2(char *str)
{
    int i = 0; int count = 0;

    for (; str[i] != '\0'; i++) {
        if (is_printable2(str[i]) == 1 && is_printable2(str[i + 1]) == 0)
            count++;
    }
    return count;
}

int len_word2(char *str)
{
    int i = 0;
    for (; is_printable2(str[i]) == 1; i++);
    return i + 1;
}

char **feed_tab2(char *str, char **tab)
{
    int i = 0; int x = 0; int y = 0; int l_word = 0;

    for (;str[i] != '\0';) {
        for (;is_printable2(str[i]) == 0; i++);
        l_word = len_word2(str + i);
        tab[x] = malloc(sizeof(char) * l_word);
        for (;l_word > 1; l_word--) {
            tab[x][y] = str[i];
            y++;
            i++;
        }
        tab[x][y] = '\0';
        y = 0;
        x++;
    }
    tab[x] = NULL;
    return tab;
}

char **my_str_to_word_array_giantman(char *str)
{
    if (nb_words2(str) == 0)
        return NULL;

    int nb_word = nb_words2(str);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));

    tab = feed_tab2(str, tab);
    return tab;
}
