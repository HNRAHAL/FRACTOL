/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:08:30 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:08:30 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractals(t_fractal *fractal)
{
	if (ft_strcmp(fractal->av[1], "mandelbrot") == 0)
		draw_mandelbrot(fractal);
	else if (ft_strcmp(fractal->av[1], "julia") == 0)
		draw_julia(fractal);
}

void	start_program(t_fractal *fractal)
{
	init_mlx_connection(fractal);
	init_win_connection(fractal);
	init_img_pointer(fractal);
	init_pixel_ptr(fractal);
	draw_fractals(fractal);
	event_init(fractal);
	mlx_loop(fractal->mlx_ptr);
}
