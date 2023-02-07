/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_navigate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:30:02 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:30:03 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

// Hook for making navigating through the screen possible
void	hooks_navigate(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_LEFT))
		fract->modif.nav_x -= fract->modif.nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_RIGHT))
		fract->modif.nav_x += fract->modif.nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_DOWN))
		fract->modif.nav_y += fract->modif.nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_UP))
		fract->modif.nav_y -= fract->modif.nav_step;
	create_fractal(fract);
}

// Hook to change the navigation step size
void	change_nav_step(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_1))
		fract->modif.nav_step /= 2;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_2))
		fract->modif.nav_step *= 2;
}
