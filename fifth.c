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
#include <math.h>

void up_down(all *pic, int i, int j)
{
    if ((pic->map[i][j].pos.x < 300))
        pic->map[i][j].pos.y += 4;
    if (pic->map[i][j].secpic != 0 && (pic->map[i][j].secpos.x < 300))
        pic->map[i][j].secpos.y += 4;
    if ((pic->map[i][j].pos.x > 1920) && (pic->map[i][j].pos.x <= 1929)
    && j > 12)
        pic->map[i][j].pos.y += 200;
    if (pic->map[i][j].secpic != 0 && (pic->map[i][j].secpos.x > 1920)
    && (pic->map[i][j].secpos.x <= 1929) && j > 12)
        pic->map[i][j].secpos.y += 200;
    if ((pic->map[i][j].pos.x > 1470) && (pic->map[i][j].pos.x <= 1920)
    && j >= 11)
        pic->map[i][j].pos.y -= 4;
    if (pic->map[i][j].secpic != 0 && (pic->map[i][j].secpos.x > 1470)
    && (pic->map[i][j].secpos.x <= 1920) && j >= 11)
        pic->map[i][j].secpos.y -= 4;
    if (pic->map[i][j].type == 4 && pic->bool.anim_mob % 5 == 0) {
        pic->map[i][j].pos.y += cosf(pic->map[i][j].pos.x) * 10;
    }
}

void draw_sword(all *pic, int i)
{
    if (pic->map[i][pic->bool.block_passed + 4].type == 4) {
        pic->map[i][pic->bool.block_passed + 4].pic = 0;
        pic->map[i][pic->bool.block_passed + 4].type = 0;
        pic->bool.atk++;
        sfSound_play(pic->s.woosh);
    }
}

void touch_nme(all *pic, int i)
{
    if (pic->map[i][pic->bool.block_passed + 4].type == 3 && pic->
    plc_p.x + 40 >= pic->map[i][pic->bool.block_passed + 4].pos.x
    && pic->plc_p.x - 20 <= pic->map[i][pic->bool.block_passed + 4].pos
    .x && pic->plc_p.y - 210 < pic->map[i][pic->bool.block_passed + 4].
    pos.y - 135) {
        if (pic->bool.atk == 0 && pic->bool.is_atk == 0) {
            pic->bool.lose = 1;
        } else if (pic->bool.is_atk != -1) {
            pic->bool.is_atk = 5;
            sfSound_play(pic->s.woosh);
        }
    }
}

void move_atk(all *pic)
{
    pic->rec_p.top = 320;
    pic->rec_p.left += 80;
    pic->rec_p.left >= 480
    ? pic->rec_p.left = 0 : 0;
    sfSprite_setTextureRect(pic->perso, pic->rec_p);
    pic->bool.is_atk--;
    if (pic->bool.is_atk == 0)
        pic->bool.is_atk = -1;
}

void move_perso(all *pic)
{
    if (pic->bool.is_ground == 1 && pic->bool.is_atk == 0
    && pic->bool.is_won == 0) {
        pic->rec_p.left += 80;
        if (pic->rec_p.left >= 720)
            pic->rec_p.left = 160;
    } else if (pic->bool.lose == 1) {
        pic->rec_p.left = pic->bool.anim / 4 * 80;
        pic->bool.anim++;
        (pic->rec_p.left >= 400) ? pic->bool.anim = 4 : 0;
        pic->plc_p.y -= 5;
        sfSprite_setPosition(pic->perso, pic->plc_p);
    }
    sfSprite_setTextureRect(pic->perso, pic->rec_p);
}
