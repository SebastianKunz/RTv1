#ifndef RGBA_H
# define RGBA_H

typedef struct s_rgba
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
}				t_rgba;

t_rgba	uint_to_rgba(unsigned int color);
t_rgba	mult_rgba(t_rgba rgba, float scalar);
t_rgba	init_rgba(unsigned char r, unsigned char g,
					unsigned char b, unsigned char a);

#endif
