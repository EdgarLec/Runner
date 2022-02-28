/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write number
*/
#include <unistd.h>
#include "my.h"

static int reverse(int number, int *j)
{
    int i;
    if (number != 0) {
        i = number % 10;
        if (i < 0) {
            i = -i;
        }
        number /= 10;
        reverse(number, j);
        my_putchar(i + 48);
    }
    (*j)++;
    return *j;
}

int my_put_nbr(int nb)
{
    int j = 0;
    if (nb < 0) {
        my_putchar('-');
        j++;
    }
    if (nb == 0) {
        my_putchar('0');
        j++;
    }
    reverse(nb, &j);
    return j - 1;
}

int my_size_nbr(int nb)
{
    int j = 0;
    for (; nb != 0; nb /= 10, j++);
    return j;
}

int my_size_nbr_base(int nb, int size)
{
    int j = 0;
    for (; nb != 0; nb /= size, j++);
    return j;
}
