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

void color_stop(all *pic)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(pic->window);
    sfVector2u s = sfRenderWindow_getSize(pic->window);
    if (pos.x * W_ / s.x >= 700 && pos.x * W_ / s.x <= 1600 && pos.y
    * L_ / s.y >= 200 && pos.y * L_ / s.y <= 360) {
        sfSprite_setColor(pic->ps.resume, (sfColor){_A, _A, _A, _A});
    } else
        sfSprite_setColor(pic->ps.resume, (sfColor){_A, _A, _A, 200});
    if (pos.x * W_ / s.x >= 700 && pos.x * W_ / s.x <= 1600 && pos.y
    * L_ / s.y >= 400 && pos.y * L_ / s.y <= 560) {
        sfSprite_setColor(pic->ps.restart, (sfColor){_A, _A, _A, _A});
    } else
        sfSprite_setColor(pic->ps.restart, (sfColor){_A, _A, _A, 200});
    color_stop2(pic, pos, s);
}

void draw_stop(all *pic)
{
    color_stop(pic);
    sfRenderWindow_drawSprite(pic->window, pic->ps.back, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.d1, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.d10, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.d100, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.best_score, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.b1, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.b10, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.b100, 0);
    sfRenderWindow_drawSprite(pic->window, pic->ps.resume, 0);
    sfRenderWindow_drawSprite(pic->window, pic->ps.restart, 0);
    sfRenderWindow_drawSprite(pic->window, pic->ps.bc_mn, 0);
    sfRenderWindow_drawSprite(pic->window, pic->ps.quit, 0);
}

int evnt_stop(sfEvent event, all *pic)
{
    sfMouseButtonEvent pos = event.mouseButton;
    sfVector2u s = sfRenderWindow_getSize(pic->window);
    if (event.type == sfEvtMouseButtonPressed) {
        if (pos.x * W_ / s.x >= 700 && pos.x * W_ / s.x <= 1600 && pos.y
        * L_ / s.y >= 800 && pos.y * L_ / s.y <= 960) {
            des(pic);
            return 84;
        }
        if (pos.x * W_ / s.x >= 700 && pos.x * W_ / s.x <= 1600 && pos.y
        * L_ / s.y >= 400 && pos.y * L_ / s.y <= 560) {
            sfRenderWindow_setMouseCursorVisible(pic->window, 0);
            free_map(pic);
            set_pic(pic);
        }
        evnt_stop2(pic, pos, s);
    }
}

void color_menu(all *pic)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(pic->window);
    sfVector2u s = sfRenderWindow_getSize(pic->window);
    if (pos.x * W_ / s.x >= 500 && pos.x * W_ / s.x <= 1400 && pos.y
    * L_ / s.y >= 250 && pos.y * L_ / s.y <= 370) {
        sfSprite_setColor(pic->mn.txt, (sfColor){_A, _A, _A, _A});
    } else
        sfSprite_setColor(pic->mn.txt, (sfColor){_A, _A, _A, 200});
    if (pos.x * W_ / s.x >= 500 && pos.x * W_ / s.x <= 1400 && pos.y
    * L_ / s.y >= 450 && pos.y * L_ / s.y <= 570) {
        sfSprite_setColor(pic->mn.procedural, (sfColor){_A, _A, _A, _A});
    } else
        sfSprite_setColor(pic->mn.procedural, (sfColor){_A, _A, _A, 200});
    if (pos.x * W_ / s.x >= 500 && pos.x * W_ / s.x <= 1400 && pos.y
    * L_ / s.y >= 650 && pos.y * L_ / s.y <= 770) {
        sfSprite_setColor(pic->mn.quit, (sfColor){_A, _A, _A, _A});
    } else
        sfSprite_setColor(pic->mn.quit, (sfColor){_A, _A, _A, 200});
}

void draw_menu(all *pic)
{
    sfRenderWindow_drawSprite(pic->window, pic->ps.back, 0);
    color_menu(pic);
    sfRenderWindow_drawSprite(pic->window, pic->mn.txt, 0);
    sfRenderWindow_drawSprite(pic->window, pic->mn.procedural, 0);
    sfRenderWindow_drawSprite(pic->window, pic->mn.quit, 0);
}
