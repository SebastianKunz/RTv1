#ifndef TEST_VECTOR3_H
# define TEST_VECTOR3_H

# define LOG_NAME printf("%s... ", __func__);

#include "vector3.h"
#include <stdio.h>

int	test_new_vector3(void);
int	test_init_vector3(void);
int test_sub_vector3(void);
int test_add_vector3(void);
int	test_scale_vector3(void);
int test_dot_vector3(void);
int	test_magnitude_vector3(void);
int	test_normalize_vector3(void);
int	test_normalize_vector3_ref(void);

#endif
