/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:57:09 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/27 17:00:54 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_determine_color(int iterations, int max_iterations)
{
	int		color;
	double	t;

	if (iterations == max_iterations)
		color = 0x000000;
	else
	{
		t = (double)iterations / max_iterations;
		color = (int)(8.5 * (1 - t) * t * t * t * 255) << 16
			| (int)(20 * (1 - t) * (1 - t) * t * t * 255) << 8
			| (int)(12 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	return (color);
}
