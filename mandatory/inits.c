/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:27:35 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/30 22:38:23 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_borders(t_fractol *fractal)
{
	if (fractal->type == JULIA)
	{
		fractal->min = ft_complex(-2.0, -2.0);
		fractal->max = ft_complex(2.0, 2.0);
	}
	else if (fractal->type == MANDELBROT)
	{
		fractal->min = ft_complex(-2.5, -2.0);
		fractal->max = ft_complex(1.5, 2.0);
	}
}

void	init_julia(t_fractol *fractal, t_complex c)
{
	fractal->c = c;
	fractal->type = JULIA;
	fractal->max_iter = 200;
	init_borders(fractal);
}

void	init_mandelbrot(t_fractol *fractal)
{
	fractal->type = MANDELBROT;
	fractal->max_iter = 100;
	init_borders(fractal);
}
