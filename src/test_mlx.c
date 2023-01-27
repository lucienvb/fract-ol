#include "../fractol.h"

#include <stdio.h>

static void zoom_in(t_fract *fract)
{
	fract->zoom += 0.005;
	fract->min_x /= fract->zoom;
	fract->max_x /= fract->zoom;
	fract->min_y /= fract->zoom;
	fract->max_y /= fract->zoom;
}

static void hook(void *param)
{

	t_fract	*fract;
	fract = param;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
	 	mlx_close_window(fract->mlx);
	if (fract->choice == 1)
	{
		if (mlx_is_mouse_down(fract->mlx, MLX_MOUSE_BUTTON_LEFT)) {
			zoom_in(fract);
			mandelbrot(fract);
		}
	}
	else if (fract->choice == 0)
	{
		if (mlx_is_mouse_down(fract->mlx, MLX_MOUSE_BUTTON_LEFT))
			fract->tmp -= 0.005;
		if (mlx_is_mouse_down(fract->mlx, MLX_MOUSE_BUTTON_RIGHT))
			fract->tmp += 0.005;
		julia_set(fract);
	}
}

int32_t	mlx(t_fract *fract)
{
	fract->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fract->mlx)
		exit(EXIT_FAILURE);
	fract->img = mlx_new_image(fract->mlx, 1080, 720);
	mlx_image_to_window(fract->mlx, fract->img, 0, 0);
	if (fract->choice)
		mandelbrot(fract);
	else
		julia_set(fract);
	mlx_loop_hook(fract->mlx, &hook, fract);
	mlx_loop(fract->mlx);
	mlx_delete_image(fract->mlx, fract->img);
	mlx_terminate(fract->mlx);
	return (EXIT_SUCCESS);
}

static void	setup(t_fract *fract, char **argv)
{
	fract->tmp = 1.0;
	fract->zoom = 1.0;
	fract->min_x = -2.0;
	fract->max_x = 1.0;
	fract->min_y = -1.5;
	fract->max_y = 1.5;

	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fract->choice = 1;
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		fract->choice = 0;
	fract->set = ft_atoi(argv[2]);
	mlx(fract);
}

int	main(int argc, char **argv)
{
	t_fract	fract;

	if (argc != 3)
		return (0);
	setup(&fract, argv);
	return (0);
}
