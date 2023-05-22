/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:52:45 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/22 09:04:18 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*pix;

	pix = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pix = color;
}

int	maximum(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

void	my_mlx_canvas_put(t_img *img, int **canvas)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, canvas[i][j]);
			j++;
		}
		i++;
	}
}

int	**ft_init_canvas(void)
{
	int		**canvas;
	int		i;
	int		j;

	i = 0;
	canvas = (int **)malloc(sizeof(int *) * WIDTH);
	while (i < WIDTH)
	{
		j = 0;
		canvas[i] = (int *)malloc(sizeof(int) * HEIGHT);
		while (j < HEIGHT)
		{
			canvas[i][j] = 0;
			j++;
		}
		i++;
	}
	return (canvas);
}

t_complex	**ft_init_complex(double zoom, t_complex center)
{
	t_complex	**z;
	int			i;
	int			j;

	i = 0;
	z = (t_complex **)malloc(sizeof(t_complex *) * WIDTH);
	while (i < WIDTH)
	{
		j = 0;
		z[i] = (t_complex *)malloc(sizeof(t_complex) * HEIGHT);
		while (j < HEIGHT)
		{
			z[i][j].re = (i - WIDTH / 2) / (0.5 * zoom * WIDTH) + center.re;
			z[i][j].im = (j - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + center.im;
			j++;
		}
		i++;
	}
	return (z);
}

void	ft_canvas(int **canvas, t_complex **z, int index, t_complex c)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (index == 1)
				canvas[i][j] = ft_mandelbrot(z[i][j]);
			if (index == 2)
				canvas[i][j] = ft_julia(z[i][j], c);
			max = maximum(max, canvas[i][j]);
			j++;
		}
		i++;
	}
}

t_complex	ft_complex(double real, double imag)
{
	t_complex	c;

	c.re = real;
	c.im = imag;
	return (c);
}

int	ft_mandelbrot(t_complex c)
{
	t_complex	z;
	int			i;

	i = 1;
	z = ft_complex(0, 0);
	while (i < MAX_ITER)
	{
		z = ft_complex(z.re * z.re - z.im * z.im + c.re,
				2 * z.re * z.im + c.im);
		if (z.re * z.re + z.im * z.im > 16)
			break ;
		i++;
	}
	if (i == MAX_ITER)
		return (0);
	return (i);
}

int	ft_julia(t_complex z, t_complex c)
{
	int	i;

	i = 1;
	while (i < MAX_ITER)
	{
		z = ft_complex(z.re * z.re - z.im * z.im + c.re,
				2 * z.re * z.im + c.im);
		if (z.re * z.re + z.im * z.im > 16)
			break ;
		i++;
	}
	if (i == MAX_ITER)
		return (0);
	return (i);
}

void	ft_valuetocolor(int **canvas)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			canvas[i][j] = color_shader(COLOR,
					sqrt((double)canvas[i][j] / (MAX_ITER - 1)));
			j++;
		}
		i++;
	}
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

void	fractal_constructor(t_data *fractal, int name, t_complex c, double zoom, t_complex center)
{
	fractal->name = name;
	fractal->c = c;
	fractal->zoom = zoom;
	fractal->center = center;
	fractal->img.img = mlx_new_image(fractal->vars.mlx, WIDTH, HEIGHT);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_per_pixel,
			&fractal->img.line_length, &fractal->img.endian);
	fractal->vars.win = mlx_new_window(fractal->vars.mlx, WIDTH, HEIGHT, "fract-ol");
	fractal->plane = ft_init_complex(zoom, center);
	fractal->canvas = ft_init_canvas();
	ft_canvas(fractal->canvas, fractal->plane, fractal->name, fractal->c);
	ft_valuetocolor(fractal->canvas);
}

int	main(int ac, char **av)
{
	t_data	fractal;

	(void)ac;
	(void)av;
	fractal.vars.mlx = mlx_init();
	fractal_constructor(&fractal, MANDELBROT, ft_complex(0, 0), 1, ft_complex(-0.5, 0));
	my_mlx_canvas_put(&fractal.img, fractal.canvas);
	mlx_put_image_to_window(fractal.vars.mlx, fractal.vars.win, fractal.img.img, 0, 0);
	// mlx_hook(vars.win, 4, 1L<<0, print_key, &vars);
	mlx_loop(fractal.vars.mlx);
	free(fractal.plane);
	free(fractal.canvas);
}
