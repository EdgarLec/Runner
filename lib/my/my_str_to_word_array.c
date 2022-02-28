/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int alpha_num(char n)
{
    if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
        return 1;
    if (n >= '0' && n <= '9')
        return 1;
    return 0;
}

static int word(char const *str, char **to_retrn, int n)
{
    char *in_to_rt;
    int i = 0;
    int j = 0;

    while (!alpha_num(str[i]))
        i++;
    j = i;
    while (alpha_num(str[j]))
        j++;
    in_to_rt = malloc(sizeof(char) * j + 1);
    j = i;
    while (alpha_num(str[j])) {
        in_to_rt[j - i] = str[j];
        j++;
    }
    in_to_rt[my_strlen(in_to_rt)] = '\0';
    to_retrn[n] = in_to_rt;
    return j;
}

static int count(int *nb_wrd, char const *str)
{
    int bool = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha_num(str[i]) && !bool) {
            bool = 1;
            (*nb_wrd)++;
        }
        if (!alpha_num(str[i]) && bool)
            bool = 0;
    }
    return 0;
}

char **my_str_to_word_array(char const *str)
{
    char **to_retrn;
    int nb_wrd = 0;
    int i = 0;
    int j = 0;

    count(&nb_wrd, str);
    to_retrn = malloc(sizeof(char *) * (nb_wrd + 1));
    while (j < nb_wrd) {
        i += word(str + i, to_retrn, j);
        j++;
    }
    to_retrn[j] = 0;
    return to_retrn;
}
