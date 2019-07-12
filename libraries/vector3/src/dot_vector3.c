#include "vector3.h"

float	dot_vector3(t_vector3 a, t_vector3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}