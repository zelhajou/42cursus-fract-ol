/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:57:09 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/30 23:02:30 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_determine_color(int iterations, int max_iterations)
{
	int	red;
	int	green;
	int	blue;

	if (iterations == max_iterations)
		return (0x000000);
	else
	{
		red = (iterations * 5) % 255;
		green = (iterations * 3) % 255;
		blue = (iterations * 7) % 255;
		return ((red << 16) | (green << 8) | blue);
	}
}
