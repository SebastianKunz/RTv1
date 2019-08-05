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

// Returns a pointer to a new vector allocated on heap
t_vector3	*new_vector3(float x, float y, float z);
// Returns a new vector allocated on stack
t_vector3	init_vector3(float x, float y, float z);
// Adds vector a to vector b. Returns new vector on stack
t_vector3	add_vector3(t_vector3 a, t_vector3 b);
// Subtracts vector a from vector b. Returns new vector on stack
t_vector3	sub_vector3(t_vector3 a, t_vector3 b);
// Scales vector a by float scalar. Returns new vector on stack
t_vector3	scale_vector3(t_vector3 a, float scalar);
// Normalizes vec. Returns new vector allocated on stack
t_vector3	normalize_vector3(t_vector3 vec);
// Normalizes vec by reference
void		normalize_vector3_ref(t_vector3 *vec);
// Returns the dot product of vector a and b
float		dot_vector3(t_vector3 a, t_vector3 b);
// Returns the magnitude of vector vec
float		magnitude_vector3(t_vector3 vec);
// Prints vector vec
void		print_vector3(t_vector3 vec);

#endif
