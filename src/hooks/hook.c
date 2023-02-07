/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:07:43 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:29:19 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

// This hooks allows you to quit the program using the escape button
static void	escape_hook(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fract->mlx);
}

// Initializes all hooks
static void	hooks_init(t_fract *fract)
{
	change_nav_step(fract);
	change_zoom_fac(fract);
	change_c(fract);
	change_color(fract);
	change_auto_basis(fract);
	change_auto_background(fract);
	escape_hook(fract);
}

// Initializes all hooks and navigation
void	hook(void *param)
{
	t_fract	*fract;

	fract = param;
	hooks_init(fract);
	hooks_navigate(fract);
}
