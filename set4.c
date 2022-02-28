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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my_struct.h"

void set_sword(all *pic, char **map, int i, int j)
{
    if (map[i][j] == '4') {
        pic->map[i][j].pic = open_w_texture(pic->txtu.sword, 0.8, 0.8);
        pic->map[i][j].type = 4;
        pic->map[i][j].pos = (sfVector2f){j * 160 + 10, i * 160 + 10
        + ((j == 12) ? 196 : 0)};
    }
}

void set_void(all *pic, int i, int j)
{
    if (i < 5) {
        pic->map[i][j].pic = open_w_texture(pic->txtu.block, 0, 0);
        pic->map[i][j].pos = (sfVector2f){j * 160, i * 160};
        pic->map[i][j].secpic = open_w_texture(pic->txtu.grass, 0, 0);
        pic->map[i][j].secpos = (sfVector2f){j * 160 - 11, (i + 1 - 0.3)
        * 160};
        pic->map[i][j].type = 0;
    } else if (i == 6) {
        pic->map[i][j].pic = open_w_texture(pic->txtu.block, 2, 2);
        pic->map[i][j].pos = (sfVector2f){j * 160, i * 160};
        pic->map[i][j].secpic = open_w_texture(pic->txtu.grass, 0, 0);
        pic->map[i][j].type = 1;
        pic->map[i][j].secpos = (sfVector2f){j * 160 - 11, (i + 1 - 0.3)
        * 160};
        sfSprite_setPosition(pic->map[i][j].pic, pic->map[i][j].pos);
    }
}

void set_grass(all *pic, int i, int j)
{
    pic->map[i][j].secpic = open_w_texture(pic->txtu.grass, 1, 1);
    pic->map[i][j].pos = (sfVector2f){j * 160, i * 160};
    pic->map[i][j].pic = open_w_texture(pic->txtu.block, 0, 0);
    pic->map[i][j].type = 0;
    pic->map[i][j].secpos = (sfVector2f){j * 160 - 11, (i + 1 - 0.3) * 160};
    sfSprite_setPosition(pic->map[i][j]
    .secpic, pic->map[i][j].secpos);
}

int set_proced_map(all *pic)
{
    pic->map = malloc(sizeof(square *) * 8);
    if (pic->map == 0)
        return 84;
    pic->bool.size = 14;
    pic->map[7] = 0;
    for (int i = 0; i < 7; i++) {
        pic->map[i] = malloc(sizeof(square) * 16);
        if (pic->map[i] == 0)
            return 84;
        for (int j = 0; j < 15; j++) {
            i != 5 ? set_void(pic, i, j) : set_grass(pic, i, j);
            set_up_down(j, i, pic);
        }
    }
    sfSprite_setScale(pic->map[5][14].pic, (sfVector2f){2, 2});
    pic->map[5][14].type = 1;
    sfSprite_setScale(pic->map[5][14].secpic, (sfVector2f){0, 0});
    sfSprite_setScale(pic->map[4][14].secpic, (sfVector2f){1, 1});
    return 0;
}

void evt_menu2(all *pic, sfMouseButtonEvent pos, sfVector2u s)
{
    if (pos.x * W_ / s.x >= 500 && pos.x * W_ / s.x <= 1400 && pos.y
    * L_ / s.y >= 250 && pos.y * L_ / s.y <= 370) {
        pic->bool.in_menu = 0;
        free_map(pic);
        pic->bool.procedural = 0;
        sfRenderWindow_setMouseCursorVisible(pic->window, 0);
        set_pic(pic);
    }
}
