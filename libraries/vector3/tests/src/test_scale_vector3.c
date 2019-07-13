#include "test_vector3.h"

int	test_scale_vector3(void)
{
	LOG_NAME
	char passed = 0;

	t_vector3 a = init_vector3(10, 10, 10);

	t_vector3 vec = scale_vector3(a, 3);

	if (vec.x == 30 && vec.y == 30 && vec.z == 30)
		passed = 1;

	return passed;
}
