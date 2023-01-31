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
#include "../../fractol.h"

static double	set_real(double c, int set)
{
	if (set == 1)
		c = -0.79;
	else if (set == 2)
		c = -0.162;
	else if (set == 3)
		c = -0.3;
	else if (set == 4)
		c = -1.476;
	else if (set == 5)
		c = -0.12;
	else
		c = 0.28;
	return (c);
}

static double	set_imag(double c, int set)
{
	if (set == 1)
		c = 0.156;
	else if (set == 2)
		c = 1.04;
	else if (set == 3)
		c = -0.01;
	else if (set == 4)
		c = 0;
	else if (set == 5)
		c = -0.77;
	else
		c = 0.008;
	return (c);
}

static int	iterations_new(int x, int y, int iterations, t_fract *fract)
{
	double	c_real;
	double	c_imag;
	double	z_real;
	double	z_imag;
	double	z_real_tmp;

	c_real = 0.0;
	c_imag = 0.0;
	c_real = set_real(c_real, fract->set) + fract->change_c;
	c_imag = set_imag(c_imag, fract->set) + fract->change_c;
	z_real = ((((double) x / WIDTH) * 4 - 2) / fract->zoom_in) + fract->nav_x;
	z_imag = ((((double) y / HEIGHT) * 4 - 2) / fract->zoom_in) + fract->nav_y;
//	z_real /= fract->zoom_in;
//	z_imag /= fract->zoom_in;
//	z_real += fract->nav_x;
//	z_imag += fract->nav_y;
	iterations = 0;
	while (iterations < MAX_ITERATIONS
		&& (z_real * z_real + z_imag * z_imag) <= THRESHOLD)
	{
		z_real_tmp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2 * z_real * z_imag + c_imag;
		z_real = z_real_tmp;
		iterations++;
	}
	return (iterations);
}

static void	fix_x_axis(int y, t_fract *fract)
{
	int	x;
	int	iterations;

	x = 0;
	while (x < WIDTH)
	{
		iterations = iterations_new(x, y, iterations, fract);
		give_color(fract->img, x, y, iterations);
		x++;
	}
}

void	julia_set(t_fract *fract)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		fix_x_axis(y, fract);
		y++;
	}
}
