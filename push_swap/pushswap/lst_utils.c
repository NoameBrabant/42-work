/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:34:30 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 17:31:31 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lst_size(t_node	*head)
{
	t_node	*current;
	int		size;

	current = head;
	size = 0;
	while (current->next != head)
	{
		size++;
		current = current->next;
	}
	size++;
	return (size);
}

void	ft_print_linked_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current->next != head)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("%d\n", current->value);
}

int	ft_issort(t_node *head)
{
	t_node	*current;

	current = head;
	while (current->next != head)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next; 
	}
	return (1);
}
