/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:07:38 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:07:38 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_fractal *fractal, int x, int y, int color)
{
	int	offset;

	offset = ((y * fractal->img.line_length
				) + (x * fractal->img.bits_per_pixel / 8));
	*(unsigned int *)(fractal->img.pixel_ptr + offset) = color;
}
