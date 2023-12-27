/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:06:53 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/27 16:36:37 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_setup_window(t_fractol *fractol)
{
	ft_init_window(fractol);
}

void	ft_init_window(t_fractol *fractol)
{
	fractol->mlx_connextion = mlx_init();
	if (!fractol->mlx_connextion)
		exit(1);
	fractol->mlx_window = mlx_new_window(fractol->mlx_connextion,
			WINDOW_HEIGHT, WINDOW_WIDTH, "Fractol");
	if (!fractol->mlx_window)
	{
		mlx_destroy_window(fractol->mlx_connextion, fractol->mlx_window);
		free(fractol->mlx_connextion);
		exit(1);
	}
}

int	ft_close_window(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx_connextion, fractol->mlx_window);
	free(fractol->mlx_connextion);
	exit(EXIT_FAILURE);
}

void	ft_initialize_image(t_fractol *fractol)
{
	fractol->image.img_ptr = mlx_new_image(&fractol->image,
			WINDOW_HEIGHT, WINDOW_WIDTH);
	if (!fractol->image.img_ptr)
	{
		exit(EXIT_FAILURE);
	}
	fractol->image.addr = mlx_get_data_addr(fractol->image.img_ptr,
			&fractol->image.bits_per_pixel, &fractol->image.line_length,
			&fractol->image.endian);
	if (!fractol->image.addr)
	{
		exit(EXIT_FAILURE);
	}
}
