/*
** EPITECH PROJECT, 2021
** my_sort_int_array.c
** File description:
** sort int in array
*/
#include <unistd.h>
#include <stdio.h>

static void my_sort_int_array2(int *array , int size, int i)
{
    int tempo = 0;

    for (int j = i + 1; j < size; j++) {
        if (array[i] > array[j]) {
            tempo = array[i];
            array[i] = array[j];
            array[j] = tempo;
        }
    }
}

void my_sort_int_array(int *array , int size)
{
    for (int i = 0; i < size - 1; i++) {
        my_sort_int_array2(array, size, i);
    }
}
