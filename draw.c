#include "fractol.h"

void draw_mandelbrot(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {
            mandelbrot_calculations(fractal, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}

void draw_julia(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {
            julia_calculations(fractal, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}
