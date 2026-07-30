#include "fractol.h"

int get_color(int i, int max_iter)
{

    int color;
    if (i == max_iter)
        color = BLACK;
    else
    {
        // darkest
        // int shade = i * (255 /max_iter);
        // color = (shade << 16)|(shade << 8)|shade;

        //lighter
        int shade = 176 - (i * 176 / max_iter);
        color = (shade << 16) | (shade << 8) | shade;
    }
    return color;
}

void pixel_put(t_fractal *fractal, int x, int y, int color)
{
    int offset;

    offset = ((y * fractal->img.line_length) + ( x * fractal->img.bits_per_pixel / 8));
    *(unsigned int *)(fractal->img.pixel_ptr + offset) = color;
}