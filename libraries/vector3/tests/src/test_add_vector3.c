#include "test_vector3.h"

int test_add_vector3()
{
	LOG_NAME
	char passed = 0;

	t_vector3 *a = new_vector3(30, 30, 30);
	t_vector3 *b = new_vector3(12, 12, 12);

	t_vector3 c = add_vector3(*a, *b);

	if (c.x == 42 && c.y == 42 && c.z == 42)
		passed = 1;
	free(a);
	free(b);

	return passed;
}