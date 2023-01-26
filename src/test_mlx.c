#include "../fractol.h"

#include <stdio.h>

//double zoom = 1.0;
//double zoom_factor = 2.0;

//static void zoom_in(void)
//{
//	MIN_X /= zoom_factor;
//	MAX_X /= zoom_factor;
//	MIN_Y /= zoom_factor;
//	MAX_Y /= zoom_factor;
//	zoom *= zoom_factor;
//	x_step = (MAX_X - MIN_X) / WIDTH;
//	y_step = (MAX_Y - MIN_Y) / HEIGHT;
//}

static void	hook(void *param)
{
	mlx_t	*mlx;
//	int 	a;
//	int 	b;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	 	mlx_close_window(mlx);
	if (mlx_is_mouse_down(mlx, MLX_MOUSE_BUTTON_LEFT))
		fractol(1, 1, 1);
}

int32_t	fractol(int choice, int set, int zoom)
{
	t_vars	vars;

	if (!zoom)
	{
		vars.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
		if (!vars.mlx)
			exit(EXIT_FAILURE);
		vars.img = mlx_new_image(vars.mlx, 1080, 720);
		mlx_image_to_window(vars.mlx, vars.img, 0, 0);
	}
	if (choice)
		mandelbrot(vars.img, zoom);
	else
		julia_set(vars.img, set);
	mlx_loop_hook(vars.mlx, &hook, vars.mlx);
	//mlx_update_matrix(mlx, WIDTH, HEIGHT);
	mlx_loop(vars.mlx);
	mlx_delete_image(vars.mlx, vars.img); // Once the application request an exit, cleanup.
	mlx_terminate(vars.mlx);
	return (EXIT_SUCCESS);
}

static void	setup(char **argv)
{
	static int zoom;

	zoom = 0;
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fractol(1, ft_atoi(argv[2]), zoom);
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		fractol(0, ft_atoi(argv[2]), zoom);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	setup(argv);
	return (0);
}
