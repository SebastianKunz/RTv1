#include "test_vector3.h"

int	test_dot_vector3()
{
	LOG_NAME
	char pass = 0;

	t_vector3 a = init_vector3(1, 3, -5);
	t_vector3 b = init_vector3(4, -2, -1);

	float res = dot_vector3(a, b);

	if (res == 3)
		pass = 1;

	return pass;
}

