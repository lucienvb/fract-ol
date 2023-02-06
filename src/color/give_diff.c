/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   give_diff.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 16:26:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/06 16:26:23 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

static uint32_t	*get_color(t_fract *fract)
{
	if (fract->color == 4)
		return (fract->rainbow);
	else if (fract->color == 1)
		return (fract->psyc_one);
	else if (fract->color == 2)
		return (fract->psyc_two);
	else if (fract->color == 3)
		return (fract->blue_green);
	return (NULL);
}

static int	iter_hundred(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	uint32_t		*color;

	color = get_color(fract);
	if (iterations == MAX_ITERATIONS)
	{
		mlx_put_pixel(fract->img, x, y, color[0]);
		return (1);
	}
	return (0);
}

static int	iter_between(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	int				i;
	int				j;
	size_t			k;
	uint32_t		*color;

	color = get_color(fract);
	i = MAX_ITERATIONS;
	k = 1;
	j = i - fract->color_fac;
	while (i > 0)
	{
		if (iterations < i && iterations > j)
		{
			mlx_put_pixel(fract->img, x, y, color[k]);
			return (1);
		}
		k++;
		i = j;
		j -= fract->color_fac;
	}
	return (i);
}

void	give_diff(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	uint32_t	*color;
	int			i;

	color = get_color(fract);
	if (iter_hundred(fract, x, y, iterations) == 1)
		return ;
	i = iter_between(fract, x, y, iterations);
	if (i < 0)
		mlx_put_pixel(fract->img, x, y, color[6]);
}
