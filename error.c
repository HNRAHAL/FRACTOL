/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:07:54 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:07:54 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_dot(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	return (count);
}

static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (check_dot(str) > 1)
		return (0);
	if ((str[i] == '-') || (str[i] == '+'))
	{
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == '\0')
			return (0);
		if ((str[i] == '.') || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

void	check_user_input(int ac, char **av)
{
	if ((ac < 2) || (ac == 3) || (ac > 4))
		error_case_one();
	else if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") != 0)
		|| (ac == 4 && ft_strcmp(av[1], "julia") != 0))
		error_case_two();
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0 && ((av[2][0] == '\0')
		|| (av[3][0] == '\0')))
		error_case_three();
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0
		&& ((ft_isnum(av[2]) == 0) || (ft_isnum(av[3]) == 0)))
		error_case_four();
}
