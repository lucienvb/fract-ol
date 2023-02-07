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
# define MAX_ITERATIONS 100
# define THRESHOLD 4.0

// STRUCTURES -- COLOR, MODIFICATIONS, SCREEN & FRACT (root struct)
typedef struct s_color
{
	uint32_t	auto_color_fac;
	uint32_t	auto_layer_fac;
	uint32_t	blue_green[7];
	uint32_t	psyc_one[7];
	uint32_t	psyc_two[7];
	uint32_t	rainbow[7];
	uint32_t	color_type;
	uint32_t	auto_basis;
	double		color_fac;
	uint32_t	auto_bg;
}	t_color;

typedef struct s_modif
{
	double		change_c_real;
	double		change_c_imag;
	double		zoom_out;
	double		zoom_fac;
	double		nav_step;
	double		zoom_in;
	double		x_step;
	double		y_step;
	double		c_step;
	double		nav_y;
	double		nav_x;
}	t_modif;

typedef struct s_screen
{
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
}	t_screen;

typedef struct s_fract
{
	t_color		color;
	t_modif		modif;
	t_screen	screen;
	mlx_image_t	*img;
	void		*mlx;
	int			choice;
	int			set;
}	t_fract;

// MAIN FUNCTION

// COLORING
void	give_color(t_fract *fract, int x, int y, int iterations);
void	give_diff(t_fract *fract, uint32_t x, uint32_t y, int iterations);
void	gc_auto(t_fract *fract, uint32_t x, uint32_t y, int iterations);

// FUNCTIONS -- MANDELBROT & JULIA
void	mandelbrot(t_fract *fract);
void	julia_set(t_fract *fract);
double	set_imag(double c, int set);
double	set_real(double c, int set);

// INITIALIZE
void	initialize(t_fract *fract, char **argv);
void	init_colors(t_fract *fract);

// MLX
int32_t	mlx(t_fract *fract);

// FUNCTIONS -- UTILS
void	zoom_in(t_fract *fract);
void	zoom_out(t_fract *fract);
void	create_fractal(t_fract *fract);
void	create_window(t_fract *fract);
int		list_parameters(void);

// HOOKS
void	hook(void *param);
void	scroll_hook(double x_offset, double y_offset, void *param);
void	change_color(t_fract *fract);
void	change_auto_background(t_fract *fract);
void	change_auto_basis(t_fract *fract);
void	hooks_navigate(t_fract *fract);
void	change_nav_step(t_fract *fract);
void	change_zoom_fac(t_fract *fract);
void	change_c(t_fract *fract);

#endif
