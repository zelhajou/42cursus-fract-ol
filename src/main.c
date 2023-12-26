/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:30:50 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/26 22:52:24 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// t_fractol *init_fractal(void) {
//     t_fractol *fractol = malloc(sizeof(t_fractol));
//     if (!fractol) return NULL;
// ****************************************************************
// 	// fractol->zoom = 1;
	// fractol->offset.x = 0;
	// fractol->offset.y = 0;
	// fractol->max_iterations = 100;
//     return fractol;
// }

int	main(void)
{
	t_fractol	fractol;

	ft_setup_window(&fractol);

	fractol.zoom = 1;
	fractol.max_iterations = 100;
	ft_setup_hooks(&fractol);
	ft_render_fractal(&fractol);
	mlx_loop(fractol.mlx_connextion);
	mlx_destroy_window(fractol.mlx_connextion, fractol.mlx_window);
	free(fractol.mlx_connextion);

	return (0);
}
