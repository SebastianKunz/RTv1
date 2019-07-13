#ifndef RTV1_TYPES_H
# define RTV1_TYPES_H

#include <SDL2/SDL.h>
#include "vector3.h"
#include "rgba.h"

typedef struct	s_sphere
{
	float		radius;
	t_vector3	center;
	t_rgba		color;

}				t_sphere;

typedef struct	s_ray
{
	t_vector3	origin;
	t_vector3	direction;
}				t_ray;

typedef struct		s_rt
{
	t_rgba			*pixels;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_ray			ray;
	t_sphere		sphere;

}					t_rt;


#endif
