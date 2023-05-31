/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:22:40 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/30 22:24:51 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	coord_to_complex(t_complex *c, int x, int y, t_fractol *fractal)
{
	c->re = fractal->min.re + \
	x * (fractal->max.re - fractal->min.re) / WIDTH;
	c->im = fractal->max.im - \
	y * (fractal->max.im - fractal->min.im) / HEIGHT;
}

int	ft_quit(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx.mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx.mlx, fractal->mlx.win);
	exit(0);
	return (0);
}

int	ft_key_hook(int keycode, t_fractol *fractal)
{
	if (keycode == ESC)
		ft_quit(fractal);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_fractol *fractal)
{
	t_complex	pixel;
	double		ratio;

	if (button == WHEEL_UP)
	{
		ratio = 0.909;
		coord_to_complex(&pixel, x, y, fractal);
		fractal->min.re = pixel.re + (fractal->min.re - pixel.re) * ratio;
		fractal->min.im = pixel.im + (fractal->min.im - pixel.im) * ratio;
		fractal->max.re = pixel.re + (fractal->max.re - pixel.re) * ratio;
		fractal->max.im = pixel.im + (fractal->max.im - pixel.im) * ratio;
	}
	else if (button == WHEEL_DOWN)
	{
		ratio = 1.111;
		coord_to_complex(&pixel, x, y, fractal);
		fractal->min.re = pixel.re + (fractal->min.re - pixel.re) * ratio;
		fractal->min.im = pixel.im + (fractal->min.im - pixel.im) * ratio;
		fractal->max.re = pixel.re + (fractal->max.re - pixel.re) * ratio;
		fractal->max.im = pixel.im + (fractal->max.im - pixel.im) * ratio;
	}
	if (button == WHEEL_UP || button == WHEEL_DOWN)
		ft_draw(fractal);
	return (0);
}
