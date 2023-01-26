#include "../fractol.h"

#include <stdio.h>

static void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	 	mlx_close_window(mlx);
}

static int32_t	fractol(int choice, int set)
{
	t_vars	vars;

	vars.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	vars.img = mlx_new_image(vars.mlx, 1080, 720);    // Creates a new image.
	mlx_image_to_window(vars.mlx, vars.img, 0, 0);   // Adds an image to the render queue.
	if (choice)
		mandelbrot(vars.img);
	else
		julia_set(vars.img, set);
	mlx_loop_hook(vars.mlx, &hook, vars.mlx);
	//mlx_update_matrix(mlx, WIDTH, HEIGHT);
	mlx_loop(vars.mlx);
	mlx_delete_image(vars.mlx, vars.img); // Once the application request an exit, cleanup.
	mlx_terminate(vars.mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fractol(1, ft_atoi(argv[2]));
		//fractol(1, g_img);
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		fractol(0, ft_atoi(argv[2]));
		//fractol(0, g_img);
	return (0);
}
