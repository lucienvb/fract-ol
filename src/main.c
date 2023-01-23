/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 13:07:17 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/17 16:53:56 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <string.h>
//#include <stdio.h>

/*mlx_image_t	*g_img1;
mlx_image_t	*g_img2;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}*/

/*int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		mandelbrot();
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		julia_set();
	return (0);
}*/

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