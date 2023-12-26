/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:15:08 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/26 23:58:11 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calculate_mandelbrot(t_fractol *fractol, int max_iterations) {
    //  t_complex temp; // Temporary complex number for initial values
    // temp.real = fractol->c.real;
    // temp.imaginary = fractol->c.imaginary;

    // fractol->z.real = 0;
    // fractol->z.imaginary = 0;

   
    fractol->z.real = 0;
    fractol->z.imaginary = 0;
    return iterate_fractal(fractol->z, fractol->c, max_iterations);
}
// int	calculate_mandelbrot(t_fractol *fractol, int max_iterations)
// {
// 	double	real;
// 	double	imaginary;

// 	fractol->c.real = fractol->z.real;
// 	fractol->c.imaginary = fractol->z.imaginary;
// 	fractol->z.real = 0;
// 	fractol->z.imaginary = 0;
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
