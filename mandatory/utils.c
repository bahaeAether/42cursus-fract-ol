/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:22:09 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/31 00:15:16 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double	ft_atof(char *str)
{
	double	nb;
	double	quotient;
	double	sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	quotient = 0.1;
	if (str[i] == '-')
	{
		sign = -1.0;
		i++;
	}
	while (str[i] && str[i] != '.')
		nb = nb * 10.0 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		nb = nb + (str[i++] - '0') * quotient;
		quotient /= 10;
	}
	return (nb * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] - s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_is_double(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '.' || str[ft_strlen(str) - 1] == '.')
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (dot > 1)
		return (0);
	return (1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
