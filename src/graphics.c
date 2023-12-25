/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:06:53 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/25 22:07:49 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "events.h"
#include "drawing.h"

int ft_close_window(t_gfx_env *env) {
    mlx_destroy_window(env->mlx_connextion, env->mlx_window);
	free(env->mlx_connextion);
    exit(0);
}

void	ft_setup_window(t_gfx_env *env)
{
	env->mlx_connextion = mlx_init();
	if (!env->mlx_connextion)
		exit(1);
	env->mlx_window = mlx_new_window(env->mlx_connextion, WINDOW_HEIGHT, WINDOW_WIDTH, "Fractol");
	if (!env->mlx_window)
	{
		mlx_destroy_window(env->mlx_connextion, env->mlx_window);
		free(env->mlx_connextion);
		exit(1);
	}
	env->mouse.zoom = 1;
	ft_setup_hooks(env);
	ft_render_fractal(env);
	mlx_loop(env->mlx_connextion);
	mlx_destroy_window(env->mlx_connextion, env->mlx_window);
	// mlx_destroy_display(env->mlx_connextion);
	free(env->mlx_connextion);
}
