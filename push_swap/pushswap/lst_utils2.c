/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:14:55 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/04 14:01:48 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_lst(t_node **s_table, int toggle)
{
	t_node	*current;
	t_node	*temp;
	int		i;

	i = 0;
	while (s_table[i])
	{
		current = s_table[i]->next;
		while (current != s_table[i])
		{
			temp = current->next;
			free(current);
			current = temp;
		}
		free(s_table[i]);
		i++;
	}
	free(s_table);
	if (toggle == 0)
		ft_error();
}

int	ft_lst_max(t_node *head)
{
	t_node	*current;
	int		max;

	max = INT_MIN;
	current = head;
	while (current->next != head)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	if (current->value > max)
		max = current->value;
	return (max);
}

int	ft_lst_min(t_node *head)
{
	t_node	*current;
	int		min;

	min = INT_MAX;
	current = head;
	while (current->next != head)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	if (current->value < min)
		min = current->value;
	return (min);
}

int	ft_lst_find_min(t_node *head, int min)
{
	t_node	*current;
	int		count;

	count = 1;
	current = head;
	while (current->next != head)
	{
		if (current->value == min)
			return (count + 1);
		current = current->next;
		count++;
	}
	return (count + 1);
}

int	ft_lst_find_max(t_node *head, int max)
{
	t_node	*current;
	int		count;

	count = 1;
	current = head;
	while (current->next != head)
	{
		if (current->value == max)
			return (count);
		current = current->next;
		count++;
	}
	return (count);
}
