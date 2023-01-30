#include "../fractol.h"

static void	initialize_type(t_fract *fract, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0) {
		fract->choice = 1;
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0) {
		fract->choice = 0;
	}
	fract->set = ft_atoi(argv[2]);
}

static void initialize_settings(t_fract *fract)
{
	fract->tmp = 1.0;
	fract->zoom = 1.0;
	fract->min_x = -2.0;
	fract->max_x = 1.0;
	fract->min_y = -1.5;
	fract->max_y = 1.5;
}

void	initialize(t_fract *fract, char **argv)
{
	initialize_settings(fract);
	initialize_type(fract, argv);
}