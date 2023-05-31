/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:44:08 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/30 22:12:02 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_borders(t_fractol *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		fractal->min = ft_complex(-2.5, -2.0);
		fractal->max = ft_complex(1.5, 2.0);
	}
	else if (fractal->type == JULIA)
	{
		fractal->min = ft_complex(-2.0, -2.0);
		fractal->max = ft_complex(2.0, 2.0);
	}
	else
	{
		fractal->min = ft_complex(-1.5, -2.0);
		fractal->max = ft_complex(2.5, 2.0);
	}
}

void	init_julia(t_fractol *fractal, t_complex c)
{
	fractal->c = c;
	fractal->type = JULIA;
	fractal->max_iter = 150;
	init_borders(fractal);
}

void	init_mandelbrot(t_fractol *fractal)
{
	fractal->type = MANDELBROT;
	fractal->max_iter = 100;
	init_borders(fractal);
}

void	init_burning_ship(t_fractol *fractal)
{
	fractal->type = BURNING_SHIP;
	fractal->max_iter = 100;
	init_borders(fractal);
}
