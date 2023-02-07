# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-bus <lvan-bus@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/12 16:36:24 by lvan-bus      #+#    #+#                  #
#    Updated: 2023/01/17 16:54:19 by lvan-bus      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=======================================#
#========		VARIABLES:		========#
#=======================================#

NAME	:= fractol
CC		:= cc
CFLAGS	?= -Wall -Wextra -Werror
LDFLAGS	?= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o3 -march=native
#SFLAG	?= -fsanitize=address -g

SRC		:= \
		src/main.c \
		src/color/color.c \
		src/color/give_diff.c \
		src/color/give_auto.c \
		src/fractal/julia_set.c \
        src/fractal/set_type.c \
        src/fractal/mandelbrot.c \
        src/hooks/zoom_mandelbrot.c \
		src/hooks/hook.c \
		src/hooks/scroll_hook.c \
		src/hooks/hook_change_color.c \
		src/hooks/hook_navigate.c \
		src/hooks/hook_zoom.c \
		src/hooks/hook_change_c.c \
		src/initialize/initialize_colors.c \
		src/initialize/initialize_parameters.c \
		src/initialize/create.c \
		src/initialize/list_parameters.c

OBJ		:= $(SRC:.c=.o)

#=======================================#
#========		RECIPIES		========#
#=======================================#

all:	$(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(MAKE) -C ./MLX42
		$(CC) $(LDFLAGS) $(SFLAG) $^ ./libft/libft.a ./MLX42/libmlx42.a -o $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		rm -f $(OBJ)
		$(MAKE) -C ./libft clean
		$(MAKE) -C ./MLX42 clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./MLX42 fclean

re: fclean all

#LIST_TEST :=

test: $(OBJ)
		$(CC) $(CFLAGS) $(LDFLAGS) UnityExample.c $(LIST_TEST) unity/libunity.a ./libft/libft.a ./MLX42/libmlx42.a -o unittest
		@ ./unittest

.PHONY: all clean fclean re