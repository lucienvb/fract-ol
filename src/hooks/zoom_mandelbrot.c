/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:06:31 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:30:29 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	zoom_in(t_fract *fract)
{
	if (fract->modif.zoom_out != 1)
		fract->modif.zoom_out = 1;
	fract->modif.zoom_in -= fract->modif.zoom_fac;
	fract->screen.min_x /= fract->modif.zoom_in;
	fract->screen.max_x /= fract->modif.zoom_in;
	fract->screen.min_y /= fract->modif.zoom_in;
	fract->screen.max_y /= fract->modif.zoom_in;
}

void	zoom_out(t_fract *fract)
{
	if (fract->modif.zoom_in != 1)
		fract->modif.zoom_in = 1;
	fract->modif.zoom_out += fract->modif.zoom_fac;
	fract->screen.min_x /= fract->modif.zoom_out;
	fract->screen.max_x /= fract->modif.zoom_out;
	fract->screen.min_y /= fract->modif.zoom_out;
	fract->screen.max_y /= fract->modif.zoom_out;
}
