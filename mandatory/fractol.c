/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:35:22 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/30 23:06:21 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_man(void)
{
	ft_putstr("Usage: ./fractol [-fractal]\n");
	ft_putstr("Available fractals: mandelbrot, julia\n");
	exit(1);
}

void	parse_args_julia(int ac, char **av, t_fractol *fractal)
{
	if (ac != 4 && ac != 2)
	{
		ft_putstr("Usage: ./fractol -julia [real] [imaginary]\n");
		exit(1);
	}
	if (ac == 4 && (!ft_is_double(av[2]) || !ft_is_double(av[3])))
	{
		ft_putstr("Usage: ./fractol -julia [real] [imaginary]\n");
		exit(1);
	}
	if (ac == 2)
		fractal->c = ft_complex(-1.476, 0.0);
	else
	{
		fractal->c.re = ft_atof(av[2]);
		fractal->c.im = ft_atof(av[3]);
	}
	init_julia(fractal, fractal->c);
}

void	parse_args(int ac, char **av, t_fractol *fractal)
{
	if (ac < 2)
		ft_man();
	if (ac != 2 && ft_strcmp(av[1], "-julia") != 0)
		ft_man();
	if (ft_strcmp(av[1], "-mandelbrot") == 0)
		init_mandelbrot(fractal);
	else if (ft_strcmp(av[1], "-julia") == 0)
		parse_args_julia(ac, av, fractal);
	else
		ft_man();
}

int	main(int ac, char **av)
{
	t_fractol	fractal;

	parse_args(ac, av, &fractal);
	fractal.mlx.mlx = mlx_init();
	fractal.mlx.win = mlx_new_window(fractal.mlx.mlx, WIDTH, HEIGHT, "fractol");
	fractal.img.img = mlx_new_image(fractal.mlx.mlx, WIDTH, HEIGHT);
	fractal.img.addr = mlx_get_data_addr(fractal.img.img, \
				&fractal.img.bits_per_pixel, \
				&fractal.img.line_length, &fractal.img.endian);
	ft_draw(&fractal);
	mlx_hook(fractal.mlx.win, DESTROY_NOTIFY, 0, ft_quit, &fractal);
	mlx_key_hook(fractal.mlx.win, ft_key_hook, &fractal);
	mlx_mouse_hook(fractal.mlx.win, ft_mouse_hook, &fractal);
	mlx_loop(fractal.mlx.mlx);
}
