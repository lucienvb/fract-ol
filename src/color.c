#include "../fractol.h"

static void	give_color_purple(mlx_image_t *g_img, int x, int y, int iterations)
{
	if (iterations == MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0x2bc0e8FF);
	else if (iterations > (0.8 * MAX_ITERATIONS) && iterations < MAX_ITERATIONS)
		mlx_put_pixel(g_img, x, y, 0xf6cb66FF);
	else if (iterations > (0.6 * MAX_ITERATIONS) && iterations < (0.8 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x484498FF);
	else if (iterations > (0.4 * MAX_ITERATIONS) && iterations < (0.6 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0x63a75eFF);
	else if (iterations > (0.2 * MAX_ITERATIONS) && iterations < (0.4 * MAX_ITERATIONS))
		mlx_put_pixel(g_img, x, y, 0xa0acb4FF);
//	else if (iterations > (0.2 * MAX_ITERATIONS) && iterations < (0.4 * MAX_ITERATIONS))
//		mlx_put_pixel(g_img, x, y, 0xEE82EE);
	else
		mlx_put_pixel(g_img, x, y, 0x443e5eFF);
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

//static uint32_t	get_color(t_fract *fract)
//{
//	if (fract->color == 0)
//		return (fract->rainbow)
//	if (fract->color == 1)
//		return (fract->psyc_colors)
//	if (fract->color == 2)
//		give_color_purple(fract->img, x, y, iterations);
//	if (fract->color == 3)
//		give_color_black_and_white(fract->img, x, y, iterations);
//}

static void	give_color_rainbow(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	int				i;
	int				j;
	size_t 			k;
//	uint32_t		*color;
//
//	color = get_color(fract);

	i = MAX_ITERATIONS;
	k = 1;
	if (iterations == i)
	{
		mlx_put_pixel(fract->img, x, y, fract->rainbow[0]);
		return;
	}
	j = i - fract->color_fac;
	while (i > 0)
	{
		if (iterations < i && iterations > j)
		{
			mlx_put_pixel(fract->img, x, y, fract->rainbow[k]);
			return ;
		}
		k++;
		i = j;
		j -= fract->color_fac;
	}
	if (i < 0)
		mlx_put_pixel(fract->img, x, y, fract->rainbow[--k]);
}

static void	give_color_black_and_white(mlx_image_t *g_img, uint32_t x, uint32_t y, int iterations)
{
	int 			i;
	int				j;
	uint32_t 		lst = 0x9400D3FF;
//	uint32_t 		lst = 0x0bcc31FF;
//	uint32_t 		lst = 0xFFFFEEFF;

	i = MAX_ITERATIONS;
	if (iterations == i)
	{
		mlx_put_pixel(g_img, x, y, lst);
		return;
	}
	lst /= 16;
	j = i - 10;
	while (i > 0)
	{
		if (iterations < i && iterations > j) {
			mlx_put_pixel(g_img, x, y, lst);
			return;
		}
		lst /= 16;
		i = j;
		j -= 10;
	}
	if (i < 0)
		mlx_put_pixel(g_img, x, y, lst);
}

void	give_color(t_fract *fract, int x, int y, int iterations)
{
	if (fract->color == 0)
		give_color_rainbow(fract, x, y, iterations);
	if (fract->color == 1)
		give_color_blue_green(fract->img, x, y, iterations);
	if (fract->color == 2)
		give_color_purple(fract->img, x, y, iterations);
	if (fract->color == 3)
		give_color_black_and_white(fract->img, x, y, iterations);
}
