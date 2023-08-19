/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:08:52 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/16 15:51:37 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_pathfinder(int pos_a, int pos_b, node_t **s_table)
{
	int cc;
	int mvc;
	int	i;

	i = 1;
	mvc = ft_both_up(pos_a, pos_b);
	if (mvc == 0)
		return (0);
	cc = ft_both_down(pos_a, pos_b, s_table);
	if (mvc > cc)
	{
		mvc = cc;
		i = 2;
	}
	cc = ft_up_a(pos_a,  pos_b, s_table);
	if (mvc > cc)
	{
		mvc = cc;
		i = 3;
	}
	cc = ft_up_b(pos_a,  pos_b, s_table);
	if (mvc > cc)
	{
		mvc = cc;
		i = 4;
	}
	return (i);
}

node_t **ft_fill_b(node_t **s_table)
{
	int		the_way;
	node_t	*pos_b;
	node_t	*pos_a;


	while (ft_lst_size(s_table[0]) > 3)
	{
		pos_a = ft_compare(s_table);
		pos_b = lst_finder(s_table[1], ft_pos_b(pos_a->value, s_table[1]));
		the_way = ft_pathfinder(lst_pos_finder(s_table[0], pos_a->value), lst_pos_finder(s_table[1], pos_b->value), s_table);
		s_table = ft_pattern_manager(pos_a, pos_b, s_table, the_way);
	}
	s_table[0] = lst_sort_a(s_table);
	return (s_table);
}