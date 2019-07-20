#ifndef CAMERA_H
# define CAMERA_H

#include "rtv1_types.h"

void	update_camera(t_rt *rt, t_vector3 new_pos, t_vector3 new_dir);
void	init_camera(t_rt *rt);

#endif
