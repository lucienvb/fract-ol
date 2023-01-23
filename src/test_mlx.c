#include "../fractol.h"

#include <stdio.h>
#define WIDTH 1080
#define HEIGHT 720
//#define WIDTH 80
//#define HEIGHT 60

static mlx_image_t *g_img;

static void	hook(void *param)
//static void	hook(mlx_t *mlx)
{
	mlx_t	*mlx;

	mlx = param;
	 if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	 	mlx_close_window(mlx);
//	if (mlx_is_key_down(mlx, MLX_KEY_UP))
//		g_img->instances[0].y -= 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
//		g_img->instances[0].y += 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
//		g_img->instances[0].x -= 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
//		g_img->instances[0].x += 5;
}

//static int32_t	fractol(int choice, mlx_image_t *g_img)
static int32_t	fractol(int choice, int set)
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
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		fractol(1, ft_atoi(argv[2]));
		//fractol(1, g_img);
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		fractol(0, ft_atoi(argv[2]));
		//fractol(0, g_img);
	return (0);
}
