#include "../fractol.h"

#include <stdio.h>

static mlx_image_t *g_img;

static void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	 	mlx_close_window(mlx);
}

static int32_t	fractol(int choice, int set)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 1080, 720);    // Creates a new image.
	mlx_image_to_window(mlx, g_img, 0, 0);   // Adds an image to the render queue.
	if (choice)
		mandelbrot(g_img, mlx);
	else
		julia_set(g_img, set);
	mlx_loop_hook(mlx, &hook, mlx);
	//mlx_update_matrix(mlx, WIDTH, HEIGHT);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	//static mlx_image_t *g_img;
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

//#include <stdlib.h>
//
//void my_scrollhook(double xdelta, double ydelta, void* param)
//{
//	(void)param;
//	// Simple up or down detection.
//	if (ydelta > 0)
//		puts("Up!");
//	else if (ydelta < 0)
//		puts("Down!");
//
//	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
//	if (xdelta < 0)
//		puts("Sliiiide to the left!");
//	else if (xdelta > 0)
//		puts("Sliiiide to the right!");
//}
//
//int32_t	main(void)
//{
//	mlx_t* mlx;
//
//	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
//		return (EXIT_FAILURE);
//
//	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
//	mlx_loop(mlx);
//	mlx_terminate(mlx);
//	return (EXIT_SUCCESS);
//}
