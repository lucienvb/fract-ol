/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_zoom.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:30:11 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:30:12 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	change_zoom_fac(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_EQUAL))
		fract->modif.zoom_fac += (fract->modif.zoom_fac / 10);
	if (mlx_is_key_down(fract->mlx, MLX_KEY_MINUS))
		fract->modif.zoom_fac -= (fract->modif.zoom_fac / 10);
}
