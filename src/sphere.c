#include "sphere.h"
#include "ray.h"

// p - center * (-1 / radius)
t_vector3	shpere_get_normal(t_sphere sphere, t_vector3 p)
{
	return scale_vector3(sub_vector3(p, sphere.center), (-1 / sphere.radius));
}

t_rgba		sphere_shading(t_ray ray, t_sphere sphere)
{
	float t;
	t_rgba color = init_rgba(0, 0, 0, 0);

	if (sphere_intersect(sphere, ray, &t)) {
		t_vector3 V = ray.direction;
		t_vector3 P = scale_vector3(add_vector3(ray.origin, V), t);
		t_vector3 N = shpere_get_normal(sphere, P);

		float facing_ratio = dot_vector3(N, V);

		color.r = sphere.color.r * (facing_ratio * 0.5);
		color.g = sphere.color.g * (facing_ratio * 0.5);
		color.b = sphere.color.b * (facing_ratio * 0.5);
	}

	return color;
}

int			sphere_intersect(t_sphere sphere, t_ray ray, float *t)
{
	// float t = dot_vector3(sub_vector3(sphere.center, ray.origin), ray.direction);

	// // ray.origin + ray.direction * t
	// t_vector3 p = scale_vector3(add_vector3(ray.origin, ray.direction), t);

	// float y = magnitude_vector3(sub_vector3(sphere.center, p));

	// if (y < sphere.radius)
	// 	return 0;

	// float x = sqrt(sphere.radius * sphere.radius - y * y);
	// float t1 = t - x;
	// float t2 = t + x;

	// *first_intersection = t1 < t2 ? t1 : t2;

	t_vector3	o = ray.origin;
	t_vector3	d = ray.direction;

	t_vector3	v = sub_vector3(o, sphere.center);

	const float b = dot_vector3(v, d) * 2;
	const float c = dot_vector3(v, v) - sphere.radius * sphere.radius;

	float delta = b * b - 4 * c;

	if (delta < 1e-4)
		return 0;

	const float t1 = (-b - sqrt(delta))/2;
	const float t2 = (-b + sqrt(delta))/2;

	*t = (t1 < t2) ? t1 : t2; // get the first intersection only

	return 1;
}
