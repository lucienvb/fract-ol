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
#include <stdlib.h>
#include "../fractol.h"

#define WIDTH 1080
#define HEIGHT 720
#define MIN_X -2.0
#define MAX_X 1.0
#define MIN_Y -1.5
#define MAX_Y 1.5
#define MAX_ITERATIONS 1000
#define THRESHOLD 4.0

static int	iterations_new(int iterations, double c_real, double c_imag)
{
	double	z_real_new;
	double	z_imag_new;
	double	z_real;
	double	z_imag;

	z_real = 0.0;
	z_imag = 0.0;
	iterations = 0;
	while (iterations < MAX_ITERATIONS
		&& (z_real * z_real + z_imag * z_imag) < THRESHOLD)
	{
		z_real_new = z_real * z_real - z_imag * z_imag + c_real;
		z_imag_new = 2 * z_real * z_imag + c_imag;
		z_real = z_real_new;
		z_imag = z_imag_new;
		iterations++;
	}
	return (iterations);
}

static void	fix_x_axis(double x_step, double y_step, int y, mlx_image_t *g_img)
{
	double	c_real;
	double	c_imag;
	int		x;
	int		iterations;

	x = 0;
	while (x < WIDTH)
	{
		c_real = MIN_X + x * x_step;
		c_imag = MIN_Y + y * y_step;
		iterations = iterations_new(iterations, c_real, c_imag);
		if (iterations != MAX_ITERATIONS)
			mlx_put_pixel(g_img, x, y,0xFFFFFFFF); // Single white pixel in the middle.
		x++;
	}
}
//void	mandelbrot(void)
void	mandelbrot(mlx_image_t *g_img)
{
	double	x_step;
	double	y_step;
	int		y;

	x_step = (MAX_X - MIN_X) / WIDTH;
	y_step = (MAX_Y - MIN_Y) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		fix_x_axis(x_step, y_step, y, g_img);
		y++;
	}
}
