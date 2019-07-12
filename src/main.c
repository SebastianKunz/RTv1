#include <SDL2/SDL.h>
#include <stdio.h>

#include "rtv1.h"
#include "rtv1_types.h"
#include "vector3.h"

void raytracer(Uint32 *pixel_buffer)
{
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{

		}
	}
}

void put_pixel(int x, int y, Uint32 *pixel_buffer)
{
	pixel_buffer[y * SCREEN_WIDTH + x] = 0;
}

void draw_circle(int radius, int x0, int y0, Uint32 *pixel_buffer)
{
	int f = 1 - radius;
    int ddF_x = 0;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;

	put_pixel(x0, y0, pixel_buffer);
    put_pixel(x0, y0 + radius, pixel_buffer);
    put_pixel(x0, y0 - radius, pixel_buffer);
    put_pixel(x0 + radius, y0, pixel_buffer);
    put_pixel(x0 - radius, y0, pixel_buffer);

    while(x < y)
    {
        if(f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x + 1;
        put_pixel(x0 + x, y0 + y, pixel_buffer);
        put_pixel(x0 - x, y0 + y, pixel_buffer);
        put_pixel(x0 + x, y0 - y, pixel_buffer);
        put_pixel(x0 - x, y0 - y, pixel_buffer);
        put_pixel(x0 + y, y0 + x, pixel_buffer);
        put_pixel(x0 - y, y0 + x, pixel_buffer);
        put_pixel(x0 + y, y0 - x, pixel_buffer);
        put_pixel(x0 - y, y0 - x, pixel_buffer);
    }
}

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
	rt->pixels = malloc(sizeof(unsigned int) * SCREEN_HEIGHT * SCREEN_WIDTH);
	memset(rt->pixels, 0, sizeof(unsigned int) * SCREEN_HEIGHT * SCREEN_WIDTH);
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
			color = uint_to_rgba(rt->pixels[y * SCREEN_HEIGHT + x]);
			// printf("color: %u, r: %u, g: %u, b: %u, a: %u\n", rt->pixels[y * SCREEN_HEIGHT + x], color.r, color.g, color.b, color.a);
			SDL_SetRenderDrawColor(rt->renderer,
				color.r, color.g, color.b, color.a);
			SDL_RenderDrawPoint(rt->renderer, x, y);
		}
	SDL_RenderPresent(rt->renderer);
}

int main()
{
	t_rt	rt;
    SDL_Event		event;
	char quit = 0;

	init_sdl(&rt);
	render_window(&rt);
    while (!quit)
    {
		quit = get_events(&event);
    }
	rt_cleanup(&rt);
	SDL_Quit();
	return 0;
}