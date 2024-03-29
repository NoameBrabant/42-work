/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:25:28 by tremy             #+#    #+#             */
/*   Updated: 2023/10/06 15:31:54 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calculate_julia(t_fractal fractal)
{
	int		i;
	int		color;
	double	tmp;

	fractal.name = "julia";
	fractal.zx = fractal.x / fractal.zoom + fractal.offset_x;
	fractal.zy = fractal.y / fractal.zoom + fractal.offset_y;
	i = 0;
	while (++i < fractal.maxiteration)
	{
		tmp = fractal.zx;
		fractal.zx = fractal.zx * fractal.zx
			- fractal.zy * fractal.zy + fractal.cx;
		fractal.zy = 2 * fractal.zy * tmp + fractal.cy;
		if (fractal.zx * fractal.zx + fractal.zy * fractal.zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal.maxiteration)
		my_mlx_pixel_put(fractal, fractal.x, fractal.y, 0x000000);
	else
	{
		color = fractal.color * (i % 255);
		my_mlx_pixel_put(fractal, fractal.x, fractal.y, color);
	}
}

void	ft_draw_julia(t_fractal fractal)
{
	fractal.x = 0;
	fractal.y = 0;
	while (fractal.x < SIZE)
	{
		while (fractal.y < SIZE)
		{
			ft_calculate_julia(fractal);
			fractal.y++;
		}
		fractal.x++;
		fractal.y = 0;
	}
}
