/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:42:53 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/30 19:43:32 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	ft_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

int	ft_mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;

	i = 1;
	z = ft_complex(0, 0);
	while (i < max_iter)
	{
		z = ft_complex(z.re * z.re - z.im * z.im + c.re,
				2 * z.re * z.im + c.im);
		if (z.re * z.re + z.im * z.im > 16)
			break ;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}

int	ft_julia(t_complex z, t_complex c, int max_iter)
{
	int	i;

	i = 1;
	while (i < max_iter)
	{
		z = ft_complex(z.re * z.re - z.im * z.im + c.re,
				2 * z.re * z.im + c.im);
		if (z.re * z.re + z.im * z.im > 16)
			break ;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}

int	ft_burning_ship(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;

	i = 1;
	z = ft_complex(0, 0);
	while (i < max_iter)
	{
		z = ft_complex(fabs(z.re), fabs(z.im));
		z = ft_complex(z.re * z.re - z.im * z.im + c.re,
				2 * (z.re * z.im) + c.im);
		if (z.re * z.re + z.im * z.im > 16)
			break ;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}

int	ft_fractol(t_fractol *fractal, t_complex z)
{
	if (fractal->type == MANDELBROT)
		return (ft_mandelbrot(z, fractal->max_iter));
	else if (fractal->type == JULIA)
		return (ft_julia(z, fractal->c, fractal->max_iter));
	else
	{
		z = ft_complex(-z.re, -z.im);
		return (ft_burning_ship(z, fractal->max_iter));
	}
}
