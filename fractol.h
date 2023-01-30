/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:08:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/17 13:05:32 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

// INCLUDE
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

// DEFINE
# define WIDTH 1080
# define HEIGHT 720
//# define MIN_X -2.0
//# define MAX_X 1.0
//# define MIN_Y -1.5
//# define MAX_Y 1.5
//# define MAX_ITERATIONS 40
# define MAX_ITERATIONS 100
# define THRESHOLD 4.0
//# define zoom 1.0
# define zoom_factor 2.0

// STRUCTURES
typedef struct s_fract
{
	void		*mlx;
	void		*win;
	mlx_image_t	*img;
	int 		choice;
	int 		set;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		x_step;
	double		y_step;
	double 		zoom;
	double 		tmp;
}	t_fract;

// MAIN FUNCTION

// FUNCTIONS -- MANDELBROT & JULIA
int32_t	mlx(t_fract *fract);
void	mandelbrot(t_fract *fract);
void	julia_set(t_fract *fract);

// FUNCTIONS -- UTILS
void	zoom(t_fract *fract, double zoom_fac);
void	hook(void *param);
void	give_color(mlx_image_t *g_img, int x, int y, int iterations);
void	initialize(t_fract *fract, char **argv);
void	create_fractal(t_fract *fract);
void	create_window(t_fract *fract);
mlx_image_t	*create_new_window(void *ptr, int width, int height);


#endif

