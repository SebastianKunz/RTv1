#include "rtv1.h"
#include "rtv1_types.h"
#include "ray.h"
#include "sphere.h"

t_ray	init_ray(t_vector3 origin, t_vector3 direction)
{
	t_ray	ray;
	ray.origin = origin;
	ray.direction = origin;

	return ray;
}

t_rgba	trace_ray(t_ray ray, t_sphere sphere, unsigned int depth)
{
	double min_t = FLT_MAX;
	int 	min_i = -1;
	float	t = FLT_MAX;

	if (sphere_intersect(sphere, ray, &t)) {
		if (min_t < t)
			min_t = t;

		return sphere_shading(ray, sphere);
	}

	return init_rgba(0, 0, 0, 0);
}

t_rgba	trace(t_rt rt, int x, int y)
{
	t_vector3	origin = init_vector3(0, 0, 0);
	t_vector3	direction = normalize_vector3(init_vector3(x, y, 150));

	return trace_ray(init_ray(origin, direction), rt.sphere, 10);
}

void do_raytracing(t_rt *rt)
{
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			rt->pixels[y * SCREEN_HEIGHT + x] = trace(*rt, x, y);
		}
	}
}