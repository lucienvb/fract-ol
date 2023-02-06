#include "../../fractol.h"
#include <stdio.h>

static void	hooks_navigate(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_LEFT))
		fract->nav_x -= fract->nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_RIGHT))
		fract->nav_x += fract->nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_DOWN))
		fract->nav_y += fract->nav_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_UP))
		fract->nav_y -= fract->nav_step;
	create_fractal(fract);
}

static void	change_nav_step(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_1))
		fract->nav_step /= 2;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_2))
		fract->nav_step *= 2;
}

static void	change_zoom_fac(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_EQUAL))
		fract->zoom_fac += (fract->zoom_fac / 10);
	if (mlx_is_key_down(fract->mlx, MLX_KEY_MINUS))
		fract->zoom_fac -= (fract->zoom_fac / 10);
}

static void	change_c(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_A))
		fract->change_c_real += fract->c_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_D))
		fract->change_c_real -= fract->c_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_S))
		fract->change_c_imag += fract->c_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_W))
		fract->change_c_imag -= fract->c_step;
	create_fractal(fract);
}

static void	change_color(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_SPACE))
	{
		if (fract->color == 4)
			fract->color = 0;
		else
			fract->color++;
	}
	create_fractal(fract);
}

static void	change_auto_background(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_B))
	{
		if (fract->auto_bg == 6)
			fract->auto_bg = 0;
		else
			fract->auto_bg++;
	}
}

static void	change_auto_basis(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_N))
	{
		if (fract->auto_basis == 6)
			fract->auto_basis = 0;
		else
			fract->auto_basis++;
	}
}

static void	hooks_init(t_fract *fract)
{
	change_nav_step(fract);
	change_zoom_fac(fract);
	change_c(fract);
	change_color(fract);
	change_auto_basis(fract);
	change_auto_background(fract);
}

void	hook(void *param)
{
	t_fract	*fract;

	fract = param;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fract->mlx);
	hooks_init(fract);
	hooks_navigate(fract);
}
