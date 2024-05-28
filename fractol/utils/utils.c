/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:40:17 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/30 02:30:10 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_validate_atof_input(const char *str)
{
	bool	has_decimal_point;

	if (str == NULL || *str == '\0')
		return (false);
	has_decimal_point = false;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_is_digit(*str))
		return (false);
	while (*str != '\0')
	{
		if (*str == '.')
		{
			if (has_decimal_point)
				return (false);
			has_decimal_point = true;
		}
		else if (!ft_is_digit(*str))
			return (false);
		str++;
	}
	return (true);
}
