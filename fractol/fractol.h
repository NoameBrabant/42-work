/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:52:15 by nbrabant          #+#    #+#             */
/*   Updated: 2023/10/06 15:13:46 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <limits.h>

# define ESC 65307
# define R 114
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define LCLICK 1
# define CCLICK 2
# define RCLICK 3
# define ZOOM 4
# define ZOOMOUT 5
# define ENTER 65293
# define MINUS 109
# define PLUS 112

# define SIZE 1000

typedef struct fractal
{
	char	*name;
	double	x;
	double	y;
	double	zoom;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	int		maxiteration;
	int		color;
	int		size_y;
	int		size_x;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	void	*win;
	void	*mlx;
	void	*pointer_to_image;
}			t_fractal;

void	ft_calculate_julia(t_fractal fractal);
void	ft_calculate_mandelbrot(t_fractal fractal);
void	ft_draw_julia(t_fractal fractal);
void	ft_draw_mandelbrot(t_fractal fractal);
void	ft_putendstr(char *str, int fd, int toggle);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_exit_fractal(t_fractal *fractal);
void	my_mlx_pixel_put(t_fractal f, int x, int y, int color);
void	init_mlx(t_fractal *fractal);
void	init_fractal(t_fractal *fractal, char *name, double cx, double cy);
int		ft_mouse_hook(int mouse_hook, int x, int y, t_fractal *fractal);
int		ft_keyboard_hook(int key_code, t_fractal *fractal);
void	ft_putnbr(int n, int fd);
int		draw_fractal(t_fractal fractal, char *prompt);
void	ft_zoom(t_fractal *fractal, int x, int y, int key_hook);
void	ft_putchar(char c, int fd);
void	ft_change_cvalue(int command, t_fractal *fractal, char *name);
void	ft_error(t_fractal *fractal);
double	ft_atof(char *str, t_fractal *fractal);
double	ft_after_dot_atof(char *str, t_fractal *fractal);
void	ft_set_c(t_fractal *fractal, double cx, double cy);
void	ft_putcommand(int command);
void	ft_putcommand_2(int command);
void	ft_calculate_burning_ship(t_fractal fractal);
void	ft_draw_burning_ship(t_fractal fractal);

#endif
