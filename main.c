#include "main.h"

#define SCREEN_WIDTH 2880
#define SCREEN_HEIGHT 1800
#define FPS 90
#define DELAY_FPS (1.0f / FPS)
#define BG_COLOR 0x1e1e2eff
#define M_COLOR 0xf38ba8ff
#define ML_COLOR 0xa6e3a1ff
#define MLL_COLOR 0x89b4faff
#define MLLL_COLOR 0xb4befeff
#define A 0x1e1e2e
#define MARKER_SIZE 100.0f

int main(void)
{
	// Initialisation de la SDL
	check_sdl_code(SDL_Init(SDL_INIT_VIDEO));
	check_sdl_code(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"));

	// Creation de la window
	SDL_Window *window = SDL_CreateWindow("Lerp visualisation",
										0,
										0,
										SCREEN_WIDTH,
										SCREEN_HEIGHT,
										SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN);

	// Creation du renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Cleaner le renderer avec bc color
	clear_renderer(renderer, BG_COLOR);

    // Event pooling
    int quit = 0;
    SDL_Event event;
	SDL_RenderPresent(renderer);
	float t = 0, magick = 0;
	int marker_count = 0;
	Marker my_markers[4];

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
            	quit = 1;
            } else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
				if (event.button.button == SDL_BUTTON_LEFT && marker_count < 4) {
					int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    Marker temp_mk = {(Vec2) { (float) mouseX, (float) mouseY }, MARKER_SIZE};
					my_markers[marker_count] = temp_mk;
                    marker_count++;
                }

                if(event.button.button == SDL_BUTTON_LEFT && marker_count == 4)
                {
                	
                }

            }
        }

		clear_renderer(renderer, BG_COLOR);

		for(int i = 0; i < marker_count+1; ++i)
			draw_marker(renderer, my_markers[i], M_COLOR);

		if(marker_count == 4)
		{
			for(float i = 0.0f; i <= 1; i+=0.001f)
			{
				Vec2 current_pos = get_interpolation(my_markers, i);
				draw_marker(renderer, (Marker) {(Vec2) {current_pos.x, current_pos.y}, 50} ,ML_COLOR);
			}
		}

        SDL_RenderPresent(renderer);
        magick += DELAY_FPS / 100.0f;
        t = (sin(magick) + 1) / 2;
        SDL_Delay(DELAY_FPS);
    }

	// Quitter proprement
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
