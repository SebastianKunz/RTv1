#include "vector3.h"

t_vector3 scale_vector3(t_vector3 a, float scalar)
{
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;

	return a;
}