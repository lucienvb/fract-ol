/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_parameters.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 16:54:43 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/06 16:54:45 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

static void	init_type(t_fract *fract, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fract->choice = 1;
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		fract->choice = 0;
	fract->set = ft_atoi(argv[2]);
}

// Initializes hook settings
static void	init_hook_settings(t_fract *fract)
{
	fract->modif.zoom_in = 1.0;
	fract->modif.zoom_out = 1.0;
	fract->modif.zoom_fac = 0.005;
	fract->modif.nav_x = 0.0;
	fract->modif.nav_y = 0.0;
	fract->modif.nav_step = 0.01;
	fract->modif.change_c_real = 0.0;
	fract->modif.change_c_imag = 0.0;
	fract->modif.c_step = 0.005;
}

// Initializes screen settings
static void	init_screen_settings(t_screen *screen)
{
	screen->min_x = -2.0;
	screen->max_x = 1.0;
	screen->min_y = -1.5;
	screen->max_y = 1.5;
}

// Initializes color settings
static void	init_color_setting(t_color *color)
{
	color->color_type = 0;
	color->color_fac = 17.0;
	color->auto_color_fac = 3;
	color->auto_layer_fac = 5;
	color->auto_bg = 4;
	color->auto_basis = 5;
}

void	initialize(t_fract *fract, char **argv)
{
	init_screen_settings(&fract->screen);
	init_hook_settings(fract);
	init_color_setting(&fract->color);
	init_colors(fract);
	init_type(fract, argv);
}
