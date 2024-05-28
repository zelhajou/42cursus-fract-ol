/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:26:30 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/31 17:44:17 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_calculate_julia(t_fractol *fractol, int max_iterations)
{
	if (fractol->fractal_config.type == 'J')
	{
		fractol->cst.real = fractol->fractal_config.julia_x;
		fractol->cst.imaginary = fractol->fractal_config.julia_y;
	}
	return (ft_iterate_fractal(fractol->pixel, fractol->cst, max_iterations));
}

int	ft_calculate_mandelbrot(t_fractol *fractol, int max_iterations)
{
	fractol->cst.real = 0;
	fractol->cst.imaginary = 0;
	return (ft_iterate_fractal(fractol->cst, fractol->pixel, max_iterations));
}

int	ft_iterate_fractal(t_complex z, t_complex c, int max_iterations)
{
	int		iterations;
	double	real;
	double	imaginary;

	iterations = 0;
	while (iterations < max_iterations)
	{
		real = z.real * z.real - z.imaginary * z.imaginary + c.real;
		imaginary = 2 * z.real * z.imaginary + c.imaginary;
		z.real = real;
		z.imaginary = imaginary;
		if (z.real * z.real + z.imaginary * z.imaginary > 4)
			break ;
		iterations++;
	}
	return (iterations);
}

int	ft_render_fractal(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_WIDTH)
	{
		x = 0;
		while (x < WINDOW_HEIGHT)
		{
			ft_draw_fractal_pixel(fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connextion, fractol->mlx_window,
		fractol->image.img_ptr, 0, 0);
	return (0);
}
