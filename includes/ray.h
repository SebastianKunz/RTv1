#ifndef RAY_H
# define RAY_H

#include "rtv1_types.h"

t_ray	init_ray(t_vector3 origin, t_vector3 direction, float length);
void do_raytracing(t_rt *rt);
t_rgba	trace_ray(t_rt rt, t_ray ray, t_sphere sphere, unsigned int depth);
void do_raytracing(t_rt *rt);

#endif
