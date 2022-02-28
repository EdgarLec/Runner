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

void end_kill(all *pic, int i)
{
    pic->bool.atk--;
    pic->bool.is_atk = 0;
    pic->bool.score++;
    pic->map[i][pic->bool.block_passed + 3].pic = 0;
    pic->map[i][pic->bool.block_passed + 3].type = 0;
}

void move_all_block(all *pic, int i, int j)
{
    if (pic->bool.procedural == 1 && pic->map[i][j].pos.x <= -160)
        move_prced(pic, i, j);
    if (pic->map[i][j].pos.x > -260) {
        pic->map[i][j].pos.x -= 9;
        pic->bool.procedural == 0 ? up_down(pic, i, j)
        : up_down_prcd(pic, i, j);
        (pic->map[i][j].pic != 0) && pic->map[i][0].pos.x <= 2180 ?
        sfSprite_setPosition(pic->map[i][j].pic, pic->map[i][j].pos) : 0;
        pic->map[i][j].pos.x <= -160 && pic->bool.block_passed < j
        && pic->bool.procedural == 0 ? pic->bool.block_passed = j : 0;
        (pic->map[i][j].secpic != 0) ? pic->map[i][j].secpos.x -= 9 : 0;
        (pic->map[i][j].secpic != 0) ? sfSprite_setPosition(pic->map[i][j]
        .secpic, pic->map[i][j].secpos) : 0;
        if (pic->map[i][j].type == 3) {
            sfSprite_setTextureRect(pic->map[i][j].pic
            , (sfIntRect){((pic->bool.anim_mob / 4) % 5) * 119 + ((pic->
            bool.anim_mob / 4) % 5) * 2, (pic->bool.anim_mob / 4) / 5 * 95
            , 119, 94});
        }
    }
}

void draw_ui(all *pic)
{
    pic->bool.procedural == 0 ? sfRenderWindow_drawSprite
    (pic->window, pic->ray_light, 0) : 0;
    sfRenderWindow_drawSprite(pic->window, pic->sc.d1, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.d10, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.d100, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.best_score, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.b1, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.b10, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.b100, 0);
    if (pic->bool.op >= 5) {
        pic->bool.op -= 5;
        sfSprite_setColor(pic->black, (sfColor){_A, _A, _A, pic->bool.op});
        sfRenderWindow_drawSprite(pic->window, pic->black, 0);
    }
}

void nme_grass(all *pic, int i, int j, char **map)
{
    if (is_nme(pic, i, j, map) == 1) {
        pic->map[i - 1][j].pic = open_w_texture(pic->txtu.nme, 1.5, 1.5);
        pic->map[i - 1][j].pos = (sfVector2f){j * 160 - 10, (i - 0.85) * 160};
        sfSprite_setTextureRect(pic->map[i - 1][j].pic
        , (sfIntRect){0, 0, 119, 94});
        sfSprite_setPosition(pic->map[i - 1]
        [j].pic, pic->map[i - 1][j].pos);
        pic->map[i - 1][j].type = 3;
    } else {
        pic->map[i - 1][j].pic = open_w_texture(pic->txtu.grass, 1, 1);
        pic->map[i - 1][j].pos = (sfVector2f){j * 160 - 11, (i - 0.3) * 160};
        sfSprite_setPosition(pic->map[i - 1]
        [j].pic, pic->map[i - 1][j].pos);
    }
    (j == 12) ? pic->map[i - 1][j].pos.y += 188 : 0;
    (j == 11) ? pic->map[i - 1][j].pos.y += 120 : 0;
}

void evnt_stop2(all *pic, sfMouseButtonEvent pos, sfVector2u s)
{
    if (pos.x * W_ / s.x >= 700 && pos.x * W_ / s.x <= 1600 && pos.y
    * L_ / s.y >= 200 && pos.y * L_ / s.y <= 360) {
        pic->bool.is_stop = 0;
        sfRenderWindow_setMouseCursorVisible(pic->window, 0);
    }
    (pos.x * W_ / s.x >= 700 && pos.x * W_ / s.x <= 1600 && pos.y
    * L_ / s.y >= 600 && pos.y * L_ / s.y <= 760) ?
    (pic->bool.in_menu = 1) && (pic->bool.is_stop = 0) : 0;
}
