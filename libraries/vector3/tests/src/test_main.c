#include "test_vector3.h"

int total_tested = 0;
int was_successful = 0;
int was_failure = 0;

void check(int success)
{
	total_tested++;
	if (success)
	{
		was_successful++;
		printf("\33[0;32mpassed\n");
	}
	else
	{
		was_failure++;
		printf("\33[0;31mfailed\n");
	}
	printf("\33[0;0m");
}

void print_results()
{
	printf("%d/%d passed\n", was_successful, total_tested);
}

int main()
{

	check(test_new_vector3());
	check(test_sub_vector3());
	check(test_add_vector3());
	check(test_scale_vector3());
	check(test_dot_vector3());

	print_results();
	return 0;
}