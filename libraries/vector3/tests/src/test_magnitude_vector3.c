#include "test_vector3.h"

int	test_magnitude_vector3(void)
{
	LOG_NAME
	t_vector3 vec = init_vector3(1, 2, 3);
	char passed = 0;

	float len = magnitude_vector3(vec);

	len = roundf(len * 100) / 100;
	if (len == 3.74f)
		passed = 1;
	else
		printf("len is %f ", len);

	return passed;
}
