/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:57:43 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/27 00:03:57 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT) {
		dst = fractol->image.addr + (y * fractol->image.line_length
				+ x * (fractol->image.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// Scaling pixel_to_complex
double	ft_scale_coordinate_x(t_fractol *fractol, int x) {
    double half_width = WINDOW_WIDTH / 2.0;
    return ((x - half_width) * (4.0 * fractol->zoom) / WINDOW_WIDTH);
}

double	ft_scale_coordinate_y(t_fractol *fractol, int y) {
    double half_height = WINDOW_HEIGHT / 2.0;
    return (((WINDOW_HEIGHT - y) - half_height)
			* (4.0 * fractol->zoom) / WINDOW_HEIGHT);
}

void	ft_setup_fractal_params(t_fractol *fractol)
{
	double half_width = WINDOW_WIDTH / 2.0;
    double half_height = WINDOW_HEIGHT / 2.0;

    fractol->c.real = (fractol->offset.x - half_width)
		* (4.0 * fractol->zoom) / WINDOW_WIDTH;
    fractol->c.imaginary = (half_height - fractol->offset.y)
		* (4.0 * fractol->zoom) / WINDOW_HEIGHT;
}

void	ft_initialize_image(t_fractol *fractol)
{
	fractol->image.img_ptr = mlx_new_image(&fractol->image,
			WINDOW_HEIGHT, WINDOW_WIDTH);
	  if (!fractol->image.img_ptr) {
        // 
        exit(EXIT_FAILURE);
    }
	fractol->image.addr = mlx_get_data_addr(fractol->image.img_ptr,
			&fractol->image.bits_per_pixel, &fractol->image.line_length,
			&fractol->image.endian);
	 if (!fractol->image.addr) {
        //
        exit(EXIT_FAILURE);
    }
}

int determine_color(int iterations, int max_iterations) {
    int color;
    double t;

    if (iterations == max_iterations) {
        color = 0x000000;
    } else {
        t = (double)iterations / max_iterations;
        color = (int)(9 * (1 - t) * t * t * t * 255) << 16 |
                (int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8 |
                (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    }
    return color;
}

void	draw_fractal_pixel(t_fractol *fractol, int x, int y)
{
    int color;
	int iterations;

	color = 0;
	fractol->z.real = ft_scale_coordinate_x(fractol, x);
	fractol->z.imaginary = ft_scale_coordinate_y(fractol, y);
	iterations = calculate_mandelbrot(fractol, fractol->max_iterations);

	color = determine_color(iterations, fractol->max_iterations);
	put_pixel_to_image(fractol, x, y, color);
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
			draw_fractal_pixel(fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connextion, fractol->mlx_window, fractol->image.img_ptr, 0, 0);
	return (0);
}