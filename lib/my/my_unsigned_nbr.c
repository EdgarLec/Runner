/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** Write number
*/
#include <unistd.h>
#include "my.h"

static unsigned int reverse(unsigned int number, int *j)
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

int my_put_unsnbr(unsigned int nb)
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
