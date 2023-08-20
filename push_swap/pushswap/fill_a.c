/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:28:22 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 18:00:34 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	**ft_fill_a(t_node **s_table)
{
	int		max_a;

	max_a = s_table[0]->previous->value;
	s_table = ft_sort_b(s_table);
	while (s_table[1] != NULL)
	{
		while (s_table[1] != NULL 
			&& ((max_a < s_table[1]->value
					&& s_table[1]->value < s_table[0]->value) 
				|| ((s_table[1]->value < ft_lst_min(s_table[0]) 
						&& s_table[0]->value == ft_lst_min(s_table[0])) 
					|| s_table[1]->value > ft_lst_max(s_table[0]))))
			s_table = push(s_table, 'a', 1);
		if (s_table[1] != NULL)
			s_table = rev_rota(s_table, 'a', 1);
		max_a = s_table[0]->previous->value;
	}
	if (!ft_issort(s_table[0]))
		s_table = ft_sort_end_a(s_table);
	return (s_table);
}

t_node	**ft_sort_b(t_node **s_table)
{
	int	max;
	int	max_pos;
	int	half_b;

	half_b = ft_lst_size(s_table[1]) / 2;
	max = ft_lst_max(s_table[1]);
	max_pos = ft_lst_find_max(s_table[1], max);
	if (half_b >= max_pos)
	{
		while (max != s_table[1]->value)
			s_table = rota(s_table, 'b', 1);
	}
	else
	{
		while (max != s_table[1]->value)
			s_table = rev_rota(s_table, 'b', 1);
	}
	return (s_table);
}

t_node	**ft_sort_end_a(t_node **s_table)
{
	int	min;
	int	min_pos;
	int	half_a;

	min = ft_lst_min(s_table[0]);
	half_a = ft_lst_size(s_table[0]) / 2;
	min_pos = ft_lst_find_min(s_table[0], min);
	if (half_a < min_pos)
	{
		while (min != s_table[0]->value)
			s_table = rev_rota(s_table, 'a', 1);
	}
	else
	{
		while (min != s_table[0]->value)
			s_table = rota(s_table, 'a', 1);
	}
	return (s_table);
}
