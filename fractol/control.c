/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:14:41 by tremy             #+#    #+#             */
/*   Updated: 2023/10/06 15:16:09 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keyboard_hook(int key_hook, t_fractal *fractal)
{
	if (key_hook == ESC)
		ft_exit_fractal(fractal);
	else if (key_hook == R)
		init_fractal(fractal, fractal->name, fractal->cx, fractal->cy);
	else if (key_hook == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_hook == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_hook == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_hook == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_hook == PLUS)
		fractal->color += 10;
	else if (key_hook == MINUS)
		fractal->color -= 10;
	draw_fractal(*fractal, fractal->name);
	ft_putcommand(key_hook);
	return (0);
}

void	ft_zoom(t_fractal *fractal, int x, int y, int key_hook)
{
	if (key_hook == ZOOM)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x)
			- (x / (fractal->zoom * 1.2));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y)
			- (y / (fractal->zoom * 1.2));
		fractal->zoom *= 1.2;
	}
	else if (key_hook == ZOOMOUT)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x)
			- (x / (fractal->zoom / 1.2));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y)
			- (y / (fractal->zoom / 1.2));
		fractal->zoom /= 1.2;
	}
	else
		return ;
}
