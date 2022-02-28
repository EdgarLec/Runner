/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** my_show_word_array.c
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
