/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** virus.c
*/


#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my.h"
#include "sf.h"

virus_t *make_virus(void)
{
    virus_t *virus = malloc(sizeof(virus_t));
    sfVector2f position;

    position.x = 0;
    position.y = 0;
    virus->pos = position;
    virus->texture = load_texture("./assets/sprites.png");
    virus->sprite = load_sprite(virus->texture);
    virus->rect = set_rect(virus->sprite, 100, 100);
    virus->speed = 1;
    return virus;
}

int move_virus(sfClock *animation_clock, game_t *game)
{
    sfIntRect *rect = &game->virus->rect;
    virus_t *virus = game->virus;
    sfVector2f position = virus->pos;

    move_rect(rect, 96, 576);
    sfSprite_setTextureRect(virus->sprite, *rect);
    virus->pos = (sfVector2f){position.x - (10 * virus->speed), position.y};
    if (virus->pos.x < 50){
        virus->pos = set_position_from_window(virus->sprite, game->window);
        trigger_infected(game);
        refresh(game);
    }
    set_position(virus->sprite, virus->pos.x, virus->pos.y);
    if (game->step != 1){
        return 0;
    }
    sfClock_restart(animation_clock);
    return 0;
}

int update_max_infected(game_t *game, int value)
{
    char *max;

    game->max_infected += value;
    if (game->max_infected < 1)
        game->max_infected = 1;
    if (game->max_infected > 100)
        game->max_infected = 100;
    max = my_strcat("Max : ", my_itoa(game->max_infected));
    sfText_setString(game->text_max_infected, max);
    return 0;
}
