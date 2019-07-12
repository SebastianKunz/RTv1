#ifndef VECTOR3_H
# define VECTOR3_H

#include <stdlib.h>

typedef struct	s_vector3
{
	float		x;
	float		y;
	float		z;
}				t_vector3;

t_vector3	*new_vector3(float x, float y, float z);
t_vector3	add_vector3(t_vector3 a, t_vector3 b);
t_vector3	sub_vector3(t_vector3 a, t_vector3 b);
t_vector3	scale_vector3(t_vector3 a, float scalar);
float		dot_vector3(t_vector3 a, t_vector3 b);

#endif
