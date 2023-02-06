#include "../fractol.h"

static uint32_t	*get_color(t_fract *fract)
{
	if (fract->color == 0)
		return (fract->rainbow);
	else if (fract->color == 1)
		return (fract->psyc_one);
	else if (fract->color == 2)
		return (fract->psyc_two);
	else if (fract->color == 3)
		return (fract->blue_green);
//	if (fract->color == 2)
//		give_color_purple(fract->img, x, y, iterations);
//	if (fract->color == 3)
//		give_color_black_and_white(fract->img, x, y, iterations);
	return (NULL);
}

static void	give_colors(t_fract *fract, uint32_t x, uint32_t y, int iterations)
{
	int				i;
	int				j;
	size_t 			k;
	uint32_t		*color;

	color = get_color(fract);
	i = MAX_ITERATIONS;
	k = 1;
	if (iterations == i)
	{
		mlx_put_pixel(fract->img, x, y, color[0]);
		return;
	}
	j = i - fract->color_fac;
	while (i > 0)
	{
		if (iterations < i && iterations > j)
		{
			mlx_put_pixel(fract->img, x, y, color[k]);
			return ;
		}
		k++;
		i = j;
		j -= fract->color_fac;
	}
	if (i < 0)
		mlx_put_pixel(fract->img, x, y, color[--k]);
}

static void	give_color_auto(mlx_image_t *g_img, uint32_t x, uint32_t y, int iterations)
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
		if (iterations < i && iterations > j)
		{
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
	if (fract->color == 4)
		give_color_auto(fract->img, x, y, iterations);
	else
		give_colors(fract, x, y, iterations);
}
