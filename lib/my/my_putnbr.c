/*
** EPITECH PROJECT, 2020
** put nbr
** File description:
** print an int
*/

int my_compute_power_rec(int a, int n);

void my_putchar(char c);

int my_getlen(int a)
{
    int len = 0;

    if (a > 0)
        while (a > 0) {
            a = a / 10;
            len++;
        }
    else
        while (a < 0) {
            a = a / 10;
            len++;
        }
    return (len);
}

int my_abs(int nb)
{
    int len = 0;

    if (nb < 0) {
        nb = nb - (2 * nb);
        my_putchar(45);
    }
    return (nb);
}

void my_put_nbr(int nb)
{
    int len = my_getlen(nb) - 1;
    int print = 0;
    int a = nb;

    nb = my_abs(nb);
    while (len > 0) {
        print = nb / my_compute_power_rec(10, len);
        my_putchar(print + 48);
        nb = nb - print * my_compute_power_rec(10, len);
        len--;
    }
    my_putchar(nb + 48);
    my_putchar('\n');
}
