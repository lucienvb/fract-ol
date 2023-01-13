# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-bus <lvan-bus@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/12 16:36:24 by lvan-bus      #+#    #+#                  #
#    Updated: 2023/01/13 17:34:58 by lvan-bus      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=======================================#
#========		VARIABLES:		========#
#=======================================#

NAME	:= fractol
CC		:= cc
CFLAGS	?= -Wall -Wextra -Werror
LDFLAGS	?= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
#LDFLAGS	?= -fsanitize=address -g

SRC		:= \
		src/mandelbrot.c

#src/main.c
#src/test_main.c

OBJ		:= $(SRC:.c=.o)

#=======================================#
#========		RECIPIES		========#
#=======================================#

all:	$(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(MAKE) -C ./ft_printf
		$(MAKE) -C ./MLX42
		$(CC) $(LDFLAGS) $^ ./libft/libft.a ./ft_printf/libftprintf.a ./MLX42/libmlx42.a -o $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		rm -f $(OBJ)
		$(MAKE) -C ./libft clean
		$(MAKE) -C ./ft_printf clean
		$(MAKE) -C ./MLX42 clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./ft_printf fclean
		$(MAKE) -C ./MLX42 fclean

re: fclean all

.PHONY: all clean fclean re
