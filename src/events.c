/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:15:52 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/25 22:09:29 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "graphics.h"
#include "drawing.h"

int ft_handle_keypress(int key, t_gfx_env *env)
{
	if (key == KEY_ESC)
		ft_close_window(env);
	else if (key == KEY_LEFT)
		printf("LEFT pressed\n");
	else if (key == KEY_RIGHT)
		printf("RIGHT pressed\n");
	else if (key == KEY_UP)
		printf("UP pressed\n");
	else if (key == KEY_DOWN)
		printf("DOWN pressed\n");
	return (0);
}

int	ft_handle_mouse(int button, int x, int y, t_gfx_env *env)
{
	if (button == ZOOM_IN_KEY)
		env->mouse.zoom *= 1.1;
	else if (button == ZOOM_OUT_KEY)
		env->mouse.zoom /= 1.1;
	else if (button == MOUSE_LEFT_CLICK)
		printf("MOUSE_LEFT_CLICK %d pressed at %d:%d\n", button, x, y);
	else if (button == MOUSE_RIGHT_CLICK)
	    printf("MOUSE_RIGHT_CLICK %d pressed at %d:%d\n", button, x, y);
	else if (button == MOUSE_MIDDLE_CLICK)
	    printf("MOUSE_MIDDLE_CLICK %d pressed at %d:%d\n", button, x, y);
	return (0);
}

int ft_handle_mouse_move(int x, int y, t_gfx_env *env)
{
	env->mouse.x = x;
	env->mouse.y = y;	
	printf("Mouse moved to %d:%d\n", x, y);
	return (0);
}

void ft_setup_hooks(t_gfx_env *env)
{
	mlx_key_hook(env->mlx_window, ft_handle_keypress, env);
	mlx_mouse_hook(env->mlx_window, ft_handle_mouse, env);
	mlx_hook(env->mlx_window, 17, 0, ft_close_window, env);
	mlx_hook(env->mlx_window, 6, 0, ft_handle_mouse_move, env);
	mlx_loop_hook(env->mlx_connextion, ft_render_fractal, env);
}