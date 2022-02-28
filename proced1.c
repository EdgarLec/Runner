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

int tp_e(all *pic, int i, int j, int eg)
{
    if (pic->map[i][j].type == eg)
        return 1;
    return 0;
}

int tp_al(all *pic, int i, int j)
{
    if (pic->map[i][j].type == 0 || pic->map[i][j].type == 2)
        return 1;
    return 0;
}

void place_air(all *pic, int i, int j, coordinate coo)
{
    if (i != 0 && !(i == 6 && tp_al(pic, i, coo.x) && tp_al(pic, i, coo.y)) &&
    !(tp_e(pic, i - 1, coo.x, 1) && tp_al(pic, i - 1, coo.y)) && ((tp_e(pic, i
    , j, 1) && tp_e(pic, i, coo.x, 1)) && ((coo.other >= 65 && i != 6 && i != 1
    ) || (coo.other >= 90 && i == 6) || (coo.other >= 50 && i == 1)) && tp_al(
    pic, i - 1, j) || (i < 6 && tp_al(pic, i + 1, coo.y)) || (tp_e(pic, i, coo.
    x, 1) && tp_al(pic, i, coo.y)) || (i != 6 && tp_al(pic, i + 1, coo.x)))) {
        pic->map[i][j].type = 0;
        sfSprite_setScale(pic->map[i][j].pic, (sfVector2f){0, 0});
        i != 6 && pic->map[i + 1][j].type == 1 ?
        sfSprite_setScale(pic->map[i][j].secpic, (sfVector2f){1, 1}) : 0;
        sfSprite_setScale(pic->map[i - 1][j].secpic, (sfVector2f){0, 0});
    }
}

void place_1block(all *pic, int i, int j, coordinate coo)
{
    if (i != 0 && !tp_e(pic, i, j, 1) && ((i != 6 && tp_e(pic, i + 1, coo.y, 1)
    && ((coo.other <= 10 && i > 2) || (coo.other <= 5 && i == 1) || (coo.other
    <= 7 && i == 2)) && tp_e(pic, i + 1, coo.x, 1)) || tp_e(pic, i - 1, j, 1)
    || tp_e(pic, i, coo.y, 1)) || (i == 6 && tp_e(pic, i, coo.y, 0) && tp_e(pic
    , i, coo.x, 0))) {
        place_light(pic, i, j);
        pic->map[i][j].type = 1;
        sfSprite_setScale(pic->map[i][j].pic, (sfVector2f){2, 2});
        sfSprite_setTexture(pic->map[i][j].pic, pic->txtu.block, sfTrue);
        sfSprite_setTextureRect(pic->map[i][j].pic, (sfIntRect){0, 0, 80, 80});
        if (pic->map[i - 1][j].type != 1)
            sfSprite_setScale(pic->map[i - 1][j].secpic, (sfVector2f){1, 1});
        sfSprite_setScale(pic->map[i][j].secpic, (sfVector2f){0, 0});
    }
    place_air(pic, i, j, coo);
}

void move_prced(all *pic, int i, int j)
{
    coordinate coo;
    coo.other = rand() % 100;
    if (j != 0)
        coo.y = j - 1;
    else
        coo.y = 14;
    if (coo.y == 0)
        coo.x = 14;
    else
        coo.x = coo.y - 1;
    pic->map[i][j].pos.x = pic->map[i][coo.y].pos.x + 160;
    pic->map[i][j].secpos.x = pic->map[i][j].pos.x - 11;
    pic->map[i][j].pos.y = i * 160 + 200;
    pic->map[i][j].secpos.y = (i + 1 - 0.3) * 160 + 200;
    place_1block(pic, i, j, coo);
    pic->bool.block_passed = j;
    if (pic->bool.block_passed + 4 > 14)
        pic->bool.block_passed -= 15;
}
