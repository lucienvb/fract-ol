# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-bus <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/04 15:34:16 by lvan-bus      #+#    #+#                  #
#    Updated: 2022/10/19 13:03:17 by lvan-bus      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=======================================#
#========		VARIABLES:		========#
#=======================================#

NAME 		:= libft.a
CC			:= cc
CFLAGS 		?= -Wall -Wextra -Werror

SRC 		:= \
	ft_itoa.c \
	ft_putstr_fd.c \
	ft_strmapi.c \
	ft_atoi.c \
	ft_memchr.c \
	ft_split.c \
	ft_strncmp.c \
	ft_bzero.c \
	ft_memcmp.c \
	ft_strchr.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_memcpy.c \
	ft_strdup.c \
	ft_strrchr.c \
	ft_isalnum.c \
	ft_memmove.c \
	ft_striteri.c \
	ft_strtrim.c \
	ft_isalpha.c \
	ft_memset.c \
	ft_strjoin.c \
	ft_substr.c \
	ft_isascii.c \
	ft_putchar_fd.c \
	ft_strlcat.c \
	ft_tolower.c \
	ft_isdigit.c \
	ft_putendl_fd.c \
	ft_strlcpy.c \
	ft_toupper.c \
	ft_isprint.c \
	ft_putnbr_fd.c \
	ft_strlen.c 

OBJ			:= $(SRC:.c=.o)

#=======================================#
#========		RECIPIES		========#
#=======================================#

all: $(NAME)

$(NAME): $(OBJ)
		ar -cr $(NAME) $(OBJ)

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
