#include "rgba.h"

t_rgba	uint_to_rgba(unsigned int color)
{
	t_rgba result;

	result.r = color >> 24 & 255;
	result.g = color >> 16 & 255;
	result.b = color >> 8 & 255;
	result.a = color & 255;

	return result;
}