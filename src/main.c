#include <SDL2/SDL.h>
#include <stdio.h>

#include "rtv1.h"
#include "rtv1_types.h"
#include "ray.h"
#include "screen.h"
#include "camera.h"

void rt_cleanup(t_rt *rt)
{
	free(rt->pixels);
    SDL_DestroyRenderer(rt->renderer);
	SDL_DestroyWindow(rt->window);
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

void	update_window(t_rt *rt)
{
	do_raytracing(rt);
	render_window(rt);
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

	return 1;
}

int get_events(SDL_Event *event, t_rt *rt)
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
				case SDLK_w:
					; // this is required, because of smth
					t_camera cam = cam = rt->camera;
					t_vector3 new_pos = add_vector3(cam.pos, init_vector3(0, 0, 1));
					update_camera(rt, new_pos, cam.view_dir);
					update_window(rt);
					return 0;
				case SDLK_s:
					rt->camera.pos.z -= 1.0f;
					update_window(rt);
					return 0;
			}
			break;
		case SDL_QUIT:
			return 1;
			break;
	}
	return 0;
}


void	init_scene(t_rt *rt)
{
	init_camera(rt);

	rt->sphere.radius = 1.0f;
	rt->sphere.center = init_vector3(0, 0, 5);
	rt->sphere.color = init_rgba(255, 0, 0, 255);

	rt->light.intensity = init_rgba(255, 255, 255, 255);
	rt->light.pos = init_vector3(100, 100, 100);

	rt->pixels = malloc(sizeof(t_rgba) * SCREEN_HEIGHT * SCREEN_WIDTH);
	memset(rt->pixels, 0, sizeof(t_rgba) * SCREEN_HEIGHT * SCREEN_WIDTH);
}

int main()
{
	t_rt			rt;
    SDL_Event		event;
	char			quit = 0;

	init_sdl(&rt);
	init_scene(&rt);
	init_screen(&rt, 1.0f);
	update_window(&rt);
	while (!quit) {
		quit = get_events(&event, &rt);
	}
	rt_cleanup(&rt);
	SDL_Quit();

	return 0;
}