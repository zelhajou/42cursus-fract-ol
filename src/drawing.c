/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:57:43 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/27 17:44:23 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel_to_image(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = fractol->image.addr + (y * fractol->image.line_length
				+ x * (fractol->image.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// Scaling pixel_to_complex
double	ft_scale_coordinate_x(t_fractol *fractol, int x)
{
	double	half_width;

	half_width = WINDOW_WIDTH / 2.0;
	return ((x - half_width) * (4.0 * fractol->zoom) / WINDOW_WIDTH);
}

double	ft_scale_coordinate_y(t_fractol *fractol, int y)
{
	double	half_height;

	half_height = WINDOW_HEIGHT / 2.0;
	return (((WINDOW_HEIGHT - y) - half_height)
		* (4.0 * fractol->zoom) / WINDOW_HEIGHT);
}

void	ft_draw_fractal_pixel(t_fractol *fractol, int x, int y)
{
	int	color;
	int	iterations;

	fractol->z.real = ft_scale_coordinate_x(fractol, x);
	fractol->z.imaginary = ft_scale_coordinate_y(fractol, y);
	iterations = ft_calculate_julia(fractol, fractol->max_iterations);
	color = ft_determine_color(iterations, fractol->max_iterations);
	ft_put_pixel_to_image(fractol, x, y, color);
}
