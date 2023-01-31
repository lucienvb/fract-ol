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
LDFLAGS	?= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -fast
#LDFLAGS	?= -fsanitize=address -g

SRC		:= \
		src/main.c \
		src/fractal/julia_set.c \
		src/fractal/mandelbrot.c \
		src/color.c \
		src/create.c \
		src/initialize.c \
		src/temp.c \
		src/zoom.c \
		src/list_parameters.c \
		src/hooks/hook.c \
		src/hooks/scroll_hook.c

#src/test_main.c

OBJ		:= $(SRC:.c=.o)

#=======================================#
#========		RECIPIES		========#
#=======================================#

all:	$(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(MAKE) -C ./MLX42
		$(CC) $(LDFLAGS) $^ ./libft/libft.a ./MLX42/libmlx42.a -o $(NAME)

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

LIST_TEST := \
			src/zoom.c \
			src/temp.c

test: $(OBJ)
		$(CC) $(CFLAGS) $(LDFLAGS) UnityExample.c $(LIST_TEST) unity/libunity.a ./libft/libft.a ./MLX42/libmlx42.a -o unittest
		@ ./unittest

.PHONY: all clean fclean re