/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:10:26 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/23 17:16:47 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct s_gfx_env {
	void *mlx_connextion;
	void *mlx_window;
}	t_gfx_env;


void	ft_setup_window(t_gfx_env *env);
int		ft_render(t_gfx_env *env);
int		ft_change_color(t_gfx_env *env);
int		ft_close_window(t_gfx_env *env);

#endif