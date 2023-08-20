/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:24:15 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 18:09:06 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*lst_finder(t_node *head, int value)
{
	t_node	*current;
	int		i;

	i = 1;
	current = head;
	while (i != value)
	{
		i++;
		current = current->next;
	}
	return (current);
}

t_node	*lst_sort_a(t_node **s_table)
{
	int		min;
	int		max;

	min = ft_lst_find_min(s_table[0], ft_lst_min(s_table[0]));
	max = ft_lst_find_max(s_table[0], ft_lst_max(s_table[0]));
	if (max - min == 0 || (max == 1 && min == 4))
		s_table[0] = swap(s_table[0], 'a', 1);
	min = ft_lst_find_min(s_table[0], ft_lst_min(s_table[0]));
	if (min == 3)
		s_table = rota(s_table, 'a', 1);
	else if (min == 4)
		s_table = rev_rota(s_table, 'a', 1);
	return (s_table[0]);
}

int	pos_finder(t_node *head, int value)
{
	t_node	*current;
	int		i;

	i = 1;
	current = head;
	while (current->value != value)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	ft_check_init(t_node **stack_table)
{
	if (ft_issort(stack_table[0]))
		return (1);
	else if (ft_lst_size(stack_table[0]) == 2)
	{
		if (stack_table[0]->value > stack_table[0]->next->value)
			stack_table = rota(stack_table, 'a', 1);
		return (1);
	}
	else if (ft_lst_size(stack_table[0]) == 3)
	{
		stack_table[0] = lst_sort_a(stack_table);
		return (1);
	}
	return (0);
}
