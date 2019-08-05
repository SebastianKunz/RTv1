#include "vector3.h"

void	normalize_vector3_ref(t_vector3 *vec)
{
	*vec = scale_vector3(*vec, 1 / magnitude_vector3(*vec));
}