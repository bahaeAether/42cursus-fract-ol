/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:28:21 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/30 22:58:05 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_transfer(t_fractol *fractal, int i, int j)
{
	t_complex	pixel;
	int			iter;

	pixel.re = fractal->min.re + \
			i * (fractal->max.re - fractal->min.re) / WIDTH;
	pixel.im = fractal->max.im - \
			j * (fractal->max.im - fractal->min.im) / HEIGHT;
	iter = ft_fractol(fractal, pixel);
	my_mlx_pixel_put(&fractal->img, i, j, \
			color_shader(COLOR, sqrt(iter / \
			(double)(fractal->max_iter - 1))) + iter * 256 * 2);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*pix;

	pix = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pix = color;
}

int	color_shader(int color, double ratio)
{
	int	t;

	if (ratio > 1 || ratio < 0)
		ratio = 1;
	t = 255 * ratio;
	color = color & 0x00ffffff;
	color = color | ((255 - t) << 24);
	return (color);
}

void	ft_draw(t_fractol *fractal)
{
	int			i;
	int			j;

	mlx_clear_window(fractal->mlx.mlx, fractal->mlx.win);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
			pixel_transfer(fractal, i, j++);
		i++;
	}
	mlx_put_image_to_window(fractal->mlx.mlx, \
			fractal->mlx.win, \
			fractal->img.img, 0, 0);
}
