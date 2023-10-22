/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:54:29 by tremy             #+#    #+#             */
/*   Updated: 2023/10/06 15:08:37 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractal f, int x, int y, int color)
{
	char	*dst;

	dst = f.pointer_to_image + (y * f.line_length + x * (f.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_exit_fractal(t_fractal *fractal)
{
	if (!fractal->mlx)
		free(fractal);
	else
	{
		mlx_destroy_image(fractal->mlx, fractal->img);
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		free(fractal);
	}
	ft_putendstr("Bye bye", 1, 1);
	exit(1);
	return (0);
}

void	init_fractal(t_fractal *fractal, char *name, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0x114538;
	fractal->zoom = 270;
	fractal->maxiteration = 60;
	fractal->name = name;
	if (ft_strncmp(name, "julia", 6) == 0)
	{
		fractal->offset_x = -1.9;
		fractal->offset_y = -1.35;
	}
	else if (ft_strncmp(name, "mandel", 7) == 0)
	{
		fractal->offset_x = -2.3;
		fractal->offset_y = -1.2;
	}
	else if (ft_strncmp(name, "burning_ship", 13) == 0)
	{
		fractal->offset_x = -1.7;
		fractal->offset_y = -0.01;
		fractal->zoom = 45000;
	}
	ft_set_c(fractal, cx, cy);
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fractol");
	fractal->img = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel,
			&fractal->line_length,
			&fractal->endian);
}
