# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 17:53:32 by nbrabant          #+#    #+#              #
#    Updated: 2023/08/12 14:41:52 by nbrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap.a

DIR			=	libft/

FLAG 		= 	-Wall -Werror -Wextra -g

LIBFT 		=   $(shell ls libft/*.c)

SRC			=	$(shell ls *.c)

OBJ			=	$(LIBFT:.c=.o) $(SRC:.c=.o) 

all: $(NAME)

view:
	echo $(LIBFT)

$(NAME): $(OBJ)
		make -C libft
		gcc $(FLAG) $(OBJ) -o push_swap

.c.o:
		gcc $(FLAG) -c $< -o $(<:.c=.o)
	
clean:
		rm -f $(OBJ)
		make -s -C libft clean

fclean: clean
		make -s -C libft fclean
		rm -f $(NAME)
		rm -f push_swap

re:		fclean all
