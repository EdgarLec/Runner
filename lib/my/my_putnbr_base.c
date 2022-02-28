/*
** EPITECH PROJECT, 2021
** my_putnbr_base.c
** File description:
** putnbr_base
*/
#include "my.h"

static int reverse(unsigned int number, char const *base, int size, int *j)
{
    int i;
    if (number != 0) {
        i = number % (size + 1);
        if (i < 0) {
            i = -i;
        }
        number /= (size + 1);
        reverse(number, base, size, j);
        my_putchar(base[i]);
        (*j)++;
    }
    return 0;
}

int my_putnbr_base(unsigned int nbr, char const *base)
{
    int i = 0;
    int j = 0;
    while (base[i] != '\0') {
        i++;
    }
    i--;
    if (nbr == 0) {
        my_putchar('0');
    }
    reverse(nbr, base, i, &j);
    return j;
}

static int rev_l(unsigned long int number, char const *base, int size, int *j)
{
    int i;
    if (number != 0) {
        i = number % (size + 1);
        if (i < 0) {
            i = -i;
        }
        number /= (size + 1);
        rev_l(number, base, size, j);
        my_putchar(base[i]);
        (*j)++;
    }
    return 0;
}

int my_putnbr_base_long(unsigned long int nbr, char const *base)
{
    int i = 0;
    int j = 0;
    while (base[i] != '\0') {
        i++;
    }
    i--;
    if (nbr == 0) {
        my_putchar('0');
    }
    rev_l(nbr, base, i, &j);
    return j;
}

int mod_p(unsigned long int nbr)
{
    int j = 0;
    if (nbr == 0) {
        my_putstr("(nil)");
        return 5;
    }
    my_putstr("0x");
    j = my_putnbr_base_long(nbr, "0123456789abcdef") + 2;
    return j;
}
