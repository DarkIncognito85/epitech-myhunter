/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** MY_H
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdarg.h>
#include <dirent.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <sf.h>

#ifndef MY_H
    #define MY_H

void trigger_infected(game_t *instance);
int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char str);
void my_put_nbr(int nb);
int switch_map(game_t *game);
int make_asset(char *filename, asset_t *asset);
int on_mouse_pressed(game_t *game, sfEvent e);
int display_mobs(sfRenderWindow *window, game_t *game);
int display_background(sfRenderWindow *window, game_t *game);
int infected_server(game_t *game);
char *my_itoa(int nb);
int check_tty(char *envp[]);
void my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int check_assets(void);
int set_position_hidden(sfText *text);
int set_position_heading(sfText *text);
int render_draw_started(sfRenderWindow *window, game_t *game);
int render_draw_playing(sfRenderWindow *window, game_t *game);
int render_draw_gameover(sfRenderWindow *window, game_t *game);
int move_virus(sfClock *animation_clock, game_t *game);
int random_nbr(int min, int max);
#endif /* !MY_H */
