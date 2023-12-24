/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:15:52 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/23 15:02:53 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

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
	(void)env;
	if (button == ZOOM_IN_KEY)
		printf("ZOOM_IN_KEY %d pressed at %d:%d\n", button, x, y);
	else if (button == ZOOM_OUT_KEY)
	    printf("ZOOM_OUT_KEY %d pressed at %d:%d\n", button, x, y);
	else if (button == MOUSE_LEFT_CLICK)
	    printf("MOUSE_LEFT_CLICK %d pressed at %d:%d\n", button, x, y);
	else if (button == MOUSE_RIGHT_CLICK)
	    printf("MOUSE_RIGHT_CLICK %d pressed at %d:%d\n", button, x, y);
	else if (button == MOUSE_MIDDLE_CLICK)
	    printf("MOUSE_MIDDLE_CLICK %d pressed at %d:%d\n", button, x, y);
	return (0);
}

int ft_handle_mouse_move(int x, int y)
{
	printf("Mouse moved to %d:%d\n", x, y);
	return (0);
}

void ft_setup_hooks(t_gfx_env *env)
{
	mlx_key_hook(env->mlx_window, ft_handle_keypress, env);
	mlx_mouse_hook(env->mlx_window, ft_handle_mouse, env);
	mlx_hook(env->mlx_window, 17, 0, ft_close_window, env);
	mlx_hook(env->mlx_window, 6, 0, ft_handle_mouse_move, env); // 6 is the event number for mouse movement in MiniLibX

	//mlx_loop_hook(env->mlx_connextion, ft_render, env);
}