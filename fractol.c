/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:08:12 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:08:12 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	fractal.av = av;
	check_user_input(ac, av);
	variable_init(&fractal);
	start_program(&fractal);
	free_and_destroy_allocs(&fractal);
}
