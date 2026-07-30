#include "fractol.h"

static int check_dot(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i])
    {
        if(str[i] == '.')
            count++;
        i++;
    }
    return (count);
}

static int ft_isnum(char *str)
{
    int i;

    i = 0;
    if(check_dot(str) > 1)
        return(0);
        
    if((str[i] == '-') || (str[i] == '+'))
    {
        i++;
        if(str[i] == '-' || str[i] == '+')
            return(0);
    }

    while(str[i])
    {
        if(str[i] == '.' && str[i + 1] == '\0')
            return(0);

        if(( str[i] == '.') || (str[i] >= '0' && str[i] <= '9'))
            i++;
        else
            return(0);
    }
    return(1);
}

void check_user_input(int ac, char **av)
{
    if((ac < 2) || (ac == 3) ||( ac > 4))
    {
        write(STDERR_FILENO, "Min input arguments: 2\nMax input arguments: 4\n",47);
        write(STDERR_FILENO, "Available Options:\n\t1- ./fractol <mandelbrot>\n\t2-./fractol <julia> <real no.> <imag no.>\n", 90);
        exit(EXIT_FAILURE);
    }
    else if((ac == 2 && ft_strcmp(av[1], "mandelbrot") != 0) || (ac == 4 && ft_strcmp(av[1], "julia") != 0))
    {
        write(STDERR_FILENO, "error: Invalid input\n", 22);
        write(STDERR_FILENO, "Available Options:\n\t1- ./fractol <mandelbrot>\n\t2-./fractol <julia> <real no.> <imag no.>\n", 90);
        exit(EXIT_FAILURE);
    }
    else if(ac == 4 && ft_strcmp(av[1], "julia") == 0 && ((av[2][0] == '\0') || (av[3][0] == '\0')))
    {
        write(STDERR_FILENO, "error: Empty Data\n", 19);
        write(STDERR_FILENO, "Available Options:\n\t1- ./fractol <mandelbrot>\n\t2-./fractol <julia> <real no.> <imag no.>\n", 90);
        exit(EXIT_FAILURE);
    }
    else if(ac == 4 && ft_strcmp(av[1], "julia") == 0 && ((ft_isnum(av[2]) == 0) || (ft_isnum(av[3]) == 0)))
    {
        write(STDERR_FILENO, "Input A Valid number\nformat: ./fractol julia <real no.> <imag no>\n", 67);
        exit(EXIT_FAILURE);
    }
}