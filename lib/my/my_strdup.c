/*
** EPITECH PROJECT, 2020
** my str dup
** File description:
** alloc memory for a str
*/

#include <stdlib.h>

int my_strlen(const char *str);

char *my_strdup(char const *src)
{
    char *dest;
    int len = my_strlen(src);
    int i = 0;

    dest = malloc(sizeof(char) * (len + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
