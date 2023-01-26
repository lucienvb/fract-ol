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
# define MIN_X -2.0
# define MAX_X 1.0
# define MIN_Y -1.5
# define MAX_Y 1.5
# define MAX_ITERATIONS 40
//# define MAX_ITERATIONS 100
# define THRESHOLD 4.0

// STRUCTURES
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	mlx_image_t	*img;
}	t_vars;

// MAIN FUNCTION

// FUNCTIONS -- MANDELBROT & JULIA
void	mandelbrot(mlx_image_t *g_img);
void	give_color(mlx_image_t *g_img, int x, int y, int iterations);
void	julia_set(mlx_image_t *g_img, int set);

#endif
