/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** on_mouse_moved.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my.h"
#include "sf.h"

int detect_mouse_for_start(game_t *game, sfEvent e)
{
    sfFloatRect playBtn = sfSprite_getGlobalBounds(game->play);
    sfFloatRect gameoverBtn = sfSprite_getGlobalBounds(game->gameover);
    sfMouseButtonEvent button = e.mouseButton;

    if (button.button == sfMouseLeft){
        if (sfFloatRect_contains(&playBtn, button.x, button.y)) {
            start_game(game);
            return 1;
        }
        if (sfFloatRect_contains(&gameoverBtn, button.x, button.y)) {
            start_game(game);
            return 1;
        }
    }
    return 0;
}

int on_mouse_pressed_start(game_t *game, sfEvent e)
{
    sfFloatRect switchMapBtn = sfSprite_getGlobalBounds(game->sswitch);
    sfFloatRect minusBtn = sfSprite_getGlobalBounds(game->minus);
    sfFloatRect plusBtn = sfSprite_getGlobalBounds(game->plus);
    sfFloatRect muteBtn = sfSprite_getGlobalBounds(game->mute);
    sfMouseButtonEvent button = e.mouseButton;

    if (button.button == sfMouseLeft){
        if (detect_mouse_for_start(game, e) == 1)
            return 1;
        if (sfFloatRect_contains(&switchMapBtn, button.x, button.y))
            return switch_map(game);
        if (sfFloatRect_contains(&minusBtn, button.x, button.y))
            return update_max_infected(game, -1);
        if (sfFloatRect_contains(&plusBtn, button.x, button.y))
            return update_max_infected(game, 1);
        if (sfFloatRect_contains(&muteBtn, button.x, button.y))
            return switch_mute(game);
    }
    return 0;
}

int on_mouse_pressed_started(game_t *game, sfEvent e)
{
    sfFloatRect virusBtn = sfSprite_getGlobalBounds(game->virus->sprite);
    sfMouseButtonEvent button = e.mouseButton;
    virus_t *virus = game->virus;

    if (button.button == sfMouseLeft){
        if (sfFloatRect_contains(&virusBtn, button.x, button.y)) {
            game->score += 1;
            virus->pos = set_position_from_window(virus->sprite, game->window);
            refresh(game);
            return 0;
        }
    }
    return 0;
}

int on_mouse_pressed(game_t *game, sfEvent e)
{
    if (game->step == 0 || game->step == 2){
        return on_mouse_pressed_start(game, e);
    }
    if (game->step == 1){
        return on_mouse_pressed_started(game, e);
    }
    return 0;
}

int switch_mute(game_t *game)
{
    if (game->autorize_music == 1){
        game->mute_texture = load_texture("assets/mute.png");
        game->mute = load_sprite(game->mute_texture);
        set_position(game->mute, 0, game->window_size.y - 50);
        game->autorize_music = 0;
        return 0;
    }
    if (game->autorize_music == 0){
        game->mute_texture = load_texture("assets/mute2.png");
        game->mute = load_sprite(game->mute_texture);
        set_position(game->mute, 0, game->window_size.y - 50);
        game->autorize_music = 1;
    }
    return 0;
}
