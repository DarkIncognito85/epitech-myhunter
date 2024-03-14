/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** draw.c
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include "sf.h"

int render_draw_started(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, game->background, NULL);
    sfRenderWindow_drawSprite(window, game->sswitch, NULL);
    sfRenderWindow_drawSprite(window, game->play, NULL);
    sfRenderWindow_drawText(window, game->text_max_infected, NULL);
    sfRenderWindow_drawSprite(window, game->plus, NULL);
    sfRenderWindow_drawSprite(window, game->minus, NULL);
    sfRenderWindow_drawSprite(window, game->mute, NULL);
    return 0;
}

int render_draw_playing(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_drawSprite(window, game->background, NULL);
    sfRenderWindow_drawSprite(window, game->virus->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->firewall, NULL);
    sfRenderWindow_drawText(window, game->text_score, NULL);
    sfRenderWindow_drawText(window, game->text_infected, NULL);
    sfRenderWindow_drawText(window, game->text_max_infected, NULL);
    if (game->seconds != 0 && game->seconds <= 3000) {
        sfRenderWindow_drawText(window, game->text_on_infect, NULL);
    }
    return 0;
}

int render_draw_gameover(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, game->background, NULL);
    sfRenderWindow_drawSprite(window, game->gameover, NULL);
    sfRenderWindow_drawSprite(window, game->sswitch, NULL);
    sfRenderWindow_drawSprite(window, game->mute, NULL);
    sfRenderWindow_drawText(window, game->text_score, NULL);
    return 0;
}
