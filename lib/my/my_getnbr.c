/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** return number from string
*/
#include <unistd.h>
#include <stdio.h>

static int full_nb(int neg, int j, char const *str)
{
    int tempo = 0;
    while (str[j] <= 57 && str[j] >= 48) {
        if (tempo > (2147483648 - (str[j] - 48)) / 10) {
            return 0;
        }
        if (neg == 1 && tempo > (2147483647 - (str[j] - 48)) / 10) {
            return 0;
        }
        tempo = tempo * 10 + (str[j] - 48);
        j++;
    }
    if (neg == 0) {
        tempo = -tempo;
    }
    return tempo;
}

static int to_int(char const *str)
{
    int i = 0;
    int end = 0;
    int toreturn = 0;
    int is_neg = 0;

    while (str[i] != '\0' && end == 0) {
        if (str[i] == '-') {
            is_neg++;
        }
        if (str[i] >= 48 && str[i] <= 57 && end == 0) {
            toreturn = full_nb(is_neg % 2 == 0, i, str);
            end = 1;
        }
        i++;
    }
    return toreturn;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int a = 0;
    int end2 = 0;

    while (a == 0) {
        if ((str[i] < 48 || str[i] > 57 ) && str[i] != 45 && str[i] != 43) {
            return 0;
        }
        if (str[i] >= 48 && str[i] <= 57) {
            end2 = to_int(str);
            a = 1;
        }
        i++;
    }
    return end2;
}
