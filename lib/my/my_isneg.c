/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** write P or N
*/

#include <unistd.h>
#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
