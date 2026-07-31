/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:08:39 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:08:39 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned int) s1[i] - (unsigned int) s2[i]);
}

static void	sign_check(char *str, int *i, int *sign)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

static void	dot_skip(char *str, int *i)
{
	if (str[*i] == '.')
		(*i)++;
}

double	ft_atof(char *str)
{
	int		sign;
	int		divisor;
	double	num1;
	double	num2;
	int		i;

	sign = 1;
	divisor = 1;
	num1 = 0;
	num2 = 0;
	i = 0;
	sign_check(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
		num1 = num1 * 10 + (str[i++] - '0');
	dot_skip(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num2 = num2 * 10 + (str[i] - '0');
		divisor *= 10;
		i++;
	}
	num2 /= divisor;
	return (sign * (num1 + num2));
}
