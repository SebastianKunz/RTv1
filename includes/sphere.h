#ifndef SPHERE_H
# define SPHERE_H

#include "rtv1_types.h"

int			sphere_intersect(t_sphere sphere, t_ray *ray);
t_rgba		sphere_shading(t_sphere sphere, t_lightsource light, float t);

#endif
