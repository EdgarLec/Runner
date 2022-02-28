/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include "include/my.h"
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "include/my_struct.h"

void place_light(all *pic, int i, int j)
{
    if (((rand() % 100) > 85 && (i != 6 && i != 0) &&
    pic->map[i - 1][j].type == 0)) {
        pic->map[i - 1][j].type = 2;
        sfSprite_setTexture(pic->map[i - 1][j].pic, pic->txtu.lights, sfTrue);
        sfSprite_setTextureRect(pic->map[i - 1][j].pic, (sfIntRect){0, 0, 160
        , 160});
        sfSprite_setScale(pic->map[i - 1][j].pic, (sfVector2f){1, 1});
    }
    if (((rand() % 100) > 85 && (i != 6 && i > 1) &&
    pic->map[i - 2][j].type == 0)) {
        pic->map[i - 2][j].type = 2;
        sfSprite_setTexture(pic->map[i - 2][j].pic, pic->txtu.lights, sfTrue);
        sfSprite_setTextureRect(pic->map[i - 2][j].pic, (sfIntRect){0, 0, 160
        , 160});
        sfSprite_setScale(pic->map[i - 2][j].pic, (sfVector2f){1, 1});
    }
}

void up_down_prcd(all *pic, int i, int j)
{
    if ((pic->map[i][j].pos.x < 220))
        pic->map[i][j].pos.y += 4;
    if ((pic->map[i][j].secpos.x < 220))
        pic->map[i][j].secpos.y += 4;
    if ((pic->map[i][j].pos.x > 1470) && (pic->map[i][j].pos.x <= 1920))
        pic->map[i][j].pos.y -= 4;
    if ((pic->map[i][j].secpos.x > 1470) && (pic->map[i][j].secpos.x <= 1920))
        pic->map[i][j].secpos.y -= 4;
}
