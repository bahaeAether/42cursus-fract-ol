/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:38:20 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/31 00:07:17 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H

# define FRACTOL_BONUS_H

# include<mlx.h>
# include<stdlib.h>
# include<unistd.h>
# include<math.h>

# define WIDTH 800
# define HEIGHT 800
# define COLOR 0x00B6FD00
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define ESC 53
# define DESTROY_NOTIFY 17
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_fractol
{
	t_mlx		mlx;
	t_img		img;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	int			type;
	int			max_iter;
}				t_fractol;

t_complex	ft_complex(double re, double im);
void		add_distance(double *min, double *max, double distance);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
void		init_julia(t_fractol *fractal, t_complex c);
void		init_mandelbrot(t_fractol *fractal);
void		init_burning_ship(t_fractol *fractal);
void		ft_draw(t_fractol *fractal);
void		init_borders(t_fractol *fractal);
void		ft_man(void);
void		parse_args(int ac, char **av, t_fractol *fractal);
void		parse_args_julia(int ac, char **av, t_fractol *fractal);
void		ft_putstr(char *str);
int			ft_key_hook(int keycode, t_fractol *fractal);
int			ft_mouse_hook(int button, int x, int y, t_fractol *fractal);
int			ft_mandelbrot(t_complex c, int max_iter);
int			ft_julia(t_complex z, t_complex c, int max_iter);
int			ft_burning_ship(t_complex c, int max_iter);
int			ft_fractol(t_fractol *fractal, t_complex z);
int			color_shader(int color, double ratio);
int			color_shift(void);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
int			ft_is_double(char *str);
int			ft_quit(t_fractol *fractal);
double		ft_atof(char *str);

#endif
