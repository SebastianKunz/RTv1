#include "vector3.h"

t_vector3	init_vector3(float x, float y, float z)
{
	t_vector3 vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;

	return vec;
}