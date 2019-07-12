#include "vector3.h"

t_vector3	sub_vector3(t_vector3 a, t_vector3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;

	return a;
}