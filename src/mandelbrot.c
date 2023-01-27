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
#include "../fractol.h"

void	give_color(mlx_image_t *g_img, int x, int y, int iterations)
{
	if (iterations == MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0x000000);
	else if (iterations > (0.8 * MAX_ITERATIONS) && iterations < MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0xADD8E6);
	else if (iterations > (0.6 * MAX_ITERATIONS) && iterations < (0.8 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x057F95);
	else if (iterations > (0.4 * MAX_ITERATIONS) && iterations < (0.6 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x40E0D0);
	else if (iterations > (0.2 * MAX_ITERATIONS) && iterations < (0.4 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0xC2DFFF);
	else
		mlx_put_pixel(g_img, x, y, 0xFDD31D);

}

	static int	iterations_new(int iterations, double c_real, double c_imag)
{
	double	z_real_tmp;
	double 	z_imag_tmp;
	double	z_real;
	double	z_imag;

	z_real = 0.0;
	z_imag = 0.0;
	iterations = 0;
	while (iterations < MAX_ITERATIONS
		   && (z_real + z_imag) <= THRESHOLD)
	{
		z_imag_tmp = 2 * z_real_tmp * z_imag_tmp + c_imag;
		z_real_tmp = z_real - z_imag + c_real;
		z_real = z_real_tmp * z_real_tmp;
		z_imag = z_imag_tmp * z_imag_tmp;
		iterations++;
	}
	return (iterations);
}

static void	fix_x_axis(int y, t_fract *fract)
{
	double	c_real;
	double	c_imag;
	int		x;
	int		iterations;

	x = 0;
	while (x < WIDTH)
	{
		c_real = fract->min_x + x * fract->x_step;
		c_imag = fract->min_y + y * fract->y_step;
		iterations = iterations_new(iterations, c_real, c_imag);
		give_color(fract->img, x, y, iterations);
		x++;
	}
}

void	mandelbrot(t_fract *fract)
{
	int		y;

	y = 0;
	fract->x_step = (fract->max_x - fract->min_x) / WIDTH;
	fract->y_step = (fract->max_y - fract->min_y) / HEIGHT;
	while (y < HEIGHT)
	{
		fix_x_axis(y, fract);
		y++;
	}
}

