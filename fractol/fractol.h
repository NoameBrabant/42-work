/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:52:15 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/02 17:49:02 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"
#include "libft/libft.h"
#include <limits.h>
#include <unistd.h>

typedef struct fractal
{
	char	*name;
	double	x;
	double	y;
	double	zoom;
	double 	zx;
	double 	zy;
	double	cx;
	double	cy;
	double	offsetX;
	double	offsetY;
	int		maxiteration;
	int		color;
	int		sizeX;
	int		sizeY;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*win;
	void	*mlx;
}			t_fractal;

void	ft_mandelbrot(t_fractal fractal);
void ft_julia(t_fractal fractal, double cx, double cy);

#endif