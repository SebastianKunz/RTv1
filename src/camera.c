#include "camera.h"
#include "ray.h"

void	update_camera(t_rt *rt, t_vector3 new_pos, t_vector3 new_dir)
{
	rt->camera.pos = new_pos;
	rt->camera.view_dir = new_dir;
}

void	move_camera(t_camera *camera)
{
	// camera->pos
}

void	init_camera(t_rt *rt)
{
	rt->camera.pos = init_vector3(0, 0, 1);
	rt->camera.view_dir = init_vector3(0, 0, 1);
}