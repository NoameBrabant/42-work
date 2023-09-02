# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tremy <tremy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 17:53:32 by nbrabant          #+#    #+#              #
#    Updated: 2023/09/02 17:51:06 by tremy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	fractol

FLAG 		= 	-Wall -Werror -Wextra mlx_linux/libmlx.a -lXext -lX11 -lm -lbsd

SRC			=	$(shell ls *.c)

LIBFT 		=   $(shell ls libft/*.c)

OBJ			=	$(LIBFT:.c=.o) $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C mlx_linux
	make -C libft
	gcc -Wall -Wextra -Werror $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
		rm -f $(OBJ)
		make -s -C libft clean

fclean: clean
		rm -f $(NAME)
		make -s -C libft fclean

re:		fclean all
