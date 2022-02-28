/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** find a prime number
*/
#include <unistd.h>
#include <stdio.h>

static int verif_prime2(int i, int nb)
{
    for (int j = 2; j < nb; j++) {
        if (i * j == nb) {
            return 0;
        }
    }
    return 1;
}

static int my_is_prime2(int nb)
{
    int to_return;

    if (nb == 0 || nb == 1) {
        return 0;
    }
    for (int i = 2; i < nb; i++) {
        to_return = verif_prime2(i, nb);
        if (to_return == 0) {
            return 0;
        }
    }
    return 1;
    return to_return;
}

int my_find_prime_sup(int nb)
{
    if (nb < 2) {
        return 2;
    }
    while (!my_is_prime2(nb)) {
        nb++;
    }
    return nb;
}
