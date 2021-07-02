/*
** EPITECH PROJECT, 2020
** my put str
** File description:
** reverse the string
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    int j = len - 1;
    char rts[len];

    for (int a = 0; a < len; a++)
        rts[a] = str[a];
    while (i < len) {
        str[i] = rts[j];
        i++;
        j--;
    }
    return (str);
}
