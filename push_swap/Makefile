# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 17:53:32 by nbrabant          #+#    #+#              #
#    Updated: 2023/08/06 13:15:22 by nbrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap.a

DIR			=	libft/

FLAG 		= 	-Wall -Werror -Wextra

LIBFT 		=   ft_toupper.c		\
				ft_substr.c			\
				ft_strlcpy.c		\
				ft_memset.c			\
				ft_calloc.c			\
				ft_strlcat.c		\
				ft_memchr.c			\
				ft_memmove.c		\
				ft_strdup.c			\
				ft_isdigit.c		\
				ft_strlen.c			\
				ft_memcmp.c			\
				ft_strrchr.c		\
				ft_isalnum.c		\
				ft_atoi.c			\
				ft_memcpy.c			\
				ft_isalpha.c		\
				ft_strnstr.c		\
				ft_strchr.c			\
				ft_tolower.c		\
				ft_isprint.c		\
				ft_strncmp.c		\
				ft_bzero.c			\
				ft_isascii.c		\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_striteri.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_putnbr_base_fd.c	\
				ft_nbrlen.c			\
				ft_putaddress_fd.c	\
				ft_printf.c			\
				ft_lstnew.c 		\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\

SRC			=	parsing.c	\
				push_swap.c	\

OBJ			=	$(addprefix $(DIR), $(LIBFT:.c=.o)) $(SRC:.c=.o) 

all: $(NAME)

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
