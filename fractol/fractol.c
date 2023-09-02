/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:51:32 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/02 17:12:03 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int draw_fractal(t_fractal fractal, char *prompt, double cx, double cy)
{
	fractal.x = 0;
	fractal.y = 0;
	while (fractal.x < fractal.sizeY)
	{
		while (fractal.y < fractal.sizeY)
		{
			if (ft_strncmp(prompt, "mandel", 7) == 0)
				calculate_mandelbrot(fractal);
			else if (ft_strncmp(prompt, "julia", 6) == 0)
				calculate_julia(fractal, cx, cy);
			else
		 	{
				ft_putendl_fd("Available fractals: mandel, julia", 1);
				exit_fractal(fractal);
		 	}
			fractal.y++;
		}
		fractal.x++;
		fractal.y = 0;
	}
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	if (argc != 2)
		ft_exit_fractal();
	
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, 500, 500, "Hello World!");	
	fractal.img = mlx_new_image(fractal.mlx, fractal.sizeX, fractal.sizeY);
	fractal.addr = mlx_get_data_addr(fractal.img, &fractal.bits_per_pixel, &fractal.line_length, &fractal.endian);
	mlx_loop(fractal.mlx);
}