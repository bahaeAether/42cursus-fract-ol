/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:36:22 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/30 23:02:24 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	pixel_transfer(t_fractol *fractal, int i, int j, int color)
{
	t_complex	pixel;
	int			iter;

	pixel.re = fractal->min.re + \
			i * (fractal->max.re - fractal->min.re) / WIDTH;
	pixel.im = fractal->max.im - \
			j * (fractal->max.im - fractal->min.im) / HEIGHT;
	iter = ft_fractol(fractal, pixel);
	my_mlx_pixel_put(&fractal->img, i, j, \
			color_shader(color, sqrt(iter / \
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

int	color_shift(void)
{
	static int				color = COLOR;
	static unsigned char	c = 13;
	int						shift;

	if (c % 3 == 1)
		shift = c;
	else if (c % 3 == 0)
		shift = c << 8;
	else
		shift = c << 16;
	color += shift;
	c += 13;
	return (color);
}

void	ft_draw(t_fractol *fractal)
{
	int			i;
	int			j;
	int			color;

	mlx_clear_window(fractal->mlx.mlx, fractal->mlx.win);
	i = -1;
	color = color_shift();
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			pixel_transfer(fractal, i, j, color);
	}
	mlx_put_image_to_window(fractal->mlx.mlx, \
			fractal->mlx.win, fractal->img.img, 0, 0);
}
