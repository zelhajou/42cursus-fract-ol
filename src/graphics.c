/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:06:53 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/21 01:49:03 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	ft_setup_window(t_gfx_env *env)
{
	env->mlx_connextion = mlx_init();
	if (!env->mlx_connextion)
		exit(1);
	env->mlx_window = mlx_new_window(env->mlx_connextion, HEIGHT, WIDTH, "Fractol");
	if (!env->mlx_window)
	{
		mlx_destroy_window(env->mlx_connextion, env->mlx_window);
		free(env->mlx_connextion);
		exit(1);
	}
	mlx_loop(env->mlx_connextion);

	mlx_destroy_window(env->mlx_connextion, env->mlx_window);
	// mlx_destroy_display(env->mlx_connextion);
	free(env->mlx_connextion);
}