#ifndef RTV1_TYPES_H
# define RTV1_TYPES_H

#include <SDL2/SDL.h>
#include "vector3.h"
#include "rgba.h"

typedef struct	s_ray
{
	t_vector3	origin;
	t_vector3	direction;
	float		length;
}				t_ray;

typedef struct		s_screen
{
	// The center point of the screen.
	t_vector3		center;
	// The top left point of the screen.
	t_vector3		top_left;
	// The top right point of the screen.
	t_vector3		top_right;
	// The bottom left point of the screen.
	t_vector3		bottom_left;
	// The bottom right point of the screen.
	t_vector3		bottom_right;
	// Describes how far away the screen is from the camera. Simulates Field Of View (FOV)
	float			distance;
}					t_screen;

typedef struct		s_camera
{
	t_vector3		pos;
	t_vector3		view_dir;
}					t_camera;

typedef	struct		s_lightsource
{
	t_vector3		pos;
	t_rgba			intensity;
}					t_lightsource;

typedef struct		s_material
{
	t_rgba			diffuse;
	float			reflection;
}					t_material;

typedef struct	s_sphere
{
	float		radius;
	t_vector3	center;
	t_rgba		color;
	char		material_id;
}				t_sphere;

enum	e_materials
{
	GLASS,
};

typedef struct		s_rt
{
	t_rgba			*pixels;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_sphere		sphere;
	t_lightsource	light;
	t_camera		camera;
	t_screen		screen;

	float			theta_x;
	float			theta_y;
	float			d_theta;
}					t_rt;

#endif
