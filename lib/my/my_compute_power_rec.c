/*
** EPITECH PROJECT, 2021
** my_compute_power_rec.c
** File description:
** return power rec
*/
#include <unistd.h>
#include <stdio.h>

int my_compute_power_rec(int nb , int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0 || nb == 0) {
        return 0;
    }
    if (p > 1) {
        return nb = (nb * my_compute_power_rec(nb, p - 1));
    }
    return nb;
}
