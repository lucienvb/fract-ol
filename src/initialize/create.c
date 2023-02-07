/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:00:32 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:00:34 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

static void	init_window(t_fract *fract)
{
	fract->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fract->mlx)
		exit(EXIT_FAILURE);
}

static void	put_image_on_window(t_fract *fract)
{
	mlx_image_to_window(fract->mlx, fract->img, 0, 0);
}

static mlx_image_t	*create_new_window(void *ptr, int width, int height)
{
	return (mlx_new_image(ptr, width, height));
}

void	create_window(t_fract *fract)
{
	init_window(fract);
	fract->img = create_new_window(fract->mlx, WIDTH, HEIGHT);
	put_image_on_window(fract);
}

void	create_fractal(t_fract *fract)
{
	if (fract->choice)
		mandelbrot(fract);
	else
		julia_set(fract);
}
