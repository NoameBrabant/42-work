/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:29:58 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/01 12:44:47 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int	*create_list_numbers(int size_input, char **input);
int	*addnumbers(char *input);
int	get_length(char **str);



typedef struct node
{
	int value;
	int index;
	struct node * next;
} node_t;

#endif