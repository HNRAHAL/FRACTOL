/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:08:17 by hrahal            #+#    #+#             */
/*   Updated: 2026/07/31 15:08:17 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0X000000
# define WHITE 0XFFFFFF

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define PLUS_KEY 65457
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_num
{
	double	real;
	double	imag;
	double	dist;
	double	tmp_z_real;
	double	tmp_z_img;
}	t_num;

typedef struct s_fractal
{
	char	**av;
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
	t_num	num_var;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	int		iteration;
}	t_fractal;

//	ERROR
void	check_user_input(int ac, char **av);

//	ERROR CASES
void	error_case_one(void);
void	error_case_two(void);
void	error_case_three(void);
void	error_case_four(void);

//	AR INIT
void	variable_init(t_fractal *fractal);

//	DISPLAY
void	init_mlx_connection(t_fractal *fractal);
void	init_win_connection(t_fractal *fractal);
void	init_img_pointer(t_fractal *fractal);
void	init_pixel_ptr(t_fractal *fractal);

//	SETUP
void	start_program(t_fractal *fractal);
void	draw_fractals(t_fractal *fractal);

//	RAW
void	draw_mandelbrot(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);

//	CALCULATIONS
void	mandelbrot_calculations(t_fractal *fractal, int x, int y);
void	julia_calculations(t_fractal *fractal, int x, int y);

//	OLOR
void	pixel_put(t_fractal *fractal, int x, int y, int color);

//	EVENTS
void	event_init(t_fractal *fractal);

//	EVENT HANDLER
int		mouse_handler(int button, int x, int y, void *param);
int		key_handler(int keycode, void *param);
int		close_handler(t_fractal *fractal);
int		expose_handler(t_fractal *fractal);

//	UTILS
int		ft_strcmp(const char *s1, const char *s2);
double	ft_atof(char *str);

//	FREE
void	free_and_destroy_allocs(t_fractal *fractal);
void	exit_program(t_fractal *fractal);

#endif
