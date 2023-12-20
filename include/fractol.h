#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>



typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif