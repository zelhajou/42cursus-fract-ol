/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:30:50 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/30 03:15:45 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	ft_init_fractal(&fractol, argc, argv);
	ft_setup_window(&fractol);
	ft_setup_hooks(&fractol);
	ft_initialize_image(&fractol);
	ft_render_fractal(&fractol);
	mlx_loop(fractol.mlx_connextion);
	ft_close_window(&fractol);
	return (0);
}
