/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** check_pull_event.c
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include "sf.h"

int change_mouse_position(game_t *game)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {mousePos.x, mousePos.y};

    sfSprite_setPosition(game->firewall, pos);
    return 0;
}

int check_pull_event(sfRenderWindow *window, sfEvent e, game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &e)){
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return 84;
        }
        if (e.type == sfEvtMouseButtonPressed){
            return on_mouse_pressed(game, e);
        }
        if (e.type == sfEvtMouseMoved) {
            return change_mouse_position(game);
        }
        if (e.type == sfEvtKeyPressed && e.key.code == sfKeyEscape) {
            sfRenderWindow_close(window);
            return 84;
        }
    }
    return 0;
}
