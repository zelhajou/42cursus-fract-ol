/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:26:30 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/27 17:44:32 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_calculate_julia(t_fractol *fractol, int max_iterations)
{
	return (ft_iterate_fractal(fractol->z, fractol->c, max_iterations));
}

int	ft_calculate_mandelbrot(t_fractol *fractol, int max_iterations)
{
	fractol->c.real = 0;
	fractol->c.imaginary = 0;
	return (ft_iterate_fractal(fractol->c, fractol->z, max_iterations));
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

void	ft_setup_fractal_params(t_fractol *fractol)
{
	double	half_width;
	double	half_height;

	half_width = WINDOW_WIDTH / 2.0;
	half_height = WINDOW_HEIGHT / 2.0;
	fractol->c.real = (fractol->offset.x - half_width)
		* (4.0 * fractol->zoom) / WINDOW_WIDTH;
	fractol->c.imaginary = (half_height - fractol->offset.y)
		* (4.0 * fractol->zoom) / WINDOW_HEIGHT;
}

int	ft_render_fractal(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	ft_setup_fractal_params(fractol);
	ft_initialize_image(fractol);
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
