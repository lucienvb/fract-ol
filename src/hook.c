#include "../fractol.h"

void hook(void *param)
{
	t_fract	*fract;

	fract = param;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fract->mlx);
	if (fract->choice == 1)
	{
		if (mlx_is_mouse_down(fract->mlx, MLX_MOUSE_BUTTON_LEFT))
			zoom(fract, -0.005);
		else if (mlx_is_mouse_down(fract->mlx, MLX_MOUSE_BUTTON_RIGHT))
			zoom(fract, 0.005);
		mandelbrot(fract);
	}
	else if (fract->choice == 0)
	{
		if (mlx_is_mouse_down(fract->mlx, MLX_MOUSE_BUTTON_LEFT))
			fract->tmp -= 0.005;
		else if (mlx_is_mouse_down(fract->mlx, MLX_MOUSE_BUTTON_RIGHT))
			fract->tmp += 0.005;
		julia_set(fract);
	}
}