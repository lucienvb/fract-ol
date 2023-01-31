#include "../fractol.h"

static void	hooks_mandelbrot(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_A))
		fract->nav_x -= fract->nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_D))
		fract->nav_x += fract->nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_S))
		fract->nav_y += fract->nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_W))
		fract->nav_y -= fract->nav_step;
	mandelbrot(fract);
}

void	hook(void *param)
{
	t_fract	*fract;

	fract = param;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fract->mlx);
	if (fract->choice == 1)
		hooks_mandelbrot(fract);
//	else if (fract->choice == 0)
//		hooks_julia(fract);
}

static void	scroll_mandelbrot(t_fract *fract, double y_offset)
{
	if (y_offset > 0)
		zoom_in(fract);
	else if (y_offset < 0)
		zoom_out(fract);
	mandelbrot(fract);
}

static void	scroll_julia(t_fract *fract, double y_offset)
{
	if (y_offset > 0)
		fract->tmp -= 0.001;
	if (y_offset < 0)
		fract->tmp += 0.001;
	julia_set(fract);
}

void	scroll_hook(double x_offset, double y_offset, void *param)
{
	t_fract *fract;

	(void) x_offset;
	fract = param;
	if (fract->choice == 1)
		scroll_mandelbrot(fract, y_offset);
	else if (fract->choice == 0)
		scroll_julia(fract, y_offset);
}