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

static uint32_t	*get_color(t_color *color)
{
	if (color->color_type == 4)
		return (color->rainbow);
	else if (color->color_type == 1)
		return (color->psyc_one);
	else if (color->color_type == 2)
		return (color->psyc_two);
	else if (color->color_type == 3)
		return (color->blue_green);
	return (0);
}

static int	iter_hundred(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	uint32_t		*color;

	color = get_color(&fract->color);
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

	color = get_color(&fract->color);
	i = MAX_ITERATIONS;
	k = 1;
	j = i - fract->color.color_fac;
	while (i > 0)
	{
		if (iterations < i && iterations > j)
		{
			mlx_put_pixel(fract->img, x, y, color[k]);
			return (1);
		}
		k++;
		i = j;
		j -= fract->color.color_fac;
	}
	return (i);
}

void	give_diff(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	uint32_t	*color;
	int			i;

	color = get_color(&fract->color);
	if (color == 0)
		return ;
	if (iter_hundred(fract, x, y, iterations) == 1)
		return ;
	i = iter_between(fract, x, y, iterations);
	if (i < 0)
		mlx_put_pixel(fract->img, x, y, color[6]);
}
