#include "main.h"

void check_sdl_code(int f_return)
{
	if(f_return < 0)
	{
		fprintf(stderr, "SDL Error : %s\n", SDL_GetError());
		exit(1);
	}
}

void check_sdl_pt(void *f_pt)
{
	if(f_pt == NULL)
	{
		fprintf(stderr, "SDL Error : %s\n", SDL_GetError());
		exit(1);
	}
}

void clear_renderer(SDL_Renderer *renderer, int color)
{
	check_sdl_code(
		SDL_SetRenderDrawColor(renderer, HEX_COLOR(color)));   
    check_sdl_code(
    	SDL_RenderClear(renderer));
}

// void draw_marker(SDL_Renderer *renderer, Vec2 pos, Vec2 size, int color)
void draw_marker(SDL_Renderer *renderer, Marker mk, int color)
{
	check_sdl_code(
		SDL_SetRenderDrawColor(renderer, HEX_COLOR(color)));

	SDL_Rect rect = {mk.pos.x - (int)(mk.size / 2), mk.pos.y - (int)(mk.size / 2), mk.size, mk.size};
	SDL_RenderFillRect(renderer, &rect);
}

Vec2 vec_lerp(Vec2 v1, Vec2 v2, float t)
{
	return vec_add(v1, vec_scale(vec_sub(v2, v1), t));
}

Vec2 get_interpolation(Marker *my_markers, float t)
{
	Vec2 a  = (Vec2) my_markers[0].pos;
	Vec2 b  = (Vec2) my_markers[1].pos;
	Vec2 c1 = (Vec2) my_markers[2].pos;
	Vec2 c2 = (Vec2) my_markers[3].pos;

	Vec2 a_c1  = (Vec2) vec_lerp(a, c1, t);
	Vec2 c1_c2 = (Vec2) vec_lerp(c1, c2, t);
	Vec2 c2_b  = (Vec2) vec_lerp(c2, b, t);

	Vec2 a_c1_c1_c2  = (Vec2) vec_lerp(a_c1, c1_c2, t);
	Vec2 c1_c2_c2_b = (Vec2) vec_lerp(c1_c2, c2_b, t);
	
	return (Vec2) vec_lerp(a_c1_c1_c2, c1_c2_c2_b, t);
}

int is_click_on_marker(Marker *my_markers, Vec2 click_pos)
{
	for(int i = 0; i < 4; i++)
	{
		
	}
}