/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:08:46 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:08:46 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	variable_init(t_fractal *fractal)
{
	fractal->mlx_ptr = NULL;
	fractal->mlx_win = NULL;
	fractal->max_x = 2.0;
	fractal->min_x = -2.0;
	fractal->max_y = 2.0;
	fractal->min_y = -2.0;
	fractal->iteration = 50;
	fractal->num_var.tmp_z_img = 0.0;
	fractal->num_var.tmp_z_real = 0.0;
}
