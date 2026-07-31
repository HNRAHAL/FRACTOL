/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:07:43 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:07:43 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx_connection(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
	{
		write(STDERR_FILENO, "Failed Allocation\n", 19);
		exit(EXIT_FAILURE);
	}
}

void	init_win_connection(t_fractal *fractal)
{
	fractal->mlx_win = mlx_new_window
		(fractal->mlx_ptr, WIDTH, HEIGHT, fractal->av[1]);
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		write(STDERR_FILENO, "Failed Allocation\n", 19);
		exit(EXIT_FAILURE);
	}
}

void	init_img_pointer(t_fractal *fractal)
{
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
		free(fractal->mlx_ptr);
		write(STDERR_FILENO, "Failed Allocation\n", 19);
		exit(EXIT_FAILURE);
	}
}

void	init_pixel_ptr(t_fractal *fractal)
{
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length,
			&fractal->img.endian);
}
