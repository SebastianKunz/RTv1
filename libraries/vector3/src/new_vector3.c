#include "vector3.h"
#include <string.h>

t_vector3	*new_vector3(float x, float y, float z)
{
	t_vector3 *vec;

	vec = malloc(sizeof(t_vector3));
	if (!vec)
		return NULL;

	vec->x = x;
	vec->y = y;
	vec->z = z;

	return vec;
}
