/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:06:53 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/26 22:31:11 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_close_window(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx_connextion, fractol->mlx_window);
	free(fractol->mlx_connextion);
	exit(0);
}

void ft_init_window(t_fractol *fractol) {
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

void	ft_setup_window(t_fractol *fractol)
{
	ft_init_window(fractol);
	
}
