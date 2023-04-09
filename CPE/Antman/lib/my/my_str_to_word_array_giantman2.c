/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** print a char into console
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int my_strlen(char *str);

int is_printable3(char c)
{
    if (c != ';')
        return 1;
    return 0;
}

int nb_words3(char *str)
{
    int i = 0; int count = 0;

    for (; str[i] != '\0'; i++) {
        if (is_printable3(str[i]) == 1 && is_printable3(str[i + 1]) == 0)
            count++;
    }
    return count;
}

int len_word3(char *str)
{
    int i = 0;
    for (; is_printable3(str[i]) == 1; i++);
    return i + 1;
}

char **feed_tab3(char *str, char **tab)
{
    int i = 0; int x = 0; int y = 0; int l_word = 0;

    for (;str[i] != '\0';) {
        for (;is_printable3(str[i]) == 0; i++);
        printf("tt\n");
        l_word = len_word3(str + i);
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

char **my_str_to_word_array_giantman2(char *str)
{
    if (nb_words3(str) == 0)
        return NULL;
    int nb_word = nb_words3(str);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));

    tab = feed_tab3(str, tab);
    return tab;
}
