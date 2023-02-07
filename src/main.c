/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 11:01:51 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 11:01:53 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

#include <stdio.h>

// Loop in which the hooks are active.
static void	main_event_loop(t_fract *fract)
{
	mlx_loop_hook(fract->mlx, &hook, fract);
	mlx_scroll_hook(fract->mlx, &scroll_hook, fract);
	mlx_loop(fract->mlx);
}

// Deletes the created image and terminate the mlx.
static void	clean_up(t_fract *fract)
{
	mlx_delete_image(fract->mlx, fract->img);
	mlx_terminate(fract->mlx);
}

// Creates a window, creates a fractal, goes in a loop for the hooks
// and cleans up at the end.
int32_t	mlx(t_fract *fract)
{
	create_window(fract);
	create_fractal(fract);
	main_event_loop(fract);
	clean_up(fract);
	return (EXIT_SUCCESS);
}

// Checks the input in the command line and gives overview
// of available parameters if necessary.
// Does the initialization.
// Calls the mlx function.
int	main(int argc, char **argv)
{
	t_fract	fract;

	if (!input_parsing(argc, argv))
		return (list_parameters());
	initialize(&fract, argv);
	mlx(&fract);
	return (0);
}
