#include "test_vector3.h"

int	test_init_vector3(void)
{
	LOG_NAME
	char passed = 0;

	t_vector3 vec = init_vector3(1, 2, 3);

	if (vec.x == 1 && vec.y == 2 && vec.z == 3)
		passed = 1;

	return passed;
}
