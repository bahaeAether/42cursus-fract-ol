/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:24:55 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/30 21:37:05 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	double	distance;

	if (keycode == ESC)
		ft_quit(fractal);
	distance = (fractal->max.re - fractal->min.re) / 15;
	if (keycode == LEFT_ARROW)
		add_distance(&fractal->min.re, &fractal->max.re, -distance);
	else if (keycode == RIGHT_ARROW)
		add_distance(&fractal->min.re, &fractal->max.re, distance);
	else if (keycode == DOWN_ARROW)
		add_distance(&fractal->min.im, &fractal->max.im, -distance);
	else if (keycode == UP_ARROW)
		add_distance(&fractal->min.im, &fractal->max.im, distance);
	if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW \
				|| keycode == DOWN_ARROW || keycode == UP_ARROW)
		ft_draw(fractal);
	return (0);
}

void	add_distance(double *min, double *max, double distance)
{
	*min += distance;
	*max += distance;
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
