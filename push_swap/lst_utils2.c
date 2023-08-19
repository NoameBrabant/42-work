/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:14:55 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/16 11:00:09 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_lst(node_t **s_table, int toggle)
{
	node_t *current;
	node_t *temp;
	int 	i;

	i = 0;
	while  (s_table[i])
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

int ft_lst_max (node_t *head)
{
	node_t	*current;
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

int ft_lst_min (node_t *head)
{
	node_t	*current;
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

int	ft_lst_find_min(node_t *head, int min)
{
	node_t	*current;
	int 	count;

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

int	ft_lst_find_max(node_t *head, int max)
{
	node_t	*current;
	int 	count;

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