/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_colors.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 16:54:33 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/06 16:54:35 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

static void	init_rainbow(t_color *color)
{
	color->rainbow[0] = 0x9400D3FF;
	color->rainbow[1] = 0x4B0082FF;
	color->rainbow[2] = 0x0000FFFF;
	color->rainbow[3] = 0x00FF00FF;
	color->rainbow[4] = 0xFFFF00FF;
	color->rainbow[5] = 0xFF7F00FF;
	color->rainbow[6] = 0xFF0000FF;
}

static void	init_psyc_one(t_color *color)
{
	color->psyc_one[0] = 0x443e5eFF;
	color->psyc_one[1] = 0xa0acb4FF;
	color->psyc_one[2] = 0x63a75eFF;
	color->psyc_one[3] = 0x484498FF;
	color->psyc_one[4] = 0xf6cb66FF;
	color->psyc_one[5] = 0x2bc0e8FF;
	color->psyc_one[6] = 0x2bc0e8FF;
}

static void	init_psyc_two(t_color *color)
{
	color->psyc_two[0] = 0x546c6cFF;
	color->psyc_two[1] = 0x7f91a7FF;
	color->psyc_two[2] = 0x6e54a4FF;
	color->psyc_two[3] = 0xb4d40cFF;
	color->psyc_two[4] = 0xebfc7dFF;
	color->psyc_two[5] = 0xdafa0dFF;
	color->psyc_two[6] = 0xdafa0dFF;
}

static void	init_blue_green(t_color *color)
{
	color->blue_green[0] = 0xFFFFFFFF;
	color->blue_green[1] = 0x21fd2bFF;
	color->blue_green[2] = 0x0bcc31FF;
	color->blue_green[3] = 0x0588daFF;
	color->blue_green[4] = 0x210a7fFF;
	color->blue_green[5] = 0x61b3ffFF;
	color->blue_green[6] = 0x61b3ffFF;
}

void	init_colors(t_fract *fract)
{
	init_rainbow(&fract->color);
	init_psyc_one(&fract->color);
	init_psyc_two(&fract->color);
	init_blue_green(&fract->color);
}
