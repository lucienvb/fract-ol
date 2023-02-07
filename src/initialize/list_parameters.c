/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_parameters.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:01:01 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:01:03 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

// Message with available parameters for the user.
int	list_parameters(void)
{
	ft_printf("AVAILABLE PARAMETERS FRACT'OL\n\n");
	ft_printf("There are 3 inputs:\n");
	ft_printf("1) The executable (fractol)\n");
	ft_printf("2) The type of fractal ('mandelbrot' or 'julia')\n");
	ft_printf("3) The type of julia (a number between 0 and 7)\n");
	ft_printf("For the mandelbrot set, the third input does nothing.\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("The options are:\n");
	ft_printf("[1]\t\t|\t[2]\t\t|\t[3]\n");
	ft_printf("fractol\t\t|\tmandelbrot\t|\tX (1 till 6)\n");
	ft_printf("''\t\t|\tjulia\t\t|\t1\n");
	ft_printf("''\t\t|\t''\t\t|\t2\n");
	ft_printf("''\t\t|\t''\t\t|\t3\n");
	ft_printf("''\t\t|\t''\t\t|\t4\n");
	ft_printf("''\t\t|\t''\t\t|\t5\n");
	ft_printf("''\t\t|\t''\t\t|\t6\n");
	ft_printf("------------------------------------------------------------\n");
	return (0);
}
