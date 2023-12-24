/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:57:43 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/23 20:18:11 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "drawing.h"
#include <math.h>

int	ft_change_color(t_gfx_env *env)
{
	int color = rand() % 0xFFFFFF;

    mlx_string_put(env->mlx_connextion, env->mlx_window, 50, 50, color, "Dynamic Text");
	//mlx_put_image_to_window(env->mlx_connextion, env->mlx_window, env->img_ptr, 0, 0);
	printf("continuous function\n");
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



void ft_put_pixel(t_data *data, int x, int y, int color)
{
    char *pxl;

    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

void ft_draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
   int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1; 
    int err = dx + dy, e2; /* error value e_xy */

    while (1) {
        ft_put_pixel(data, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
        if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
    }
}


void draw_circle(t_data *data, int color) {
    t_point center = {rand() % WINDOW_WIDTH,rand() % WINDOW_HEIGHT,};
	int radius = 50;


    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        my_mlx_pixel_put(data, center.x + x, center.y + y, color);
        my_mlx_pixel_put(data, center.x + y, center.y + x, color);
        my_mlx_pixel_put(data, center.x - y, center.y + x, color);
        my_mlx_pixel_put(data, center.x - x, center.y + y, color);
        my_mlx_pixel_put(data, center.x - x, center.y - y, color);
        my_mlx_pixel_put(data, center.x - y, center.y - x, color);
        my_mlx_pixel_put(data, center.x + y, center.y - x, color);
        my_mlx_pixel_put(data, center.x + x, center.y - y, color);

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}


int	ft_render_fractal(t_gfx_env *env)
{
	t_data	img;
	//  int x, y;
	int color = rand() % 0xFFFFFF;;

	img.img = mlx_new_image(env, WINDOW_HEIGHT, WINDOW_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// for (y = 0; y < WINDOW_WIDTH; y++) {
    //     for (x = 0; x < WINDOW_HEIGHT; x++) {
	// 		my_mlx_pixel_put(&img, x, y, color);
    //     }
    // }

	ft_put_pixel(&img, WINDOW_HEIGHT/2, WINDOW_WIDTH/2, color);
	ft_draw_line(&img, rand() % WINDOW_HEIGHT, rand() % WINDOW_WIDTH, rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT, color);
	draw_circle(&img, color);
	ft_change_color(env);
	// mlx_string_put(env->mlx_connextion, env->mlx_window, 100, 100, color, "Dynamic Text");
	// mlx_put_image_to_window(env->mlx_connextion, env->mlx_window, img.img, 100, 100);


	mlx_put_image_to_window(env, env->mlx_window, img.img, 0, 0);

	return (0);
}