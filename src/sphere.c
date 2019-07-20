#include "sphere.h"
#include "ray.h"

t_vector3	shpere_get_normal(t_sphere sphere, t_vector3 p)
{
	return scale_vector3(sub_vector3(p, sphere.center), (-1 / sphere.radius));
}

// t_rgba		sphere_shading(t_sphere sphere, t_lightsource light, float t)
// {
// 	// t_rgba color;
// 	// t_vector3 V = ray.direction;
// 	// t_vector3 P = scale_vector3(add_vector3(ray.origin, V), t);
// 	// t_vector3 N = shpere_get_normal(sphere, P);

// 	// float facing_ratio = dot_vector3(N, V);

// 	// color.r = sphere.color.r * (facing_ratio * 0.5);
// 	// color.g = sphere.color.g * (facing_ratio * 0.5);
// 	// color.b = sphere.color.b * (facing_ratio * 0.5);
// 	// return color;

// 	// t is where ray hits sphere

// 	// trace_ray(light.pos, )

// 	// float t;

// 	// t_vector3 dir =

// 	// if (sphere_intersect(sphere, init_ray(light.pos, dir), &t)) {

// 	// }

// 	return init_rgba(0, 0, 0, 255);

// 	// t_vector3 hit_point = scale_vector3(add_vector3(ray.origin, ray.direction), t);

// }

int			sphere_intersect(t_sphere sphere, t_ray *ray)
{
	// const float A = dot_vector3(ray.direction, ray.direction);
	// t_vector3 dist = sub_vector3(ray.origin, sphere.center);

	// const float B = 2 * dot_vector3(ray.direction, dist);
	// const float C = dot_vector3(dist, dist) - (sphere.radius * sphere.radius);
	// float discr = B * B - 4 * A * C;

	// if (discr < 1e-4) {
	// 	*t = -1.0f;
	// 	return 0;
	// }

	// const float sqrt_discr = sqrt(discr);
	// const float T0 = (-B + sqrt_discr) / 2;
	// const float T1 = (-B - sqrt_discr) / 2;

	// *t = (T0 < T1) ? T1 : T0;

	// return 1;


	t_vector3 origin_to_sphere = sub_vector3(sphere.center, ray->origin);
	float projection = dot_vector3(origin_to_sphere, ray->direction);
	t_vector3 distance_vec = sub_vector3(origin_to_sphere, scale_vector3(ray->direction, projection));
	float distance_sq = dot_vector3(distance_vec, distance_vec);
	float radius_sq = sphere.radius * sphere.radius;

	if (distance_sq > radius_sq)
		return 0;

	float new_len = projection - sqrtf(radius_sq - distance_sq);

	if (new_len < ray->length && new_len > 0.0f)
	{
		ray->length = new_len;
		return 1;
	}

	return 0;
}
