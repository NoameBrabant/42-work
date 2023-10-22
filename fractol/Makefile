# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tremy <tremy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 17:53:32 by nbrabant          #+#    #+#              #
#    Updated: 2023/10/06 13:42:41 by tremy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	fractol

FLAG 		= 	-Wall -Werror -Wextra -g

MLX_FLAG	=	-Lmlx_linux -lmlx_Linux -Imlx_linux -lX11 -lm -lz -lbsd -lXext

SRC			=	$(shell ls *.c)

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C mlx_linux
	gcc $(FLAG) $(OBJ) $(MLX_FLAG) -L/usr/lib -o $(NAME)

%.o: %.c
	gcc $(FLAG) $(MLX_FLAG) -I/usr/include -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
