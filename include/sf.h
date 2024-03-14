/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** sf.h
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#ifndef SF_H
    #define SF_H

typedef struct virus_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfTexture *texture;
    double speed;
} virus_t;

typedef struct asset_s {
    char *filename;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f origin;
    sfVector2f position;
    sfIntRect rect;
    sfVector2f scale;
    sfClock *clock;
    int time;
} asset_t;

typedef struct game_s {
    int score;
    int infected;
    int max_infected;
    int velocity;
    int step;
    int seconds;
    struct virus_s *virus;
    sfVector2f *mouse;
    sfVector2u window_size;
    sfText *text_score;
    sfText *text_infected;
    sfText *text_max_infected;
    sfSprite *gameover;
    sfSprite *firewall;
    sfSprite *sswitch;
    sfSprite *minus;
    sfSprite *plus;
    sfSprite *background;
    sfSprite *play;
    sfTexture *gameover_texture;
    sfTexture *firewall_texture;
    sfTexture *sswitch_texture;
    sfTexture *minus_texture;
    sfTexture *plus_texture;
    sfTexture *mute_texture;
    sfTexture *background_texture;
    sfTexture *play_texture;
    sfText *text_on_infect;
    sfFont *font;
    sfRenderWindow *window;
    sfMusic *alarm;
    int autorize_music;
    sfSprite *mute;
    int map;
} game_t;
int game_run(sfRenderWindow *win, sfEvent e, sfSprite *bg, sfTexture *text);
virus_t *make_virus(void);
sfSprite* load_sprite(sfTexture *texture);
sfTexture* load_texture(const char *filename);
sfSprite* set_position(sfSprite *sprite, int x, int y);
void move_rect(sfIntRect *rect, int offset, int max_value);
int play_music(game_t *game);
int set_pos_top_offset(sfSprite *sprite, sfRenderWindow *win, int offset);
sfIntRect set_rect(sfSprite *sprite, int width, int height);
void generate_mob(asset_t *asset, sfClock *clock, sfRenderWindow *window);
int check_pull_event(sfRenderWindow *window, sfEvent e, game_t *game);
int move_position_positive(sfSprite *sprite, sfVector2f *pos, int x, int y);
int move_position_negative(sfSprite *sprite, sfVector2f *pos, int x, int y);
int set_pos_middle_offset(sfSprite *sprite, sfRenderWindow *win, int offset);
sfRenderWindow *create_window(game_t *game);
int render_draw(sfRenderWindow *window, game_t *game);
game_t *make_game(sfSprite *bg, sfRenderWindow *win, sfTexture *text);
void refresh(game_t *instance);
int set_position_text(sfText *text, int offset);
sfFont *load_font(const char *filename);
void load_gui(game_t *instance);
int move_virus(sfClock *animation_clock, game_t *game);
int set_position_text_middle(sfText *text, sfRenderWindow *window);
sfVector2f set_position_from_window(sfSprite *sprite, sfRenderWindow *window);
int set_position_on_middle_window(sfSprite *sprite, sfRenderWindow *window);
sfFont* load_font(const char *filename);
void load_text(sfText *text, char *str, int position);
sfMusic* load_music(const char *filename);
void free_all(game_t *game, sfClock *clock1, sfClock *clock2);
int start_game(game_t *game);
int switch_mute(game_t *game);
int update_max_infected(game_t *game, int value);
#endif /* !SF_H */
