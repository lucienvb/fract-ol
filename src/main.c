#include "../fractol.h"
#include <string.h>

/*mlx_image_t	*g_img1;
mlx_image_t	*g_img2;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}*/

void	mandelbrot(int c)
{
	long long	z;
	int	i;

	z = 0;
	i = 0;
	while ((z < INT_MAX && z > INT_MIN) || i < 10)
	{
		z = z * z + c;
		ft_printf("z%i: %i\n", i, z);
		i++;
	}
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	float	z;
	float	c;
	int		i;

	z = 0;
	i = 0;
	if (argc != 2)
		return (0);
	c = atof(argv[1]);
	// mandelbrot(c);
	
	// while (c < 2.5)
	// {
	while (i < 10)
	{
		printf("%f\n", z);
		z = z * z + c;
		i++;
	}
		// if (z > 100000)
		// write(1, " ", 1);



	return (0);
}

/*int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img1 = mlx_new_image(mlx, 5, 5);
	g_img2 = mlx_new_image(mlx, 5, 5);
	memset(g_img1->pixels, 255, g_img1->width * g_img1->height * sizeof(int));
	memset(g_img2->pixels, 255, g_img2->width * g_img2->height * sizeof(int));
	mlx_image_to_window(mlx, g_img1, 250, 250);
	mlx_image_to_window(mlx, g_img2, 200, 200);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}*/