/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 10:07:45 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/17 11:15:35 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../fractol.h"

// Calculates and returns the number of iterations for the current
// location (x, y) required to escape a threshold.
static int	iter_new(int iter, double c_real, double c_imag, t_fract *fract)
{
	double	z_real_tmp;
	double	z_imag_tmp;
	double	z_real;
	double	z_imag;

	z_real = 0.0;
	z_imag = 0.0;
	iter = 0;
	while (iter < MAX_ITERATIONS && (z_real + z_imag) <= THRESHOLD)
	{
		z_imag_tmp = 2 * z_real_tmp * z_imag_tmp + c_imag + fract->modif.nav_y;
		z_real_tmp = z_real - z_imag + c_real + fract->modif.nav_x;
		z_real = z_real_tmp * z_real_tmp;
		z_imag = z_imag_tmp * z_imag_tmp;
		iter++;
	}
	return (iter);
}

// Iterates over the x-axis (WIDTH)
// Sets c_real and c_imag
// Calculates the number of iterations at the current location (x, y)
// The give_color function sets the color of the pixel located at x, y
// based on the value of iterations.
static void	fix_x_axis(int y, t_fract *fract)
{
	double	c_real;
	double	c_imag;
	int		x;
	int		iterations;

	x = 0;
	while (x < WIDTH)
	{
		c_real = fract->screen.min_x + x * fract->modif.x_step;
		c_imag = fract->screen.min_y + y * fract->modif.y_step;
		iterations = iter_new(iterations, c_real, c_imag, fract);
		give_color(fract, x, y, iterations);
		x++;
	}
}

// Sets x_step and y_step
// Iterates over the y-axis (HEIGHT) and calls the fix_x_axis function
// for every value.
void	mandelbrot(t_fract *fract)
{
	int		y;

	y = 0;
	fract->modif.x_step = (fract->screen.max_x - fract->screen.min_x) / WIDTH;
	fract->modif.y_step = (fract->screen.max_y - fract->screen.min_y) / HEIGHT;
	while (y < HEIGHT)
	{
		fix_x_axis(y, fract);
		y++;
	}
}
