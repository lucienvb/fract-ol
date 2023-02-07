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

#include "../../fractol.h"

static double	set_z_real(t_fract *fract, double z_real, int x)
{
	t_modif	*mod;

	mod = &fract->modif;
	z_real = ((((double) x / WIDTH) * 4 - 2) / mod->zoom_in) + mod->nav_x;
	return (z_real);
}

static double	set_z_imag(t_fract *fract, double z_imag, int y)
{
	t_modif	*mod;

	mod = &fract->modif;
	z_imag = ((((double) y / HEIGHT) * 4 - 2) / mod->zoom_in) + mod->nav_y;
	return (z_imag);
}

// Calculates and returns the number of iterations for the current
// location (x, y) required to escape a threshold.
static int	iterations_new(int x, int y, int iterations, t_fract *fract)
{
	double	c_real;
	double	c_imag;
	double	z_real;
	double	z_imag;
	double	z_real_tmp;

	c_real = 0.0;
	c_imag = 0.0;
	z_real = 0.0;
	z_imag = 0.0;
	c_real = set_real(c_real, fract->set) + fract->modif.change_c_real;
	c_imag = set_imag(c_imag, fract->set) + fract->modif.change_c_imag;
	z_real = set_z_real(fract, z_real, x);
	z_imag = set_z_imag(fract, z_imag, y);
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

// Iterates over the x-axis (WIDTH)
// Calculates the number of iterations at the current location (x, y)
// The give_color function sets the color of the pixel located at x, y
// based on the value of iterations.
static void	fix_x_axis(int y, t_fract *fract)
{
	int	x;
	int	iterations;

	x = 0;
	while (x < WIDTH)
	{
		iterations = iterations_new(x, y, iterations, fract);
		give_color(fract, x, y, iterations);
		x++;
	}
}

// Iterates over the y-axis (HEIGHT) and calls the fix_x_axis function
// for every value.
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
