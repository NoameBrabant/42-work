/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:42:19 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 17:46:14 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	**ft_pattern_manager(t_node *a, t_node *b, t_node **s_table, int i)
{
	if (i == 0)
	{
		s_table = push(s_table, 'b', 1);
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
	s_table = push(s_table, 'b', 1);
	return (s_table);
}

t_node	**ft_pattern_dblup(t_node *a, t_node *b, t_node **s_table)
{
	while (a != s_table[0] && b != s_table[1])
		s_table = rota(s_table, 'r', 1);
	if (a == s_table[0])
	{
		while (b != s_table[1])
			s_table = rota(s_table, 'b', 1); 
	}
	else
	{
		while (a != s_table[0])
			s_table = rota(s_table, 'a', 1);
	}
	return (s_table);
}

t_node	**ft_pattern_dbldwn(t_node *a, t_node *b, t_node **s_table)
{
	while (a != s_table[0] && b != s_table[1])
		s_table = rev_rota(s_table, 'r', 1);
	if (a == s_table[0])
	{
		while (b != s_table[1])
			s_table = rev_rota(s_table, 'b', 1); 
	}
	else
	{
		while (a != s_table[0])
			s_table = rev_rota(s_table, 'a', 1);
	}
	return (s_table);
}

t_node	**ft_pattern_aup(t_node *a, t_node *b, t_node **s_table)
{
	while (a != s_table[0])
		s_table = rota(s_table, 'a', 1);
	while (b != s_table[1])
		s_table = rev_rota(s_table, 'b', 1);
	return (s_table);
}

t_node	**ft_pattern_bup(t_node *a, t_node *b, t_node **s_table)
{
	while (b != s_table[1])
		s_table = rota(s_table, 'b', 1);
	while (a != s_table[0])
		s_table = rev_rota(s_table, 'a', 1);
	return (s_table);
}
