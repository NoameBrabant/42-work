/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:51:32 by nbrabant          #+#    #+#             */
/*   Updated: 2023/10/07 09:41:09 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal fractal, char *prompt)
{
	if (ft_strncmp(prompt, "mandel", 7) == 0)
		ft_draw_mandelbrot(fractal);
	else if (ft_strncmp(prompt, "julia", 6) == 0)
		ft_draw_julia(fractal);
	else if (ft_strncmp(prompt, "burning_ship", 13) == 0)
		ft_draw_burning_ship(fractal);
	else
		ft_error(&fractal);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;
	double		cx;
	double		cy;

	cx = 0.0;
	cy = 0.0;
	fractal = malloc(sizeof(t_fractal));
	fractal->mlx = NULL;
	if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		cx = ft_atof(argv[2], fractal);
		cy = ft_atof(argv[3], fractal);
	}
	else if (argc != 2 || (ft_strncmp(argv[1], "julia", 6) != 0
			&& ft_strncmp(argv[1], "mandel", 7) != 0
			&& ft_strncmp(argv[1], "burning_ship", 13) != 0))
		ft_error(fractal);
	init_fractal(fractal, argv[1], cx, cy);
	init_mlx(fractal);
	mlx_key_hook(fractal->win, ft_keyboard_hook, fractal);
	mlx_mouse_hook(fractal->win, ft_mouse_hook, fractal);
	mlx_hook(fractal->win, 17, 0L, ft_exit_fractal, fractal);
	draw_fractal(*fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
