/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** fonctions
*/

#include "include/my.h"
#include <stdio.h>

int max_square_size(char **map, int row, int col)
{
    int size = 0;

    while (1) {
        for (int i = size + row; i >= row; i--) {
            if (map[col + size] == NULL)
                return (size);
            if (map[col + size][i] != '.')
                return (size);
        }
        for (int j = size + col - 1; j >= col; j--)
            if (map[j][row + size] != '.')
                return (size);
        size++;
    }
    return (0);
}

int my_array_len(char **array)
{
    int i = 0;

    while (array[i] != 0)
        i++;
    return (i);
}

int pass_nbr(char *str)
{
    int i = 0;

    while (my_char_isnum(str[i]) == 1) {
        i++;
    }
    return (i + 1);
}