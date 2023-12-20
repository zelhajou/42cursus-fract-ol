/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:30:50 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/20 00:37:55 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MALLOC_ERROR 1
#define WIDTH 400
#define HEIGHT 400


int	main(void)
{
	void	*mlx_connextion;
	void	*mlx_window;

	// initailize the mlx connextion
	mlx_connextion = mlx_init();
	// check if the connextion is created
	if (!mlx_connextion)
		return (MALLOC_ERROR);

	// create a window
	mlx_window = mlx_new_window(mlx_connextion, HEIGHT, WIDTH, "My window");
	// check if the window is created
	if (!mlx_window)
	{	
		mlx_destroy_window(mlx_connextion, mlx_window);
		return (MALLOC_ERROR);
	}
	
	// loop to keep the window open
	mlx_loop(mlx_connextion);
	
	return (0);
	}
