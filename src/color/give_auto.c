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

static int	iter_hundred(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	uint32_t	lst;

	lst = fract->psyc_two[fract->auto_basis];
	if (iterations == MAX_ITERATIONS)
	{
		mlx_put_pixel(fract->img, x, y, lst);
		return (1);
	}
	return (0);
}

static int	iter_between(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	uint32_t	lst;
	int			i;
	int			j;

	i = MAX_ITERATIONS;
	lst = fract->psyc_two[fract->auto_basis];
	lst /= fract->auto_color_fac;
	j = i - fract->auto_layer_fac;
	while (i > 0)
	{
		if (iterations < i && iterations > j)
		{
			mlx_put_pixel(fract->img, x, y, lst);
			return (1);
		}
		lst /= fract->auto_color_fac;
		i = j;
		j -= fract->auto_layer_fac;
	}
	return (i);
}

void	gc_auto(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	int	i;

	if (iter_hundred(fract, x, y, iterations) == 1)
		return ;
	i = iter_between(fract, x, y, iterations);
	if (i == 0)
		mlx_put_pixel(fract->img, x, y, fract->psyc_one[fract->auto_bg]);
}
