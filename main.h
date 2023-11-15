#ifndef __MAIN_H__
#define __MAIN_H__

// Inclusions des lib
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>

// Définition des types
typedef struct vec2 {
	float x;
	float y;
} Vec2;

typedef struct marker {
    Vec2 pos;
    float size; // un marqueur c'est uncarré
} Marker;

// Prototypes des fonctions
void draw_marker(SDL_Renderer *renderer, Marker mk, int color);
int is_click_on_marker(Marker *my_markers, Vec2 click_pos);
Vec2 get_interpolation(Marker *my_markers, float t);
void clear_renderer(SDL_Renderer *renderer, int color);
Vec2 vec_lerp(Vec2 v1, Vec2 v2, float t);
void check_sdl_code(int f_return);
void check_sdl_pt(void *f_pt);
Vec2 vec_add(Vec2 v1, Vec2 v2);
Vec2 vec_sub(Vec2 v1, Vec2 v2);
Vec2 vec_scale(Vec2 v1, float s);

// Masterclass 
#define HEX_COLOR(hex)                      \
    ((hex) >> (3 * 8)) & 0xFF,              \
    ((hex) >> (2 * 8)) & 0xFF,              \
    ((hex) >> (1 * 8)) & 0xFF,              \
    ((hex) >> (0 * 8)) & 0xFF

#endif