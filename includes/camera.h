#ifndef CAMERA_H
# define CAMERA_H

#include "rtv1_types.h"

void	move_camera(t_camera *camera, t_vector3 move_by, t_vector3 rotate_by);
void	init_camera(t_rt *rt);

#endif
