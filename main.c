/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include "sf.h"
#include "math.h"

int display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_hunter\n");
    my_putstr("     you can enable/disable the alarm on botton left\n");
    my_putstr("     you can change max viruses on botton right\n");
    my_putstr("     you can switch map on 'switch' on the middle\n");
    my_putstr("     you can quit game with escape buttom\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     A dock hunt where you have to shoot viruses\n");
    my_putstr("     for protect datacenter\n");
    my_putstr("DEVELOPPER\n");
    my_putstr("     MARTIN DELEBECQUE - Epitech 2023\n");
    return 0;
}

int check_prerequisites(char *envp[])
{
    if (check_tty(envp) == 84)
        return 84;
    if (check_assets() == 84)
        return 84;
    return 0;
}

sfRenderWindow *create_window(game_t *game)
{
    sfRenderWindow *window;
    sfVideoMode mode = {950, 800, 32};

    window = sfRenderWindow_create(mode, \
"Hunter Hosting", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 144);
    game->window = window;
    return window;
}

int main(int argc, char *argv[], char *envp[])
{
    struct game_s *game = malloc(sizeof(struct game_s));
    sfRenderWindow* window;
    sfSprite *sprite;
    sfTexture *texture;
    sfEvent event;
    int run;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        return display_help();
    if (check_prerequisites(envp) == 84)
        return 84;
    window = create_window(game);
    texture = load_texture("./assets/bg-1.jpg");
    sprite = load_sprite(texture);
    run = game_run(window, event, sprite, texture);
    if (run == 0)
        return 0;
    return 0;
}
