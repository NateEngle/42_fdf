# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nengle- <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/05 14:43:45 by nengle-           #+#    #+#              #
#    Updated: 2017/03/05 14:43:48 by nengle-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc 

CFLAGS = -Wall -Wextra -Werror 

INCLUDES = -L./libft -lft -L./minilibx_macos -lmlx -framework OpenGL -framework Appkit

SRCS = main.c pixel_functions.c

PHONY = all re clean fclean

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(SRCS)

clean:

fclean: clean
	rm $(NAME)

re: fclean all