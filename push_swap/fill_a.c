/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:28:22 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/18 18:04:50 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

node_t	**ft_fill_a(node_t **s_table)
{
	int		max_a;

	max_a = s_table[0]->previous->value;
	s_table = ft_sort_b(s_table);
	while (s_table[1] != NULL)
	{	
		while (s_table[1] != NULL && ((max_a < s_table[1]->value && s_table[1]->value < s_table[0]->value) || ((s_table[1]->value < ft_lst_min(s_table[0]) && s_table[0]->value == ft_lst_min(s_table[0])) || s_table[1]->value > ft_lst_max(s_table[0]))))
			s_table = push(s_table[1], s_table[0], s_table, 'a');
		s_table = rev_rota(s_table, 'a');
		max_a = s_table[0]->previous->value;
	}
	if (!ft_issort(s_table[0]))
		s_table = ft_sort_end_a(s_table);
	return (s_table);
}

node_t	**ft_sort_b(node_t **s_table)
{
	int		max;
	int		half_b;

	half_b = ft_lst_size(s_table[1]) / 2;
	max = ft_lst_max(s_table[1]);
	if (half_b >= max)
	{
		while (max != s_table[1]->value)
			s_table = rota(s_table, 'b');
	}
	else
	{
		while (max != s_table[1]->value)
			s_table = rev_rota(s_table, 'b');
	}
	return (s_table);
}

node_t	**ft_sort_end_a(node_t **s_table)
{
	int		min;
	int		half_a;

	half_a = ft_lst_size(s_table[0]) / 2;
	min = ft_lst_min(s_table[0]);
	if (half_a <= min)
	{
		while (min != s_table[0]->value)
			s_table = rev_rota(s_table, 'a');
	}
	else
	{
		while (min != s_table[0]->value)
			s_table = rota(s_table, 'a');
	}
	return (s_table);
}