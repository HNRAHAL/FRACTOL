/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:22:21 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:34:58 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" // dont forget to format

void    error_case_one(void)
{
    write(STDERR_FILENO, "Min input arguments: 2\nMax input arguments: 4\n", 47);
    write(STDERR_FILENO, "Available Options:\n\t1- ./fractol <mandelbrot>\n\t2-./fractol <julia> <real no.> <imag no.>\n", 90);
    exit(EXIT_FAILURE);
}

void error_case_two(void)
{
    write(STDERR_FILENO, "error: Invalid input\n", 22);
    write(STDERR_FILENO, "Available Options:\n\t1- ./fractol <mandelbrot>\n\t2-./fractol <julia> <real no.> <imag no.>\n", 90);
    exit(EXIT_FAILURE);
}

void error_case_three(void)
{
    write(STDERR_FILENO, "error: Empty Data\n", 19);
    write(STDERR_FILENO, "Available Options:\n\t1- ./fractol <mandelbrot>\n\t2-./fractol <julia> <real no.> <imag no.>\n", 90);
    exit(EXIT_FAILURE);
}

void error_case_four(void)
{
    write(STDERR_FILENO, "Input A Valid number\nformat: ./fractol julia <real no.> <imag no>\n", 67);
	exit(EXIT_FAILURE);
}