/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** swap int
*/
#include <unistd.h>

void my_swap(int *a, int *b)
{
    int x;

    x = *a;
    *a = *b;
    *b = x;
}
