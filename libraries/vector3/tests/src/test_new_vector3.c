#include "test_vector3.h"

int test_new_vector3(void)
{
	LOG_NAME
	char passed = 0;

	t_vector3 *vec = new_vector3(42, 42, 42);

	if (vec && vec->x == 42 && vec->y == 42 && vec->z == 42)
		passed = 1;

	if (vec)
		free(vec);

	return passed;
}