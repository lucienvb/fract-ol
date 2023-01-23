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
// # define WIDTH 500
// # define HEIGHT 500

// STRUCTURES

// MAIN FUNCTION

// FUNCTIONS -- MANDELBROT & JULIA
//void	mandelbrot(void);
void	mandelbrot(mlx_image_t *g_img);
void	give_color(mlx_image_t *g_img, int x, int y, int iterations);
//void	julia_set(void);
void	julia_set(mlx_image_t *g_img, int set);

#endif
