/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia_set.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 10:07:48 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/17 13:05:13 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <complex.h>
#include <math.h>
#include "../fractol.h"

#define WIDTH 80
#define HEIGHT 60
#define MAX_ITERATIONS 100
#define THRESHOLD 4.0

static int	iteration_new(int x, int y, int iteration)
{
	double	c_real;
	double	c_imag;
	double	z_real;
	double	z_imag;
	double	z_real_temp;

	c_real = -0.8;
	c_imag = 0.156;
	z_real = ((double)x / WIDTH) * 4 - 2;
	z_imag = ((double)y / HEIGHT) * 4;
	iteration = 0;
	while (iteration < MAX_ITERATIONS
		&& z_real * z_real + z_imag * z_imag < THRESHOLD)
	{
		z_real_temp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2 * z_real * z_imag + c_imag;
		z_real = z_real_temp;
		iteration++;
	}
	return (iteration);
}

static void	fix_x_axis(int y)
{
	int	x;
	int	iteration;

	x = 0;
	while (x < WIDTH)
	{
		iteration = iteration_new(x, y, iteration);
		if (iteration == MAX_ITERATIONS)
			ft_printf("*");
		else
			ft_printf(" ");
		x++;
	}
}

void	julia_set(void)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		fix_x_axis(y);
		ft_printf("\n");
		y++;
	}
}
