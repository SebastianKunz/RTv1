#include "test_vector3.h"

int	test_normalize_vector3(void)
{
	LOG_NAME
	char passed = 0;

	t_vector3 vec = init_vector3(1, 21, 42);
	t_vector3 normalized_vec = normalize_vector3(vec);

	normalized_vec.x = roundf(normalized_vec.x * 100) / 100;
	normalized_vec.y = roundf(normalized_vec.y * 100) / 100;
	normalized_vec.z = roundf(normalized_vec.z * 100) / 100;

	if (normalized_vec.x == 0.02f && normalized_vec.y == 0.45f && normalized_vec.z == 0.89f)
		passed = 1;
	else
		print_vector3(normalized_vec);

	return passed;
}
