/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:08:30 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 17:53:02 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*ft_compare(t_node **s_table)
{
	int		cc;
	int		pos_a;
	int		mvc;
	t_node	*current;
	t_node	*mvn;

	mvc = INT_MAX;
	current = s_table[0];
	pos_a = 1;
	while (current->next != s_table[0])
	{
		cc = ft_calcul(current->value, pos_a, s_table);
		if (mvc > cc)
			mvn = current;
		if (mvc > cc)
			mvc = cc;
		current = current->next;
		pos_a++;
	}
	cc = ft_calcul(current->value, pos_a, s_table);
	if (mvc > cc)
		mvn = current;
	if (mvc > cc)
		mvc = cc;
	return (mvn);
}

int	ft_calcul(int cv, int pos_a, t_node **s_table)
{
	int	pos_b;
	int	cc;
	int	mvc;

	pos_b = ft_pos_b(cv, s_table[1]);
	mvc = ft_both_up(pos_a, pos_b);
	cc = ft_both_down(pos_a, pos_b, s_table);
	if (mvc > cc)
		mvc = cc;
	cc = ft_up_a(pos_a, pos_b, s_table);
	if (mvc > cc)
		mvc = cc;
	cc = ft_up_b(pos_a, pos_b, s_table);
	if (mvc > cc)
		mvc = cc;
	return (mvc);
}

int	ft_pos_b(int cv, t_node *head_b)
{
	t_node	*current;
	int		pos_b;
	int		max;
	int		min;

	max = ft_lst_max(head_b);
	min = ft_lst_min(head_b);
	pos_b = 1;
	current = head_b;
	if (cv > max)
		return (ft_lst_find_max(head_b, max));
	if (cv < min)
		return (ft_lst_find_min(head_b, min));
	while (current->next != head_b)
	{
		if (current->previous->value > cv && current->value < cv)
			return (pos_b);
		current = current->next;
		pos_b++;
	}
	return (pos_b);
}
