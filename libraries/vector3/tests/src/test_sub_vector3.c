#include "test_vector3.h"

int	test_sub_vector3()
{
	LOG_NAME
	char passed = 0;

	t_vector3 *a = new_vector3(42, 42, 42);
	t_vector3 *b = new_vector3(12, 12, 12);

	t_vector3 c = sub_vector3(*a, *b);

	if (c.x == 30 && c.y == 30 && c.z == 30)
		passed = 1;
	free(a);
	free(b);

	return passed;
}