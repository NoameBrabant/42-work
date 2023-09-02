/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:25:28 by tremy             #+#    #+#             */
/*   Updated: 2023/09/02 17:33:40 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_julia(t_fractal fractal, double cx, double cy)
{
    int  i;
    double tmp; 
    fractal.name = "julia";
    fractal.cx = cx;
    fractal.cy = cy;
    fractal.zx = fractal.x / fractal.zoom + fractal.offsetX;
    fractal.zy = fractal.y / fractal.zoom + fractal.offsetY;
    i = 0;
    while (++i < fractal.maxiteration)
    {
        tmp = fractal.zx;
        fractal.zx = fractal.zx * fractal.zx - fractal.zy * fractal.zy + fractal.cx;
        fractal.zy = 2 * fractal.zy * tmp + fractal.cy;
        if (fractal.zx * fractal.zx + fractal.zy * fractal.zy >= __DBL_MAX__)
        break;
    }
    if (i == fractal.maxiteration)
        put_color_to_pixel(fractal, fractal.x, fractal.y, 0x000000);
    else
        put_color_to_pixel(fractal, fractal.x, fractal.y, (fractal.color * (i% 255)));
}