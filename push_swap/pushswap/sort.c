/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:08:52 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 18:09:35 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_path(int pos_a, int pos_b, t_node **s_table)
{
	int	cc;
	int	mvc;
	int	i;

	i = 1;
	mvc = ft_both_up(pos_a, pos_b);
	if (mvc == 0)
		return (0);
	cc = ft_both_down(pos_a, pos_b, s_table);
	if (mvc > cc)
		i = 2;
	if (mvc > cc)
		mvc = cc;
	cc = ft_up_a(pos_a, pos_b, s_table);
	if (mvc > cc)
		i = 3;
	if (mvc > cc)
		mvc = cc;
	cc = ft_up_b(pos_a, pos_b, s_table);
	if (mvc > cc)
		i = 4;
	if (mvc > cc)
		mvc = cc;
	return (i);
}

t_node	**ft_fill_b(t_node **s)
{
	int		y;
	t_node	*b;
	t_node	*a;

	while (ft_lst_size(s[0]) > 3)
	{
		a = ft_compare(s);
		b = lst_finder(s[1], ft_pos_b(a->value, s[1]));
		y = ft_path(pos_finder(s[0], a->value), pos_finder(s[1], b->value), s);
		s = ft_pattern_manager(a, b, s, y);
	}
	s[0] = lst_sort_a(s);
	return (s);
}
