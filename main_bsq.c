/*
** EPITECH PROJECT, 2020
** step 1
** File description:
** accès au file
*/

#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int max_square_size(char **map, int row, int col);

int pass_nbr(char *str);

int my_array_len(char **array);

char **malloc_array(char *str)
{
    int x = 0;
    int y = 0;
    int k = 0;
    int i = 0;
    int j = 0;
    char **array = 0;

    x = count_x(str);
    y = count_y(str);
    array = malloc(sizeof(char *) * (y + 2));
    while (i < y) {
        array[i] = malloc(sizeof(char) * (x + 2));
        for (j = 0; j < x + 1; j++) {
            array[i][j] = str[k];
            k++;
        }
        array[i][j] = '\0';
        i++;
    }
    array[i] = NULL;
    return (array);
}

char **load_2d_arr_from_file(char  const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str = 0;
    struct stat buf;

    stat(filepath, &buf);
    str = malloc(sizeof(char) * (buf.st_size + 1));
    while (read(fd, str, buf.st_size) < buf.st_size) {}
    str[buf.st_size] = '\0';
    close(fd);
    my_strcpy(str, str + pass_nbr(str));
    return (malloc_array(str));
}

int print_square_of_size(char **map, int row, int col, int square_size)
{
    int size = 0;
    int len = my_strlen(map[0]);

    while (size <= square_size) {
        for (int i = size + row; i >= row; i--)
            if (map[col + size][i] == '.')
                map[col + size][i] = 'x';
        for (int j = size + col - 1; j >= col; j--)
            if (map[j][row + size] == '.')
                map[j][row + size] = 'x';
        size++;
    }
    for (int i = 0; map[i] != NULL; i++) {
        write(1, map[i], len);
        free(map[i]);
    }
    free(map);
    return (0);
}

int bsq(char *file)
{
    char **str = load_2d_arr_from_file(file);
    int coord[3] = {0, 0};
    int y = my_array_len(str);
    int x = my_strlen(str[0]) - 1;
    int size = 0;
    int size_max = 0;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            size = max_square_size(str, j, i);
            if (size > size_max) {
                coord[0] = j;
                coord[1] = i;
                size_max = size;
            }
        }
    }
    print_square_of_size(str, coord[0], coord[1], size_max - 1);
    return (0);
}

int main(int ac, char **av)
{
    int fd = 0;
    char str[2];

    if (ac != 2)
        return (84);
    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        close(fd);
        return (84);
    }
    read(fd, str, 1);
    if (my_char_isnum(str[0]) == 0)
        return (84);
    close(fd);
    return (bsq(av[1]));
}