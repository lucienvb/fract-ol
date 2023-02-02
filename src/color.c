#include "../fractol.h"

static void	give_color_purple(mlx_image_t *g_img, int x, int y, int iterations)
{
	if (iterations == MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0x000000FF);
	else if (iterations > (0.8 * MAX_ITERATIONS) && iterations < MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0xADD8E6FF);
	else if (iterations > (0.6 * MAX_ITERATIONS) && iterations < (0.8 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x057F95FF);
	else if (iterations > (0.4 * MAX_ITERATIONS) && iterations < (0.6 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x40E0D0FF);
	else if (iterations > (0.2 * MAX_ITERATIONS) && iterations < (0.4 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0xC2DFFFFF);
//	else if (iterations > (0.2 * MAX_ITERATIONS) && iterations < (0.4 * MAX_ITERATIONS))
//		mlx_put_pixel(g_img, x, y, 0xEE82EE);
	else
		mlx_put_pixel(g_img, x, y, 0xCBC3E3FF);
}

static void	give_color_blue_green(mlx_image_t *g_img, int x, int y, int iterations)
{
	if (iterations == MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0xFFFFFFFF);
	else if (iterations > (0.8 * MAX_ITERATIONS) && iterations < MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0x21fd2bFF);
	else if (iterations > (0.6 * MAX_ITERATIONS) && iterations < (0.8 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x0bcc31FF);
	else if (iterations > (0.4 * MAX_ITERATIONS) && iterations < (0.6 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x0588daFF);
	else if (iterations > (0.2 * MAX_ITERATIONS) && iterations < (0.4 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x210a7fFF);
	else
		mlx_put_pixel(g_img, x, y, 0x61b3ffFF);
}

static void	give_color_rainbow(mlx_image_t *g_img, int x, int y, int iterations)
{
	if (iterations == MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0x9400D3FF);
	else if (iterations > (0.85 * MAX_ITERATIONS) && iterations < MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0x4B0082FF);
	else if (iterations > (0.7 * MAX_ITERATIONS) && iterations < (0.85 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x0000FFFF);
	else if (iterations > (0.55 * MAX_ITERATIONS) && iterations < (0.7 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x00FF00FF);
	else if (iterations > (0.4 * MAX_ITERATIONS) && iterations < (0.55 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0xFFFF00FF);
	else if (iterations > (0.2 * MAX_ITERATIONS) && iterations < (0.4 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0xFF7F00FF);
	else
		mlx_put_pixel(g_img, x, y, 0xFF0000FF);
}

// try to fix the coloring with while loops instead of hard coding it
/*static void	give_color_rainbow(mlx_image_t *g_img, int x, int y, int iterations)
{
	int 			i;
	int				j;
	size_t 			k;
	unsigned int	lst[] = {0x9400D3FF, 0x9400D3FF, 0x4B0082FF, 0x0000FFFF, 0x00FF00FF, 0xFFFF00FF, 0xFF7F00FF, 0xFF0000FF};

	i = MAX_ITERATIONS;
	j = 1;
	k = 0;
	while(j > 0 && i > 0)
	{
		if (iterations == i && j == 0)
		{
			mlx_put_pixel(g_img, x, y, lst[k++]);
		}
		else if (iterations < i && iterations > j)
		{
			mlx_put_pixel(g_img, x, y, lst[k++]);
			i -= 15;
		}
		j = i -15;
	}
}*/

static void	give_color_black_and_white(mlx_image_t *g_img, int x, int y, int iterations)
{
	if (iterations == MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0xFFFFFFFF);
	else if (iterations > (0.85 * MAX_ITERATIONS) && iterations < MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0x000000FF);
	else if (iterations > (0.7 * MAX_ITERATIONS) && iterations < (0.85 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0xFFFFFFFF);
	else if (iterations > (0.55 * MAX_ITERATIONS) && iterations < (0.7 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x000000FF);
	else if (iterations > (0.4 * MAX_ITERATIONS) && iterations < (0.55 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0xFFFFFFFF);
	else if (iterations > (0.2 * MAX_ITERATIONS) && iterations < (0.4 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x000000FF);
	else
		mlx_put_pixel(g_img, x, y, 0xFFFFFFFF);
}

void	give_color(t_fract *fract, int x, int y, int iterations)
{
	if (fract->color == 0)
		give_color_rainbow(fract->img, x, y, iterations);
	if (fract->color == 1)
		give_color_blue_green(fract->img, x, y, iterations);
	if (fract->color == 2)
		give_color_purple(fract->img, x, y, iterations);
	if (fract->color == 3)
		give_color_black_and_white(fract->img, x, y, iterations);
}
