/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** return 1 if prime
*/
#include <unistd.h>
#include <stdio.h>

static int verif_prime(int i, int nb)
{
    for (int j = 2; j < nb; j++) {
        if (i * j == nb) {
            return 0;
        }
    }
    return 1;
}

int my_is_prime(int nb)
{
    int to_return;

    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i < nb; i++) {
        to_return = verif_prime(i, nb);
        if (to_return == 0) {
            return 0;
        }
    }
    return 1;
}
