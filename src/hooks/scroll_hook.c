/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scroll_hook.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:30:20 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:30:21 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include "../../fractol.h"
#include "fractol.h"

static void	scroll_mandelbrot(t_fract *fract, double y_offset)
{
	if (y_offset > 0)
		zoom_in(fract);
	else if (y_offset < 0)
		zoom_out(fract);
	mandelbrot(fract);
}

static void	scroll_julia(t_fract *fract, double y_offset)
{
	fract->modif.zoom_in -= fract->modif.zoom_fac * y_offset;
	julia_set(fract);
}

// Hook to realize zooming in and out with the mousewheel
void	scroll_hook(double x_offset, double y_offset, void *param)
{
	t_fract	*fract;

	(void) x_offset;
	fract = param;
	if (fract->choice == 1)
		scroll_mandelbrot(fract, y_offset);
	else if (fract->choice == 0)
		scroll_julia(fract, y_offset);
}
