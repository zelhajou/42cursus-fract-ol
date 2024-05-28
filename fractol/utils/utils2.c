/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 03:04:44 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/30 22:34:27 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display_message(void)
{
	ft_putstr_fd("Available fractals:\n", 1);
	ft_putstr_fd("1: Mandelbrot\n", 1);
	ft_putstr_fd("2: Julia (requires two additional parameters)\n", 1);
	ft_putstr_fd("Usage: ./fractol [fractal number] [julia parameters]\n", 1);
	exit(0);
}

void	ft_validate_arguments(int argc, char *argv[], t_fractol *fractol)
{
	if (argc < 2 || argc > 4)
		ft_display_message();
	fractol->fractal_choice = ft_atoi(argv[1]);
	if (fractol->fractal_choice < 1 || fractol->fractal_choice > 2)
	{
		ft_putstr_fd("Error: Invalid fractal number. Choose 1 or 2.\n", 2);
		ft_display_message();
	}
	if (fractol->fractal_choice == 1 && argc != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments for Mandelbrot.\n", 2);
		ft_putstr_fd("Usage: ./fractol mandelbrot\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_handle_julia_parameters(int argc, char *argv[], t_fractol *fractol)
{
	if (argc == 4)
	{
		fractol->fractal_config.type = 'J';
		if (ft_validate_atof_input(argv[2]) && ft_validate_atof_input(argv[3]))
		{
			fractol->fractal_config.julia_x = ft_atof(argv[2]);
			fractol->fractal_config.julia_y = ft_atof(argv[3]);
		}
		else
		{
			ft_putstr_fd("Error: Invalid parameters for Julia.\n", 2);
			exit(0);
		}
	}
	else
	{
		ft_putstr_fd("Error: Invalid number of arguments for Julia.\n", 2);
		ft_putstr_fd("Usage: ./fractol julia [julia parameters]\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_initialize_fractal(t_fractol *fractol)
{
	fractol->zoom = 1;
	fractol->max_iterations = 100;
}

void	ft_init_fractal(t_fractol *fractol, int argc, char *argv[])
{
	ft_validate_arguments(argc, argv, fractol);
	ft_initialize_fractal(fractol);
	if (fractol->fractal_choice == 2)
		ft_handle_julia_parameters(argc, argv, fractol);
}
