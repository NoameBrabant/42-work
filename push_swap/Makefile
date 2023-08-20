# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 17:53:32 by nbrabant          #+#    #+#              #
#    Updated: 2023/08/20 17:05:00 by nbrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap.a

NAME_BONUS	=	checker.a

DIR			=	libft/

FLAG 		= 	-Wall -Werror -Wextra -g

GNL			=	$(shell ls get_next_line/*.c)

LIBFT 		=   $(shell ls libft/*.c)

P_S			=	$(shell ls pushswap/*.c)

CHECKER		=	bonus/checker.c 		\
				pushswap/moves.c 		\
				pushswap/linked_list.c	\
				pushswap/lst_utils.c	\
				pushswap/lst_utils2.c	\
				pushswap/parsing.c 		\
				pushswap/moves2.c 		\
				$(shell ls libft/*.c)

OBJ			=	$(LIBFT:.c=.o) $(P_S:.c=.o)

OBJ_BONUS	=	$(GNL:.c=.o) $(CHECKER:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft
		gcc $(FLAG) $(OBJ) -o push_swap

bonus:	$(OBJ_BONUS) $(NAME)
		gcc $(FLAG) $(OBJ_BONUS) -o checker

.c.o:
		gcc $(FLAG) -c $< -o $(<:.c=.o)
	
clean:
		rm -f $(OBJ)
		make -s -C libft clean
		rm -f $(OBJ_BONUS)

fclean: clean
		make -s -C libft fclean
		rm -f $(NAME)
		rm -f push_swap
		rm -f checker

re:		fclean all
