/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:58:08 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/23 18:14:05 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
#define DRAWING_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point {
    int x; // X coordinate
    int y; // Y coordinate
} t_point;

typedef struct s_color {
    int red;
    int green;
    int blue;
} t_color;

int ft_render_fractal(t_gfx_env *env);
void ft_put_pixel(t_data *data, int x, int y, int color);

#endif
