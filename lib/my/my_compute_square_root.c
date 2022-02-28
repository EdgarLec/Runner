/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** return square root
*/
#include <unistd.h>
#include <stdio.h>

static int loop5(int nb, int i)
{
    if (i * i == nb) {
        return i;
    }
    if (i <= nb) {
        i++;
        i = loop5(nb, i);
    }
    if (i * i == nb) {
        return i;
    }
    return 0;
}

int my_compute_square_root(int nb)
{
    int to_return;

    to_return = loop5(nb, 0);
    return to_return;
}
