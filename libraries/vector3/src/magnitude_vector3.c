#include "vector3.h"

float	magnitude_vector3(t_vector3 vec)
{
	return	sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
