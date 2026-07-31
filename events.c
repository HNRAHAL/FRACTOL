/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:08:06 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:08:06 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, 17, 0, close_handler, fractal);
	mlx_hook(fractal->mlx_win, 12, 0, expose_handler, fractal);
	mlx_key_hook(fractal->mlx_win, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_win, mouse_handler, fractal);
}
