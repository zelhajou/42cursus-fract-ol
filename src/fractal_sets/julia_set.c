/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:22:07 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/26 23:18:55 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calculate_julia(t_fractol *fractol, int max_iterations) {
    return iterate_fractal(fractol->z, fractol->c, max_iterations);
}
// int	calculate_julia(t_fractol *fractol, int max_iterations)
// {
// 	double	real;
// 	double	imaginary;

// 	while (max_iterations)
// 	{
// 		real = fractol->z.real * fractol->z.real - fractol->z.imaginary
// 			* fractol->z.imaginary + fractol->c.real;
// 		imaginary = 2 * fractol->z.real * fractol->z.imaginary
// 			+ fractol->c.imaginary;
// 		fractol->z.real = real;
// 		fractol->z.imaginary = imaginary;
// 		if (fractol->z.real * fractol->z.real + fractol->z.imaginary
// 			* fractol->z.imaginary > 4)
// 			return (max_iterations);
// 		max_iterations--;
// 	}
// 	return (max_iterations);
// }
