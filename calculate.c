#include "fractol.h"

void mandelbrot_calculations(t_fractal *fractal, int x, int y)
{
    int i;
    t_num z;
    t_num c;

    c.real = fractal->min_x + (x * ((fractal->max_x - fractal->min_x) / WIDTH));
    c.imag = fractal->max_y - (y * ((fractal->max_y - fractal->min_y) / HEIGHT));

    i = 0;
    z.real = 0.0;
    z.imag = 0.0;
    while(i < fractal->iteration)
    {
        fractal->num_var.tmp_z_real = z.real;
        fractal->num_var.tmp_z_img = z.imag;
        z.real = fractal->num_var.tmp_z_real * fractal->num_var.tmp_z_real - fractal->num_var.tmp_z_img * fractal->num_var.tmp_z_img + c.real;
        z.imag = 2 * fractal->num_var.tmp_z_real * fractal->num_var.tmp_z_img + c.imag;
        if(z.real * z.real + z.imag * z.imag > 4)
        {
            pixel_put(fractal, x, y, 0xffd700 * i);
            return ;
        }
        i++;
    }
    pixel_put(fractal, x, y, 0x0 );
}

void julia_calculations(t_fractal *fractal, int x, int y)
{
    int i;
    t_num z;
    t_num c;

    c.real = ft_atof(fractal->av[2]);
    c.imag = ft_atof(fractal->av[3]);
    z.real = fractal->min_x + (x * ((fractal->max_x - fractal->min_x) / WIDTH));
    z.imag = fractal->max_y - (y * ((fractal->max_y - fractal->min_y) / HEIGHT));
    i = 0;
    while(i < fractal->iteration)
    {
        fractal->num_var.tmp_z_real = z.real;
        fractal->num_var.tmp_z_img = z.imag;
        z.real = fractal->num_var.tmp_z_real * fractal->num_var.tmp_z_real - fractal->num_var.tmp_z_img * fractal->num_var.tmp_z_img + c.real;
        z.imag = 2 * fractal->num_var.tmp_z_real * fractal->num_var.tmp_z_img + c.imag;
        if(z.real * z.real + z.imag * z.imag > 4)
        {
            pixel_put(fractal, x, y, 0xffd700 * i);
            return ;
        }
        i++;
    }
    pixel_put(fractal, x, y, 0x0);
}