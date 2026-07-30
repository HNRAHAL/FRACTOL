#include "fractol.h"

int main(int ac, char **av)
{
    t_fractal fractal;

    fractal.av = av;
    check_user_input(ac, av);
    variable_init(&fractal);
    start_program(&fractal);
    free_and_destroy_allocs(&fractal);
}