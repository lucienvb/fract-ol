/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_change_c.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:29:41 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:29:42 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	change_c(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_A))
		fract->modif.change_c_real += fract->modif.c_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_D))
		fract->modif.change_c_real -= fract->modif.c_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_S))
		fract->modif.change_c_imag += fract->modif.c_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_W))
		fract->modif.change_c_imag -= fract->modif.c_step;
	create_fractal(fract);
}
