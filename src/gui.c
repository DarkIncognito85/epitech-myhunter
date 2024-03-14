/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** gui.c
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my.h"
#include "sf.h"

void trigger_infected(struct game_s *instance)
{
    char *score = my_strcat("Score : ", my_itoa(instance->score));

    instance->infected += 1;
    instance->seconds = 1;
    play_music(instance);
    if (instance->infected >= instance->max_infected) {
        instance->step = 2;
        sfText_setString(instance->text_score, score);
        set_position_text_middle(instance->text_score, instance->window);
    } else {
        set_position_heading(instance->text_on_infect);
    }
}

void load_text(sfText *text, char *str, int position)
{
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 20);
    if (position != -1){
        set_position_text(text, position);
        sfText_setColor(text, sfWhite);
    } else {
        sfText_setColor(text, sfRed);
    }
    sfText_setFont(text, load_font("./assets/Games.ttf"));
}

void refresh(struct game_s *instance)
{
    char *score = my_strcat("Score : ", my_itoa(instance->score));
    char *infected = my_strcat("Infected : ", my_itoa(instance->infected));

    sfText_setString(instance->text_score, score);
    sfText_setString(instance->text_infected, infected);
    if (instance->score % 5 == 0 && instance->score != 0) {
        instance->virus->speed += 0.5;
    }
}

int switch_map(game_t *game)
{
    char *map;

    if (game->map == 2) {
        map = "./assets/bg-1.jpg";
        game->map = 1;
    } else {
        map = "./assets/bg-2.jpg";
        game->map = 2;
    }
    game->background_texture = load_texture(map);
    game->background = load_sprite(game->background_texture);
    return 1;
}

static void gui_load_text(game_t *instance)
{
    instance->font = load_font("./assets/Games.ttf");
    instance->alarm = load_music("./assets/alarm.ogg");
    instance->text_infected = sfText_create();
    instance->text_score = sfText_create();
    instance->text_on_infect = sfText_create();
    instance->text_max_infected = sfText_create();
}

static void gui_load(game_t *instance)
{
    gui_load_text(instance);
    instance->play_texture = load_texture("./assets/play.png");
    instance->play = load_sprite(instance->play_texture);
    instance->gameover_texture = load_texture("./assets/gameover.png");
    instance->gameover = load_sprite(instance->gameover_texture);
    instance->sswitch_texture = load_texture("./assets/switch.png");
    instance->sswitch = load_sprite(instance->sswitch_texture);
    instance->firewall_texture = load_texture("./assets/firewall.png");
    instance->firewall = load_sprite(instance->firewall_texture);
    instance->plus_texture = load_texture("./assets/plus.png");
    instance->plus = load_sprite(instance->plus_texture);
    instance->minus_texture = load_texture("./assets/minus.png");
    instance->minus = load_sprite(instance->minus_texture);
    instance->mute_texture = load_texture("./assets/mute2.png");
    instance->mute = load_sprite(instance->mute_texture);
    my_putstr("GUI loaded\n");
}

void load_gui(struct game_s *instance)
{
    char *score = my_strcat("Score : ", my_itoa(instance->score));
    char *max = my_strcat("Max : ", my_itoa(instance->max_infected));

    instance->virus = make_virus();
    gui_load(instance);
    set_position_on_middle_window(instance->play, instance->window);
    set_position_on_middle_window(instance->gameover, instance->window);
    set_pos_middle_offset(instance->sswitch, instance->window, -250);
    set_position(instance->mute, 0, instance->window_size.y - 50);
    set_rect(instance->mute, 75, 47);
    set_pos_top_offset(instance->plus, instance->window, 0);
    set_pos_top_offset(instance->minus, instance->window, 50);
    set_position_heading(instance->text_on_infect);
    load_text(instance->text_score, score, 350);
    load_text(instance->text_infected, "Infected : 0", 150);
    load_text(instance->text_on_infect, "Datacenter infected!!", -1);
    load_text(instance->text_max_infected, max, 10);
}
