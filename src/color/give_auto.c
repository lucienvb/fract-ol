/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   give_auto.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 16:26:01 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/06 16:26:04 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

// When iterations equals max_iterations, the first color in lst is used.
static int	iter_hundred(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	uint32_t	lst;
	t_color		*col;

	col = &fract->color;
	lst = col->psyc_two[col->auto_basis];
	if (iterations == MAX_ITERATIONS)
	{
		mlx_put_pixel(fract->img, x, y, lst);
		return (1);
	}
	return (0);
}

// Depending on which number of iterations between 'i' and max_iterations,
// a color in lst is used.
static int	iter_between(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	uint32_t	lst;
	t_color		*col;
	int			i;
	int			j;

	i = MAX_ITERATIONS;
	col = &fract->color;
	lst = col->psyc_two[col->auto_basis];
	lst /= col->auto_color_fac;
	j = i - col->auto_layer_fac;
	while (i > 0)
	{
		if (iterations < i && iterations > j)
		{
			mlx_put_pixel(fract->img, x, y, lst);
			return (1);
		}
		lst /= col->auto_color_fac;
		i = j;
		j -= col->auto_layer_fac;
	}
	return (i);
}

// Generates color based on a given input with a variation of inputs.
// When i equals 0, a background color is used.
void	gc_auto(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	t_color	*col;
	int		i;

	if (iter_hundred(fract, x, y, iterations) == 1)
		return ;
	i = iter_between(fract, x, y, iterations);
	col = &fract->color;
	if (i == 0)
		mlx_put_pixel(fract->img, x, y, col->psyc_one[col->auto_bg]);
}
