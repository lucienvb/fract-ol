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
	fract->zoom_in = 1.0;
	fract->zoom_out = 1.0;
	fract->zoom_fac = 0.005;
	fract->min_x = -2.0;
	fract->max_x = 1.0;
	fract->min_y = -1.5;
	fract->max_y = 1.5;
	fract->nav_x = 0.0;
	fract->nav_y = 0.0;
	fract->nav_step = 0.01;
	fract->change_c_real = 0.0;
	fract->change_c_imag = 0.0;
	fract->c_step = 0.005;
	fract->color = 0;
	fract->color_fac = 15;
}

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

static void	initialize_colors(t_fract *fract)
{
	init_rainbow(fract);
}

void	initialize(t_fract *fract, char **argv)
{
	initialize_settings(fract);
	initialize_colors(fract);
	initialize_type(fract, argv);
}