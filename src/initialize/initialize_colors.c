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

static void	init_rainbow(t_fract *fract)
{
	fract->rainbow[0] = 0x9400D3FF;
	fract->rainbow[1] = 0x4B0082FF;
	fract->rainbow[2] = 0x0000FFFF;
	fract->rainbow[3] = 0x00FF00FF;
	fract->rainbow[4] = 0xFFFF00FF;
	fract->rainbow[5] = 0xFF7F00FF;
	fract->rainbow[6] = 0xFF0000FF;
}

static void	init_psyc_one(t_fract *fract)
{
	fract->psyc_one[0] = 0x443e5eFF;
	fract->psyc_one[1] = 0xa0acb4FF;
	fract->psyc_one[2] = 0x63a75eFF;
	fract->psyc_one[3] = 0x484498FF;
	fract->psyc_one[4] = 0xf6cb66FF;
	fract->psyc_one[5] = 0x2bc0e8FF;
	fract->psyc_one[6] = 0x2bc0e8FF;
}

static void	init_psyc_two(t_fract *fract)
{
	fract->psyc_two[0] = 0x546c6cFF;
	fract->psyc_two[1] = 0x7f91a7FF;
	fract->psyc_two[2] = 0x6e54a4FF;
	fract->psyc_two[3] = 0xb4d40cFF;
	fract->psyc_two[4] = 0xebfc7dFF;
	fract->psyc_two[5] = 0xdafa0dFF;
	fract->psyc_two[6] = 0xdafa0dFF;
}

static void	init_blue_green(t_fract *fract)
{
	fract->blue_green[0] = 0xFFFFFFFF;
	fract->blue_green[1] = 0x21fd2bFF;
	fract->blue_green[2] = 0x0bcc31FF;
	fract->blue_green[3] = 0x0588daFF;
	fract->blue_green[4] = 0x210a7fFF;
	fract->blue_green[5] = 0x61b3ffFF;
	fract->blue_green[6] = 0x61b3ffFF;
}

void	init_colors(t_fract *fract)
{
	init_rainbow(fract);
	init_psyc_one(fract);
	init_psyc_two(fract);
	init_blue_green(fract);
}
