/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_type.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:07:26 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:07:27 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

double	set_real(double c, int set)
{
	if (set == 1)
		c = -0.79;
	else if (set == 2)
		c = -0.162;
	else if (set == 3)
		c = -0.3;
	else if (set == 4)
		c = -1.476;
	else if (set == 5)
		c = -0.12;
	else
		c = 0.28;
	return (c);
}

double	set_imag(double c, int set)
{
	if (set == 1)
		c = 0.156;
	else if (set == 2)
		c = 1.04;
	else if (set == 3)
		c = -0.01;
	else if (set == 4)
		c = 0;
	else if (set == 5)
		c = -0.77;
	else
		c = 0.008;
	return (c);
}
