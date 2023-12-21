/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:10:26 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/21 01:31:33 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <mlx.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_gfx_env {
	void *mlx_connextion;
	void *mlx_window;
}	t_gfx_env;

void	ft_setup_window(t_gfx_env *env);

#endif