/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 08:53:40 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/22 08:53:42 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include<mlx.h>
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<math.h>

# define WIDTH 1300
# define HEIGHT 1300
# define COLOR 0x00FFFF00 //0x0083FF00
# define MAX_ITER 600
# define WHELL_UP 4
# define WHELL_DOWN 5
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define ESC 53
# define MANDELBROT 1
# define JULIA 2

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data{
	t_img		img;
	t_vars		vars;
	t_complex	c;
	t_complex	**plane;
	int			**canvas;
	int			name;
	double		zoom;
	t_complex	center;
}				t_data;

#endif
