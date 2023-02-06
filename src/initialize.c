#include "../fractol.h"

static void	initialize_type(t_fract *fract, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		fract->choice = 1;
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fract->choice = 0;
	}
	fract->set = ft_atoi(argv[2]);
}

static void	initialize_settings(t_fract *fract)
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
	fract->color_fac = 17.0;
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

static void	initialize_colors(t_fract *fract)
{
	init_rainbow(fract);
	init_psyc_one(fract);
	init_psyc_two(fract);
	init_blue_green(fract);
}

void	initialize(t_fract *fract, char **argv)
{
	initialize_settings(fract);
	initialize_colors(fract);
	initialize_type(fract, argv);
}
