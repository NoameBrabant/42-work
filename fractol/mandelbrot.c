/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:27:36 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/02 16:33:55 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_fractal fractal)
{
	int	i;
	double Xtemp;

	fractal.name = "mandelbrot";
	i = 0;
	fractal.zx = 0.0;
	fractal.zy = 0.0;
	fractal.cx = (fractal.x / fractal.zoom) + fractal.offsetX;
	fractal.cy = (fractal.y / fractal.zoom) + fractal.offsetY;
	while (i++ < fractal.maxiteration)
	{
		Xtemp = fractal.zx * fractal.zx - fractal.zy * fractal.zy + fractal.cx;
		fractal.zy = 2 * fractal.zx * fractal.zy + fractal.cy;
		fractal.zx = Xtemp;
		if (fractal.zx * fractal.zx + fractal.zy * fractal.zy >= __DBL_MAX__)
			break;
		if (i == fractal.maxiteration)
			my_mlx_pixel_put(fractal, fractal.x, fractal.y, 0x00000000);
		else
			my_mlx_pixel_put(fractal, fractal.x, fractal.y, fractal.color * i);
	}
}