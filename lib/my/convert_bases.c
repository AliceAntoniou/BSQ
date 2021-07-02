/*
** EPITECH PROJECT, 2020
** convert base
** File description:
** change the base of a nbr
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

void setnums(char const *base, unsigned int i, char *dest)
{
    int j = 0;
    int len = my_strlen(base);

    while (i >= len) {
        j++;
        i = i - len;
    }
    dest[0] = base[i];
    if (j > 0) {
        setnums(base, j, dest + 1);
    }
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int p = my_strlen(nbr);
    int a = 0;
    unsigned int dec = 0;
    char *rt = malloc(sizeof(char) * sizeof(char));

    for (int i = 0; a < my_strlen(nbr); a++){
        while (nbr[a] != base_from[i]) {
            i++;
        }
        p--;
        dec = dec + i * my_power(10, p);
        i = 0;
    }
    setnums(base_to, dec, rt);
    return (my_evil_str(rt));
}