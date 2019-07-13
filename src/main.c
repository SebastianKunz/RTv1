#include <SDL2/SDL.h>
#include <stdio.h>

#include "rtv1.h"
#include "rtv1_types.h"
#include "ray.h"

void rt_cleanup(t_rt *rt)
{
	free(rt->pixels);
    SDL_DestroyRenderer(rt->renderer);
	SDL_DestroyWindow(rt->window);
}

int init_sdl(t_rt *rt)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
		return 0;
	}
	rt->window = SDL_CreateWindow(
					"RTv1",
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					SCREEN_WIDTH, SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN
				);
	if (!rt->window)
		return 0;
	rt->renderer = SDL_CreateRenderer(rt->window, -1, SDL_RENDERER_ACCELERATED);
	rt->pixels = malloc(sizeof(t_rgba) * SCREEN_HEIGHT * SCREEN_WIDTH);
	memset(rt->pixels, 0, sizeof(t_rgba) * SCREEN_HEIGHT * SCREEN_WIDTH);
	return 1;
}

int get_events(SDL_Event *event)
{
	SDL_WaitEvent(event);
	switch (event->type)
	{
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym)
			{
				case SDLK_q:
					return 1;
					break;
			}
			break;
		case SDL_QUIT:
			return 1;
			break;
	}
	return 0;
}

void	render_window(t_rt *rt)
{
	t_rgba color;

	for (int y = 0; y < SCREEN_HEIGHT; y++)
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			color = rt->pixels[y * SCREEN_HEIGHT + x];
			// printf("r: %u, g: %u, b: %u, a: %u\n", color.r, color.g, color.b, color.a);
			SDL_SetRenderDrawColor(rt->renderer,
				color.r, color.g, color.b, color.a);
			SDL_RenderDrawPoint(rt->renderer, x, y);
		}
	SDL_RenderPresent(rt->renderer);
}

int main()
{
	t_rt			rt;
    SDL_Event		event;
	char			quit = 0;

	init_sdl(&rt);
	rt.sphere.radius = 100;
	rt.sphere.center = init_vector3(200, 250, 220);
	rt.sphere.color = init_rgba(255, 0, 0, 255);
	do_raytracing(&rt);
	render_window(&rt);

    while (!quit)
    {
		quit = get_events(&event);
    }
	rt_cleanup(&rt);
	SDL_Quit();
	return 0;
}