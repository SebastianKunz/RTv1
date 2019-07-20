#include "rtv1.h"
#include "rtv1_types.h"
#include "ray.h"
#include "sphere.h"

t_ray	init_ray(t_vector3 origin, t_vector3 direction, float length)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.length = length;
	return ray;
}

t_vector3	calculate_point_on_screen(t_screen screen, float u, float v)
{
	t_vector3 width_v = scale_vector3(sub_vector3(screen.top_right, screen.top_left), u);
	t_vector3 first = add_vector3(screen.top_left, width_v);
	t_vector3 height_v = scale_vector3(sub_vector3(screen.bottom_left, screen.top_left), v);

	return add_vector3(first, height_v);
}

void do_raytracing(t_rt *rt)
{
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			float u = (float)x / SCREEN_WIDTH;
			float v = (float)y / SCREEN_HEIGHT;

			t_vector3 point_on_screen = calculate_point_on_screen(rt->screen, u, v);
			t_vector3 ray_dir = sub_vector3(point_on_screen, rt->camera.pos);
			t_ray ray = init_ray(rt->camera.pos, normalize_vector3(ray_dir), 10000000.0f);

			if (sphere_intersect(rt->sphere, &ray))
				rt->pixels[y * SCREEN_HEIGHT + x] = rt->sphere.color;
		}
	}
}
