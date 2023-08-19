/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:42:19 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/16 14:53:17 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

node_t	**ft_pattern_manager(node_t *a, node_t *b, node_t **s_table, int i)
{
	if (i == 0)
	{
		s_table = push(s_table[0], s_table[1], s_table, 'b');
		return (s_table);
	}
	else if (i == 1)
		s_table = ft_pattern_dblup(a, b, s_table);
	else if (i == 2)
		s_table = ft_pattern_dbldwn(a, b, s_table);
	else if (i == 3)
		s_table = ft_pattern_aup(a, b, s_table);
	else
		s_table = ft_pattern_bup(a, b, s_table);
	s_table = push(s_table[0], s_table[1], s_table, 'b');
	return (s_table);	
}

node_t **ft_pattern_dblup(node_t *a, node_t *b, node_t **s_table)
{
	while (a != s_table[0] && b != s_table[1])
		s_table = rota(s_table, 'r');
	if (a == s_table[0])
	{
		while(b != s_table[1])
			s_table = rota(s_table, 'b'); 
	}
	else
	{
		while(a != s_table[0])
			s_table = rota(s_table, 'a');
	}
	return (s_table);
}

node_t **ft_pattern_dbldwn(node_t *a, node_t *b, node_t **s_table)
{
	while (a != s_table[0] && b != s_table[1])
		s_table = rev_rota(s_table, 'r');
	if (a == s_table[0])
	{
		while(b != s_table[1])
			s_table = rev_rota(s_table, 'b'); 
	}
	else
	{
		while(a != s_table[0])
			s_table = rev_rota(s_table, 'a');
	}
	return (s_table);
}

node_t **ft_pattern_aup(node_t *a, node_t *b, node_t **s_table)
{
	while (a != s_table[0])
		s_table = rota(s_table, 'a');
	while(b != s_table[1])
		s_table = rev_rota(s_table, 'b');
	return (s_table);
}

node_t **ft_pattern_bup(node_t *a, node_t *b, node_t **s_table)
 {
	while (b != s_table[1])
		s_table = rota(s_table, 'b');
	while(a != s_table[0])
		s_table = rev_rota(s_table, 'a');
	return (s_table);
}