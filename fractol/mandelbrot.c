/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:27:36 by nbrabant          #+#    #+#             */
/*   Updated: 2023/10/06 15:33:07 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calculate_mandelbrot(t_fractal fractal)
{
	int		i;
	double	x_temp;

	fractal.name = "mandel";
	i = 0;
	fractal.zx = 0.0;
	fractal.zy = 0.0;
	fractal.cx = (fractal.x / fractal.zoom) + fractal.offset_x;
	fractal.cy = (fractal.y / fractal.zoom) + fractal.offset_y;
	while (i++ < fractal.maxiteration)
	{
		x_temp = fractal.zx * fractal.zx - fractal.zy * fractal.zy + fractal.cx;
		fractal.zy = 2 * fractal.zx * fractal.zy + fractal.cy;
		fractal.zx = x_temp;
		if (fractal.zx * fractal.zx + fractal.zy * fractal.zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal.maxiteration)
		my_mlx_pixel_put(fractal, fractal.x, fractal.y, 0x00000000);
	else
		my_mlx_pixel_put(fractal, fractal.x, fractal.y, (fractal.color * i));
}

void	ft_draw_mandelbrot(t_fractal fractal)
{
	fractal.x = 0;
	fractal.y = 0;
	fractal.name = "mandel";
	while (fractal.x < SIZE)
	{
		while (fractal.y < SIZE)
		{
			ft_calculate_mandelbrot(fractal);
			fractal.y++;
		}
		fractal.x++;
		fractal.y = 0;
	}
}
