#include "test_vector3.h"

int	test_normalize_vector3_ref(void)
{
	LOG_NAME
	char passed = 0;

	t_vector3 vec = init_vector3(1, 21, 42);
	normalize_vector3_ref(&vec);

	vec.x = roundf(vec.x * 100) / 100;
	vec.y = roundf(vec.y * 100) / 100;
	vec.z = roundf(vec.z * 100) / 100;

	if (vec.x == 0.02f && vec.y == 0.45f && vec.z == 0.89f)
		passed = 1;
	else
		print_vector3(vec);

	return passed;
}