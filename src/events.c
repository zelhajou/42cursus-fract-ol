/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:15:52 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/29 18:24:31 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_handle_keypress(int key, t_fractol *fractol)
{
	if (key == KEY_ESC)
		ft_close_window(fractol);
	// else if (key == KEY_LEFT)
	// 	ft_printf("LEFT pressed\n");
	// else if (key == KEY_RIGHT)
	// 	ft_printf("RIGHT pressed\n");
	// else if (key == KEY_UP)
	// 	ft_printf("UP pressed\n");
	// else if (key == KEY_DOWN)
	// 	ft_printf("DOWN pressed\n");
	return (0);
}

int	ft_handle_mouse(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == ZOOM_IN_KEY)
		fractol->zoom *= 1.1;
	else if (button == ZOOM_OUT_KEY)
		fractol->zoom /= 1.1;
	// else if (button == MOUSE_LEFT_CLICK)
	// 	ft_printf("MOUSE_LEFT_CLICK %d pressed at %d:%d\n", button, x, y);
	// else if (button == MOUSE_RIGHT_CLICK)
	// 	ft_printf("MOUSE_RIGHT_CLICK %d pressed at %d:%d\n", button, x, y);
	// else if (button == MOUSE_MIDDLE_CLICK)
	// 	ft_printf("MOUSE_MIDDLE_CLICK %d pressed at %d:%d\n", button, x, y);
	return (0);
}

int	ft_handle_mouse_move(int x, int y, t_fractol *fractol)
{
	fractol->offset.x = x;
	fractol->offset.y = y;
	return (0);
}

void	ft_setup_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_window, ft_handle_keypress, fractol);
	mlx_mouse_hook(fractol->mlx_window, ft_handle_mouse, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, ft_close_window, fractol);
	mlx_hook(fractol->mlx_window, 6, 0, ft_handle_mouse_move, fractol);
	mlx_loop_hook(fractol->mlx_connextion, ft_render_fractal, fractol);
}
