/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:22:33 by tremy             #+#    #+#             */
/*   Updated: 2023/10/06 15:12:35 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_c(t_fractal *fractal, double cx, double cy)
{
	if (ft_strncmp(fractal->name, "julia", 6) == 0)
	{
		if (cx == 0.0 && cy == 0.0)
		{
			fractal->cx = 0.0822;
			fractal->cy = 0.67;
		}
		else
		{
			fractal->cx = cx;
			fractal->cy = cy;
		}
	}
	else if (ft_strncmp(fractal->name, "mandel", 7) == 0)
	{
		fractal->cx = 0.0;
		fractal->cy = 0.0;
	}
	else if (ft_strncmp(fractal->name, "new", 4) == 0)
	{
		fractal->cx = 0.745429;
		fractal->cy = 0.05;
	}
}

void	ft_error(t_fractal *fractal)
{
	ft_putendstr("    Available fractals: mandel, julia and burning", 2, 0);
	ft_putendstr("_ship", 1, 1);
	ft_putendstr("  If you want to use Mandel or Burning Ship, don't", 2, 0);
	ft_putendstr(" put cx cy as second and third parameters.", 2, 1);
	ft_putendstr("If you want to use Julia you can put", 2, 0);
	ft_putendstr(" cx cy as second and third parameters.", 2, 1);
	ft_putendstr("-----> But it is ok if you do not want to, do not", 2, 0);
	ft_putendstr(" add any. It's cool. Chill.", 2, 1);
	ft_exit_fractal(fractal);
}
