#ifndef RTV1_TYPES_H
# define RTV1_TYPES_H

#include <SDL2/SDL.h>
#include "rgba.h"

typedef struct		s_rt
{
	unsigned int	*pixels;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_rt;


#endif
