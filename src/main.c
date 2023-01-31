#include "../fractol.h"

#include <stdio.h>

static void	main_event_loop(t_fract *fract)
{
	mlx_loop_hook(fract->mlx, &hook, fract);
	mlx_scroll_hook(fract->mlx, &scroll_hook, fract);
	mlx_loop(fract->mlx);
}

static void	clean_up(t_fract *fract)
{
	mlx_delete_image(fract->mlx, fract->img);
	mlx_terminate(fract->mlx);
}

int32_t	mlx(t_fract *fract)
{
	create_window(fract);
	create_fractal(fract);
	main_event_loop(fract);
	clean_up(fract);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fract	fract;

	if (!input_parsing(argc, argv))
		return (list_parameters());
	initialize(&fract, argv);
	mlx(&fract);
//	system("leaks fractol");
	return (0);
}
