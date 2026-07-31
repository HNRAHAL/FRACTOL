/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:08:01 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:08:01 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keycode, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	if (keycode == ESC_KEY)
		exit_program(fractal);
	return (0);
}

int	close_handler(t_fractal *fractal)
{
	exit_program(fractal);
	return (0);
}

int	expose_handler(t_fractal *fractal)
{
	draw_fractals(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, void *param) //review
{
	t_fractal	*fractal;
	double		mouse_real;
	double		mouse_imag;
	double		zoom;

	fractal = (t_fractal *) param;
	if (button == SCROLL_UP)
		zoom = 0.9;
	else if (button == SCROLL_DOWN)
		zoom = 1.1;
	else
		return (0);
	mouse_real = fractal->min_x
		+ (x * ((fractal->max_x - fractal->min_x) / WIDTH));
	mouse_imag = fractal->max_y
		- (y * ((fractal->max_y - fractal->min_y) / HEIGHT));
	fractal->min_x = mouse_real - ((mouse_real - fractal->min_x) * zoom);
	fractal->max_x = mouse_real + ((fractal->max_x - mouse_real) * zoom);
	fractal->min_y = mouse_imag - ((mouse_imag - fractal->min_y) * zoom);
	fractal->max_y = mouse_imag + ((fractal->max_y - mouse_imag) * zoom);
	draw_fractals(fractal);
	return (0);
}
