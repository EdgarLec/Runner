/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** strcmp
*/

static int size(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0') {
        i++;
    }
    while (s2[j] != '\0') {
        j++;
    }
    if (i < j) {
        return -1;
    }
    if (i > j) {
        return 1;
    }
    return 0;
}

int my_strcmp(char const *s1 , char const *s2)
{
    int i = 0;

    if (size(s1, s2) != 0)
        return size(s1, s2);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            return -1;
        }
        if (s1[i] > s2[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}
