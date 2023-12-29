/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:57:09 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/29 16:02:01 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_determine_color(int iterations, int max_iterations)
{
    if (iterations == max_iterations) {
        return 0x000000;
    } else {
        int red = (iterations * 5) % 255;
        int green = (iterations * 3) % 255;
        int blue = (iterations * 7) % 255;
        return (red << 16) | (green << 8) | blue;
    }
}
