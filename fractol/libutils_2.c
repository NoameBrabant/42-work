/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:39:00 by tremy             #+#    #+#             */
/*   Updated: 2023/10/06 15:41:59 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *str, t_fractal *fractal)
{
	double	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(fractal);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	return (sign * (result + ft_after_dot_atof(&str[i], fractal)));
}

double	ft_after_dot_atof(char *str, t_fractal *fractal)
{
	double	result;
	int		i;

	result = 0.1;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(fractal);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	while (i != 0)
	{
		result = result / 10;
		i--;
	}
	return (result);
}
