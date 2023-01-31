#include "../fractol.h"

int	list_parameters(void)
{
	ft_printf("AVAILABLE PARAMETERS FRACT'OL\n\n");
	ft_printf("*1: There are 3 inputs: [1] the executable (fractol)\n");
	ft_printf("[2] 'mandelbrot' or 'julia' [3] a number between 0 and 7\n");
	ft_printf("*2: With the julia set, the third input will show you a different julia set\n");
	ft_printf("---------------------------------------------------------------------------\n");
	ft_printf("The options are:\n");
	ft_printf("[1]\t\t|\t[2]\t\t|\t[3]\n");
	ft_printf("fractol\t\t|\tmandelbrot\t|\tX (1 till 6)\n");
	ft_printf("''\t\t|\tjulia\t\t|\t1\n");
	ft_printf("''\t\t|\t''\t\t|\t2\n");
	ft_printf("''\t\t|\t''\t\t|\t3\n");
	ft_printf("''\t\t|\t''\t\t|\t4\n");
	ft_printf("''\t\t|\t''\t\t|\t5\n");
	ft_printf("''\t\t|\t''\t\t|\t6\n");
	return (0);
}
