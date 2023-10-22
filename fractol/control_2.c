/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:25:08 by tremy             #+#    #+#             */
/*   Updated: 2023/10/06 15:18:33 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_hook(int mouse_hook, int x, int y, t_fractal *fractal)
{
	if (mouse_hook == ZOOM || mouse_hook == ZOOMOUT)
		ft_zoom(fractal, x, y, mouse_hook);
	else if (mouse_hook == LCLICK || mouse_hook == RCLICK)
		ft_change_cvalue(mouse_hook, fractal, fractal->name);
	ft_putcommand(mouse_hook);
	draw_fractal(*fractal, fractal->name);
	return (0);
}

void	ft_putcommand(int command)
{
	if (command == ESC)
		return ;
	else if (command == UP)
		ft_putendstr("Up", 1, 1);
	else if (command == DOWN)
		ft_putendstr("Down", 1, 1);
	else if (command == LEFT)
		ft_putendstr("Left", 1, 1);
	else if (command == RIGHT)
		ft_putendstr("Right", 1, 1);
	else if (command == ZOOM)
		ft_putendstr("Zoom", 1, 1);
	else if (command == ZOOMOUT)
		ft_putendstr("Zoom out", 1, 1);
	else if (command == R)
		ft_putendstr("Start position", 1, 1);
	else
	{
		ft_putcommand_2(command);
	}
}

void	ft_putcommand_2(int command)
{
	if (command == LCLICK)
		ft_putendstr("Raising c", 1, 1);
	else if (command == RCLICK)
		ft_putendstr("Lowing c", 1, 1);
	else if (command == PLUS || command == MINUS)
		ft_putendstr("Color changing", 1, 1);
	else
	{
		ft_putnbr(command, 1);
		ft_putchar('\n', 1);
	}
}

void	ft_change_cvalue(int command, t_fractal *fractal, char *name)
{
	if (command == LCLICK && ft_strncmp(name, "julia", 6) == 0)
	{
		fractal->cx += 0.0375;
		fractal->cy += 0.0375;
	}
	else if (command == RCLICK && ft_strncmp(name, "julia", 6) == 0)
	{
		fractal->cx -= 0.0375;
		fractal->cy -= 0.0375;
	}
	else
		ft_putendstr("Only works with Julia -> ", 1, 0);
}
