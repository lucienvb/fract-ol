#include "../fractol.h"

#include <stdio.h>
#define WIDTH 1080
#define HEIGHT 720
//#define WIDTH 80
//#define HEIGHT 60

static mlx_image_t *g_img;

int32_t	fractol(int choice)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 1080, 720);    // Creates a new image.
	mlx_image_to_window(mlx, g_img, 0, 0);   // Adds an image to the render queue.
	if (choice)
		mandelbrot(g_img);
	else
		julia_set(g_img);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		fractol(1);
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		fractol(0);
	return (0);
}
