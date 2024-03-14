/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** game.c
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my.h"
#include "sf.h"

void animation_time(int time, sfClock *clock, game_t *game_instance)
{
    if (time >= 1000) {
        if (game_instance->step != 1){
            return;
        }
        move_virus(clock, game_instance);
    }
    if (game_instance->seconds != 0 && game_instance->seconds <= 3000) {
        game_instance->seconds += 5;
    }
}

//clear sprites
// -h complet
// rajouter la musique
// rajouter le viseur en rj
// setframe limit
// struture info avec les assets
int game_run(sfRenderWindow *win, sfEvent e, sfSprite *bg, sfTexture *text)
{
    game_t *game = make_game(bg, win, text);
    sfClock *animation_clock = sfClock_create();
    sfClock *main_clock = sfClock_create();
    int time;

    load_gui(game);
    game->virus->pos = set_position_from_window(game->virus->sprite, win);
    while (sfRenderWindow_isOpen(win)) {
        if (check_pull_event(win, e, game) == 84)
            break;
        time = sfClock_getElapsedTime(main_clock).microseconds / 100;
        if (time >= 0.5) {
            sfClock_restart(main_clock);
            render_draw(win, game);
        }
        time = sfClock_getElapsedTime(animation_clock).microseconds / 100;
        animation_time(time, animation_clock, game);
    }
    free_all(game, animation_clock, main_clock);
    return 0;
}

game_t *make_game(sfSprite *bg, sfRenderWindow *win, sfTexture *text)
{
    game_t *game = malloc(sizeof(game_t));

    game->max_infected = 3;
    game->infected = 0;
    game->score = 0;
    game->step = 0;
    game->seconds = 0;
    game->map = 1;
    game->autorize_music = 1;
    game->background = bg;
    game->window = win;
    game->background_texture = text;
    game->window_size = sfRenderWindow_getSize(win);
    return game;
}

int render_draw(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfWhite);
    if (game->step == 0) {
        render_draw_started(window, game);
    }
    if (game->step == 1){
        render_draw_playing(window, game);
    }
    if (game->step == 2){
        render_draw_gameover(window, game);
    }
    sfRenderWindow_display(window);
    return 0;
}

int start_game(game_t *game)
{
    char *score = "Score : 0";

    game->step = 1;
    game->score = 0;
    game->infected = 0;
    game->seconds = 0;
    refresh(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    load_text(game->text_score, score, 350);
    return 0;
}
