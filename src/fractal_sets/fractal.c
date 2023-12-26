/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:59:07 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/26 23:12:56 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iterate_fractal(t_complex z, t_complex c, int max_iterations) {
    int iterations = 0;
    double real, imaginary;

    while (iterations < max_iterations) {
        real = z.real * z.real - z.imaginary * z.imaginary + c.real;
        imaginary = 2 * z.real * z.imaginary + c.imaginary;
        z.real = real;
        z.imaginary = imaginary;

        if (z.real * z.real + z.imaginary * z.imaginary > 4) {
            break;
        }
        iterations++;
    }
    return iterations;
}