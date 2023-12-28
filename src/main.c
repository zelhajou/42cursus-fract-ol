/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:30:50 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/28 23:49:10 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display_message(char *argv[])
{
	printf("Available fractals:\n");
	printf("1: Mandelbrot\n2: Julia (requires two additional parameters)\n");
	printf("Usage: %s [fractal number] [julia parameters if needed]\n\n",
		argv[0]);
}

void	ft_init_fractal(t_fractol *fractol, int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
	{
		ft_display_message(argv);
		exit(0);
	}
	fractol->fractal_choice = atoi(argv[1]);
	if (fractol->fractal_choice < 1 || fractol->fractal_choice > 2)
	{
		fprintf(stderr, "Error: Invalid fractal number. Please choose 1 or 2.\n\n");
		ft_display_message(argv);
		exit(1);
	}
	fractol->offset.x = 0;
	fractol->offset.y = 0;
	if (fractol->fractal_choice == 2 && argc == 4)
	{
		fractol->fractal_config.type = 'J';
		fractol->fractal_config.julia_x = atof(argv[2]);
		fractol->fractal_config.julia_y = atof(argv[3]);
	}
	else if (fractol->fractal_choice == 2 && argc != 4)
	{
		fprintf(stderr, "Error: Invalid number of arguments for Julia fractal.\n");
		ft_display_message(argv);
		exit(1);
	}
	fractol->zoom = 1;
	fractol->max_iterations = 100;
}

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
