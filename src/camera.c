#include "camera.h"
#include "ray.h"

static void	update_camera(t_camera *camera, t_vector3 new_pos, t_vector3 new_dir)
{
	if (!camera)
		return ;
	camera->pos = new_pos;
	camera->view_dir = new_dir;
}

void	move_camera(t_camera *camera, t_vector3 move_by, t_vector3 rotate_by)
{
	if (!camera)
		return ;

	t_vector3 new_pos = add_vector3(move_by, camera->pos);
	t_vector3 new_dir = add_vector3(rotate_by, rotate_by);

	update_camera(camera, new_pos, new_dir);
}

void	init_camera(t_rt *rt)
{
	rt->camera.pos = init_vector3(0, 0, 1);
	rt->camera.view_dir = init_vector3(0, 0, 1);
}