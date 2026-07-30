#include "fractol.h"

void free_and_destroy_allocs(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
    mlx_destroy_display(fractal->mlx_ptr);
    free(fractal->mlx_ptr);
    exit(EXIT_SUCCESS);
}

void exit_program(t_fractal *fractal)
{
    free_and_destroy_allocs(fractal);
}