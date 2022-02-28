/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/
#ifndef STRUCT_
    #define STRUCT_
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
    #define W_ 1920
    #define L_ 1080
    #define _A 255

typedef struct bool {
    int is_jumping;
    int is_stopped;
    int is_ground;
    int is_head_touch;
    int block_passed;
    int score;
    int anim_mob;
    int is_stop;
    int in_menu;
    int is_won;
    int best_score;
    int size;
    int atk;
    int is_atk;
    int lose;
    int anim;
    int op;
    int procedural;
} all_bool;

typedef struct sounds {
    sfMusic *run;
    sfMusic *mus;
    sfMusic *forest;
    sfSound *ting;
    sfSoundBuffer *tingbuf;
    sfSound *woosh;
    sfSoundBuffer *wooshbuf;
} sounds;

typedef struct square {
    sfSprite *pic;
    sfVector2f pos;
    int type;
    sfSprite *secpic;
    sfVector2f secpos;
} square;

typedef struct scr {
    sfSprite *d1;
    sfIntRect rec1;
    sfSprite *d10;
    sfIntRect rec10;
    sfSprite *d100;
    sfIntRect rec100;
    sfSprite *best_score;
    sfSprite *b1;
    sfIntRect br1;
    sfSprite *b10;
    sfIntRect br10;
    sfSprite *b100;
    sfIntRect br100;
} scr;

typedef struct stop {
    sfSprite *resume;
    sfSprite *restart;
    sfSprite *quit;
    sfSprite *bc_mn;
    sfSprite *back;
} stop;

typedef struct menu {
    sfSprite *txt;
    sfSprite *procedural;
    sfSprite *quit;
} menu;

typedef struct won {
    sfSprite *you_won;
} won;

typedef struct back {
    sfSprite *back;
    sfSprite *back2;
    sfIntRect r2;
    sfSprite *back3;
    sfIntRect r3;
    sfSprite *back4;
    sfIntRect r4;
    sfSprite *fog;
} back;

typedef struct texture {
    sfTexture *block;
    sfTexture *grass;
    sfTexture *lights;
    sfTexture *nme;
    sfTexture *sword;
} texture;

typedef struct all {
    sfRenderWindow *window;
    sfSprite *perso;
    sfSprite *black;
    texture txtu;
    int color;
    sfSprite *lose;
    sfIntRect rec_p;
    sfVector2f plc_p;
    sfSprite *ylose;
    sfSprite *ray_light;
    scr sc;
    all_bool bool;
    square **map;
    stop ps;
    menu mn;
    won vic;
    sounds s;
    char *map_path;
    back bk;
} all;

typedef struct coordinate {
    int x;
    int y;
    int other;
} coordinate;

int evnt(sfEvent event, all *pic);
void move_sprite(all *pic, sfClock **clock, sfClock **clock2);
void draw(all *pic);
void draw_lose(all *pic);
int set_pic(all *pic);
void move_block(all *pic);
int evt(all *pic, sfEvent event);
void set_map2(all *pic, int i, int file_s, char **map);
sfSprite *open_picture(char *png, double x, double y);
void set_sc(all *pic);
void set_stop(all *pic);
void draw_stop(all *pic);
int evnt_stop(sfEvent event, all *pic);
void set_menu(all *pic);
void draw_menu(all *pic);
int evnt_menu(sfEvent event, all *pic);
void free_map(all *pic);
void draw_won(all *pic);
void new_best_score(all *pic);
int set_pic2(all *pic);
int set_perso(all *pic);
void change_score(all *pic);
void des(all *pic);
void des_song(all *pic);
void color_stop2(all *pic, sfVector2i pos, sfVector2u s);
int get_file_size(char *path);
void up_down(all *pic, int i, int j);
void set_sword(all *pic, char **map, int i, int j);
void draw_sword(all *pic, int i);
void touch_nme(all *pic, int i);
void move_atk(all *pic);
void jump(all *pic);
void move_perso(all *pic);
void end_kill(all *pic, int i);
void move_all_block(all *pic, int i, int j);
void draw_ui(all *pic);
void nme_grass(all *pic, int i, int j, char **map);
int is_nme(all *pic, int i, int j, char **map);
sfSprite *open_w_texture(sfTexture *texture, double x, double y);
int set_proced_map(all *pic);
void move_prced(all *pic, int i, int j);
void evnt_stop2(all *pic, sfMouseButtonEvent pos, sfVector2u s);
void evt_menu2(all *pic, sfMouseButtonEvent pos, sfVector2u s);
void place_light(all *pic, int i, int j);
void up_down_prcd(all *pic, int i, int j);
void ground_perso(all *pic);
void print_usage(void);
int set_sys(all *pic);
int set_sys3(all *pic);
void des_all(all *pic);
int set_sys4(all *pic);
void set_up_down(int j, int i, all *pic);

#endif
