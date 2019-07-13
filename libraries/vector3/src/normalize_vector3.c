#include "vector3.h"

t_vector3	normalize_vector3(t_vector3 vec)
{
	return scale_vector3(vec, 1 / magnitude_vector3(vec));
}
