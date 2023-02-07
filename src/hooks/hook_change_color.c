/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_change_color.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:29:52 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:29:54 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

// Hook for changing coloring
void	change_color(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_SPACE))
	{
		if (fract->color.color_type == 4)
			fract->color.color_type = 0;
		else
			fract->color.color_type++;
	}
	create_fractal(fract);
}

// Hook for changing background coloring for the 'auto' color type
void	change_auto_background(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_B))
	{
		if (fract->color.auto_bg == 6)
			fract->color.auto_bg = 0;
		else
			fract->color.auto_bg++;
	}
}

// Hook for changing basis coloring for the 'auto' color type
void	change_auto_basis(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_N))
	{
		if (fract->color.auto_basis == 6)
			fract->color.auto_basis = 0;
		else
			fract->color.auto_basis++;
	}
}
