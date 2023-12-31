/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:31:13 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/31 15:55:31 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

int	skip_space(int *i, const char *str)
{
	int	sign;

	sign = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	res;
	long long	prev;
	long long	tmp;

	i = 0;
	res = 0;
	sign = skip_space(&i, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = res;
		res = res * 10 + str[i] - '0';
		tmp = res / 10;
		if (tmp != prev)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return (sign * res);
}

double	ft_process_fractional_part(const char *str)
{
	double	fractional_part;
	int		divisor_for_fraction;

	fractional_part = 0.0;
	divisor_for_fraction = 1;
	while (*str != '\0')
	{
		fractional_part = fractional_part * 10 + (*str - '0');
		divisor_for_fraction *= 10;
		str++;
	}
	return (fractional_part / divisor_for_fraction);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	integer_part;
	double	fractional_part;

	sign = 1;
	fractional_part = 0.0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	integer_part = (double)ft_atoi(str);
	while (*str != '\0' && *str != '.')
		str++;
	if (*str == '.')
	{
		str++;
		fractional_part = ft_process_fractional_part(str);
	}
	return (sign * (integer_part + fractional_part));
}
