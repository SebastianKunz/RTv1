#ifndef VECTOR3_H
# define VECTOR3_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_vector3
{
	float		x;
	float		y;
	float		z;
}				t_vector3;

t_vector3	*new_vector3(float x, float y, float z);
t_vector3	init_vector3(float x, float y, float z);
t_vector3	add_vector3(t_vector3 a, t_vector3 b);
t_vector3	sub_vector3(t_vector3 a, t_vector3 b);
t_vector3	scale_vector3(t_vector3 a, float scalar);
t_vector3	normalize_vector3(t_vector3 vec);
float		dot_vector3(t_vector3 a, t_vector3 b);
float		magnitude_vector3(t_vector3 vec);
void		print_vector3(t_vector3 vec);

#endif
