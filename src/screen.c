#include "screen.h"

void	update_screen(t_rt *rt, float distance)
{
	rt->screen.distance = distance;

	rt->screen.center = add_vector3(rt->camera.pos, scale_vector3(rt->camera.view_dir, distance));
	rt->screen.top_left = add_vector3(rt->screen.center, init_vector3(-1, 1, 0));
	rt->screen.top_right = add_vector3(rt->screen.center, init_vector3(1, 1, 0));
	rt->screen.bottom_left = add_vector3(rt->screen.center, init_vector3(-1, -1, 0));
	rt->screen.bottom_right = add_vector3(rt->screen.center, init_vector3(1, -1, 0));

}

void	init_screen(t_rt *rt, float distance)
{
	rt->screen.distance = distance;

	rt->screen.center = add_vector3(rt->camera.pos, scale_vector3(rt->camera.view_dir, distance));
	rt->screen.top_left = add_vector3(rt->screen.center, init_vector3(-1, 1, 0));
	rt->screen.top_right = add_vector3(rt->screen.center, init_vector3(1, 1, 0));
	rt->screen.bottom_left = add_vector3(rt->screen.center, init_vector3(-1, -1, 0));
	rt->screen.bottom_right = add_vector3(rt->screen.center, init_vector3(1, -1, 0));
}
