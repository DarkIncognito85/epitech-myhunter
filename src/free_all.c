/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** free_all.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include "sf.h"

void free_all_textures(game_t *game)
{
    sfTexture_destroy(game->virus->texture);
    sfTexture_destroy(game->background_texture);
    sfTexture_destroy(game->sswitch_texture);
    sfTexture_destroy(game->play_texture);
    sfTexture_destroy(game->gameover_texture);
    sfTexture_destroy(game->mute_texture);
    sfTexture_destroy(game->minus_texture);
    sfTexture_destroy(game->plus_texture);
    sfTexture_destroy(game->firewall_texture);
}

void free_all_sprites(game_t *game)
{
    sfSprite_destroy(game->virus->sprite);
    sfSprite_destroy(game->background);
    sfSprite_destroy(game->sswitch);
    sfSprite_destroy(game->play);
    sfSprite_destroy(game->gameover);
    sfSprite_destroy(game->mute);
    sfSprite_destroy(game->minus);
    sfSprite_destroy(game->plus);
    sfSprite_destroy(game->firewall);
}

void free_all(game_t *game, sfClock *clock1, sfClock *clock2)
{
    free_all_textures(game);
    free_all_sprites(game);
    sfText_destroy(game->text_score);
    sfText_destroy(game->text_infected);
    sfText_destroy(game->text_max_infected);
    sfText_destroy(game->text_on_infect);
    sfFont_destroy(game->font);
    sfMusic_destroy(game->alarm);
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(clock1);
    sfClock_destroy(clock2);
    free(game->virus);
    free(game);
}
