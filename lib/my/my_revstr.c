/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverse str
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tempo;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    while (j < i) {
        tempo = str[i];
        str[i] = str[j];
        str[j] = tempo;
        j++;
        i--;
    }
    return str;
}
