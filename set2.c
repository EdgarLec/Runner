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

int is_nme(all *pic, int i, int j, char **map)
{
    if (rand() % 5 == 1 && j < pic->bool.size - 2 && i != 1 && map[i][j] == '1'
    && j > 5 && map[i][j - 1] == '1' && map[i][j + 1] == '1' && map[i - 2][j]
    == '0' && pic->map[i - 1][j - 1].type != 3 && pic->map[i - 1][j - 2].type
    != 3 && map[i][j - 2] == '1' && map[i][j + 2] == '1' && map[i - 1][j + 2]
    == '0' && map[i - 2][j + 1] != '1' && map[i - 2][j - 1] != '1')
        return 1;
    return 0;
}

void set_nme(all *pic, int i, int j, char **map)
{
    if (i != 0 && (pic->map[i - 1][j].type == 0
    || pic->map[i - 1][j].type == 2 || pic->map[i - 1][j].type == 4)) {
        if (pic->map[i - 1][j].type != 2 && pic->map[i - 1][j].type != 4) {
            nme_grass(pic, i, j, map);
        } else {
            pic->map[i - 1][j].secpic = open_w_texture(pic->txtu.grass, 1, 1);
            pic->map[i - 1][j].secpos = (sfVector2f){j * 160 - 11
            , (i - 0.3) * 160};
            sfSprite_setPosition(pic->map[i - 1][j]
            .secpic, pic->map[i - 1][j].secpos);
            (j == 12) ? pic->map[i - 1][j].secpos.y += 188 : 0;
            (j == 11) ? pic->map[i - 1][j].secpos.y += 120 : 0;
        }
    }
}

void set_map2(all *pic, int i, int file_s, char **map)
{
    for (int j = 0; j < (file_s) / 7; j++) {
        pic->map[i][j].type = 0;
        pic->map[i][j].pic = 0;
        if (map[i][j] == '1') {
            pic->map[i][j].pic = open_w_texture(pic->txtu.block, 2, 2);
            pic->map[i][j].type = 1;
            set_nme(pic, i, j, map);
        } else if (map[i][j] == '2') {
            pic->map[i][j].pic = open_w_texture(pic->txtu.lights, 1, 1);
            pic->map[i][j].type = 2;
        }
        pic->map[i][j].secpic = 0;
        pic->map[i][j].pos = (sfVector2f){j * 160, i * 160 + ((j == 12)
        ? 196 : 0)};
        set_sword(pic, map, i, j);
        (j == 11) ? pic->map[i][j].pos.y += 128 : 0;
        pic->map[i][j].pic != 0 ? sfSprite_setPosition
        (pic->map[i][j].pic, pic->map[i][j].pos) : 0;
    }
}

void set_sc(all *pic)
{
    sfSprite_setPosition(pic->sc.d1, (sfVector2f){160, 80});
    sfSprite_setPosition(pic->sc.d10, (sfVector2f){80, 80});
    sfSprite_setPosition(pic->sc.d100, (sfVector2f){0, 80});
    sfSprite_setTextureRect(pic->sc.d1, (sfIntRect){0, 0, 80, 100});
    sfSprite_setTextureRect(pic->sc.d10, (sfIntRect){0, 0, 80, 100});
    sfSprite_setTextureRect(pic->sc.d100, (sfIntRect){0, 0, 80, 100});
    sfSprite_setPosition(pic->sc.best_score, (sfVector2f){0, -10});
    sfSprite_setPosition(pic->sc.b1, (sfVector2f){580, 0});
    sfSprite_setPosition(pic->sc.b10, (sfVector2f){500, 0});
    sfSprite_setPosition(pic->sc.b100, (sfVector2f){420, 0});
    sfSprite_setTextureRect(pic->sc.b1, (sfIntRect){0, 0, 80, 100});
    sfSprite_setTextureRect(pic->sc.b10, (sfIntRect){0, 0, 80, 100});
    sfSprite_setTextureRect(pic->sc.b100, (sfIntRect){0, 0, 80, 100});
}

void set_stop(all *pic)
{
    pic->black = open_w_texture(pic->txtu.block, 30, 20);
    pic->bool.op = 255;
    sfSprite_setColor(pic->black, (sfColor){_A, _A, _A, 255});
    sfSprite_setPosition(pic->ps.resume, (sfVector2f){700, 200});
    sfSprite_setColor(pic->ps.resume, (sfColor){_A, _A, _A, 200});
    sfSprite_setPosition(pic->ps.restart, (sfVector2f){700, 400});
    sfSprite_setColor(pic->ps.restart, (sfColor){_A, _A, _A, 200});
    sfSprite_setPosition(pic->ps.quit, (sfVector2f){700, 800});
    sfSprite_setColor(pic->ps.quit, (sfColor){_A, _A, _A, 200});
    sfSprite_setColor(pic->ps.back, (sfColor){_A, _A, _A, 170});
    sfSprite_setPosition(pic->ps.bc_mn, (sfVector2f){700, 600});
    sfSprite_setColor(pic->ps.bc_mn, (sfColor){_A, _A, _A, 200});
    set_menu(pic);
}
