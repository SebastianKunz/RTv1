#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

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

int main()
{
	SDL_Window* window = NULL;
	SDL_Renderer *renderer = NULL;
   	char quit = 0;
    SDL_Event event;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
		return 1;
	}
	window = SDL_CreateWindow(
				"RTv1",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN
				);
	if (window == NULL) {
		fprintf(stderr, "could not create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Texture *texture = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_ABGR8888,
		SDL_TEXTUREACCESS_STATIC,
		SCREEN_WIDTH,
		SCREEN_HEIGHT
	);

	Uint32 *pixels = malloc(sizeof(Uint32) * SCREEN_HEIGHT * SCREEN_WIDTH);

	Uint32 color = 0x4287f5;

	memset(pixels, color, sizeof(Uint32) * SCREEN_HEIGHT * SCREEN_WIDTH);
	draw_circle(30, 300, 200, pixels);

	raytracer(pixels);

	char left_mouse_down = 0;


    while (!quit)
    {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		for (int i = 0; i < SCREEN_HEIGHT; ++i)
			SDL_RenderDrawPoint(renderer, i, i);

        SDL_WaitEvent(&event);
        switch (event.type)
        {
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
					left_mouse_down = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
					left_mouse_down = 1;
				break;
			case SDL_MOUSEMOTION:
				if (left_mouse_down)
				{
					int mouse_x = event.motion.x;
					int mouse_y = event.motion.y;
    				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
					SDL_RenderDrawPoint(renderer, mouse_x, mouse_y);
				}
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_c:
						// SDL_RenderClear(renderer);
						break;
				}
				break;

            case SDL_QUIT:
                quit = 1;
                break;
        }

        SDL_RenderPresent(renderer);
    }

	free(pixels);
	SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}