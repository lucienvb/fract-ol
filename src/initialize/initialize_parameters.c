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
	{
		fract->choice = 1;
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fract->choice = 0;
	}
	fract->set = ft_atoi(argv[2]);
}

static void	init_hook_settings(t_fract *fract)
{
	fract->tmp = 1.0;
	fract->zoom_in = 1.0;
	fract->zoom_out = 1.0;
	fract->zoom_fac = 0.005;
	fract->nav_x = 0.0;
	fract->nav_y = 0.0;
	fract->nav_step = 0.01;
	fract->change_c_real = 0.0;
	fract->change_c_imag = 0.0;
	fract->c_step = 0.005;
}

static void	init_screen_settings(t_fract *fract)
{
	fract->min_x = -2.0;
	fract->max_x = 1.0;
	fract->min_y = -1.5;
	fract->max_y = 1.5;
}

static void	init_color_setting(t_fract *fract)
{
	fract->color = 0;
	fract->color_fac = 17.0;
	fract->auto_color_fac = 3;
	fract->auto_layer_fac = 5;
	fract->auto_bg = 0;
	fract->auto_basis = 0;
}

void	initialize(t_fract *fract, char **argv)
{
	init_screen_settings(fract);
	init_hook_settings(fract);
	init_color_setting(fract);
	init_colors(fract);
	init_type(fract, argv);
}
