/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** char * my_revstr ( char * str ) ;
*/
int my_strlen(char const *str);

char * my_revstr ( char * str )
{
    int len = my_strlen(str);
    int last = len - 1;
    int first = 0;
    int temp;

    while ( last > first) {
        temp = str[first];
        str[first] = str[last];
        str[last] = temp;
        last--;
        first++;
    }
    return str;
}
