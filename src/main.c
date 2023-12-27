/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:30:50 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/27 16:03:34 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractol *fractol)
{
	fractol->zoom = 1;
	fractol->offset.x = 0;
	fractol->offset.y = 0;
	fractol->max_iterations = 100;
}

int	main(void)
{
	t_fractol	fractol;

	ft_setup_window(&fractol);
	init_fractal(&fractol);
	ft_setup_hooks(&fractol);
	ft_render_fractal(&fractol);
	mlx_loop(fractol.mlx_connextion);
	mlx_destroy_window(fractol.mlx_connextion, fractol.mlx_window);
	free(fractol.mlx_connextion);
	return (0);
}
