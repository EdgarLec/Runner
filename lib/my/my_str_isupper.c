/*
** EPITECH PROJECT, 2021
** my_str_isupper.c
** File description:
** only uppercase
*/

int my_str_isupper(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 90 && str[i] >= 65)
            i++;
        else
            return 0;
    }
    return 1;
}
