/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/
#ifndef MY_H
    #define MY_H
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <math.h>
    #include <time.h>
    #include <stdlib.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
int my_put_unsnbr(unsigned int nb);
int my_printf(char *str, ...);
int my_putnbr_base(unsigned int nbr, char const *base);
int my_putnbr_base_long(unsigned long int nbr, char const *base);
int mod_p(unsigned long int nbr);
int my_putstrbug(char const *str);
char *my_realloc(char *str, int size);
int is_in(char *str, char c);
int forint2(char *str2, int nbr, int i, int *flag);
int forint(char *str2, int nbr);
int my_size_nbr(int nb);
int fors(char *str2, char *argchar);
int forp(char *str2, unsigned long int nbr);
int forusi(char *str2, unsigned int nbr);
int my_size_nbr_base(int nb, int size);
void htag(char *str2);
int forc(char *str2, int c);
void my_forr(int *i, char *str);
void double_free(int size, char **str);

#endif
