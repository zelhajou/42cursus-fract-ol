/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:57:43 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/25 22:15:40 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "drawing.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ft_put_pixel(t_data *data, int x, int y, int color)
{
    char *pxl;

    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

struct s_complex{
	double real;
	double imag;
};

int function(struct s_complex c, struct s_complex z, int max_iterations)
{
	while (max_iterations)
	{
		double r = z.real * z.real - z.imag * z.imag + c.real;
		double i = 2 * z.real * z.imag + c.imag;
		z.real = r;
		z.imag = i;
		if (z.real * z.real + z.imag * z.imag > 4)
			return max_iterations;
		max_iterations--;
	}
	return (max_iterations);
}


int	ft_render_fractal(t_gfx_env *env)
{
	t_data	img;
	int x, y, color = 0;
	struct s_complex n;
	struct s_complex c;

	c.real = (env->mouse.x - WINDOW_WIDTH / 2.0) * (4.0 * env->mouse.zoom) / WINDOW_WIDTH;;
	c.imag = ((WINDOW_HEIGHT - env->mouse.y) - WINDOW_HEIGHT / 2.0) * (4.0 * env->mouse.zoom) / WINDOW_HEIGHT;;
	// int color = rand() % 0xFFFFFF;
	img.img = mlx_new_image(&img, WINDOW_HEIGHT, WINDOW_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// &img.bits_per_pixel, &img.line_length, &img.endian);

	for (y = 0; y < WINDOW_WIDTH; y++) {
        for (x = 0; x < WINDOW_HEIGHT; x++) {
			n.real = (x - WINDOW_WIDTH / 2.0) * (4.0 * env->mouse.zoom) / WINDOW_WIDTH;
			n.imag = ((WINDOW_HEIGHT - y) - WINDOW_HEIGHT / 2.0) * (4.0 * env->mouse.zoom) / WINDOW_HEIGHT;
			color = function(c, n, 100);
			my_mlx_pixel_put(&img, x, y, color * 0x0608F2);
		}
	}
	mlx_put_image_to_window(env->mlx_connextion, env->mlx_window, img.img, 0, 0);
	//mlx_string_put(env->mlx_connextion, env->mlx_window, 5, 5, 0, "Fractol");
	return (0);
}