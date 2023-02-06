/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 16:26:13 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/06 16:26:15 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	give_color(t_fract *fract, int x, int y, int iterations)
{
	if (fract->color == 0)
		gc_auto(fract, x, y, iterations);
	else
		give_diff(fract, x, y, iterations);
}
