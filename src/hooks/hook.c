#include "../../fractol.h"
#include <stdio.h>

static void	hooks_navigate(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_A))
		fract->nav_x -= fract->nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_D))
		fract->nav_x += fract->nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_S))
		fract->nav_y += fract->nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_W))
		fract->nav_y -= fract->nav_step;
	create_fractal(fract);
}

static void	change_nav_step(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_1))
		fract->nav_step -= (fract->nav_step / 10);
	if (mlx_is_key_down(fract->mlx, MLX_KEY_2))
		fract->nav_step += (fract->nav_step / 10);
}

static void	change_zoom_fac(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_EQUAL))
		fract->zoom_fac += (fract->zoom_fac / 10);
	if (mlx_is_key_down(fract->mlx, MLX_KEY_MINUS))
		fract->zoom_fac -= (fract->zoom_fac / 10);
}

static void	hooks_init(t_fract *fract)
{
	change_nav_step(fract);
	change_zoom_fac(fract);
}

void	hook(void *param)
{
	t_fract	*fract;

	fract = param;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fract->mlx);
//	if (fract->choice == 1);
	hooks_init(fract);
	hooks_navigate(fract);
//	else if (fract->choice == 0)
//		hooks_julia(fract);
}
