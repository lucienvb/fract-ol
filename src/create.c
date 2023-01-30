#include "../fractol.h"

static void	init_window(t_fract *fract)
{
	fract->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fract->mlx)
		exit(EXIT_FAILURE);
}

static void	put_image_on_window(t_fract *fract)
{
	mlx_image_to_window(fract->mlx, fract->img, 0, 0);
}

void	create_window(t_fract *fract)
{
	init_window(fract);
	fract->img = create_new_window(fract->mlx, WIDTH, HEIGHT);
	put_image_on_window(fract);
}

void	create_fractal(t_fract *fract)
{
	if (fract->choice)
		mandelbrot(fract);
	else
		julia_set(fract);
}