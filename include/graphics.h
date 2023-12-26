/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:10:26 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/25 22:14:47 by zelhajou         ###   ########.fr       */
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
#define WINDOW_HEIGHT 800

typedef struct s_point {
    int x; // X coordinate
    int y; // Y coordinate
	double zoom;
}	t_point;

typedef struct s_gfx_env {
	void *mlx_connextion;
	void *mlx_window;
	t_point mouse;
} t_gfx_env;

void	ft_setup_window(t_gfx_env *env);
int		ft_render(t_gfx_env *env);
int		ft_close_window(t_gfx_env *env);

#endif