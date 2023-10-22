/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:36:32 by nbrabant          #+#    #+#             */
/*   Updated: 2023/10/13 14:24:59 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calculate_burning_ship(t_fractal fractal)
{
	int		i;
	double	x_temp;
	int		color;

	fractal.name = "burning_ship";
	fractal.zx = 0.0;
	fractal.zy = 0.0;
	fractal.cx = (fractal.x / fractal.zoom) + fractal.offset_x;
	fractal.cy = (fractal.y / fractal.zoom) + fractal.offset_y;
	i = 0;
	while (++i < fractal.maxiteration)
	{
		x_temp = fractal.zx * fractal.zx - fractal.zy * fractal.zy + fractal.cx;
		fractal.zy = fabs(2.0 * fractal.zx * fractal.zy) + fractal.cy;
		fractal.zx = fabs(x_temp);
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

void	ft_draw_burning_ship(t_fractal fractal)
{
	fractal.x = 0;
	fractal.y = 0;
	while (fractal.x < SIZE)
	{
		while (fractal.y < SIZE)
		{
			ft_calculate_burning_ship(fractal);
			fractal.y++;
		}
		fractal.x++;
		fractal.y = 0;
	}
}
