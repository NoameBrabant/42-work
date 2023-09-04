/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:15:09 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/04 14:00:26 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*create_linked_list(int *numbers, int len)
{
	t_node	*head;
	t_node	*current;
	t_node	*temp;
	int		i;

	i = 1;
	current = NULL;
	temp = NULL;
	head = lst_init(numbers[0]);
	while (i < len)
	{
		current = malloc(sizeof(t_node));
		current->value = numbers[i++];
		if (head->next == NULL)
			temp = head;
		temp->next = current;
		current->previous = temp;
		temp = current;
	}
	if (head->next != NULL)
		current->next = head;
	if (head->next != NULL)
		head->previous = current;
	free(numbers);
	return (head);
}

t_node	*lst_init(int first_value)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	head->value = first_value;
	head->next = NULL;
	head->previous = NULL;
	return (head);
}

t_node	**lst_init_b(t_node **s_table)
{
	t_node	*new_head;

	new_head = s_table[0]->next->next;
	s_table[0]->previous->next = new_head;
	new_head->previous = s_table[0]->previous;
	s_table[0]->previous = s_table[0]->next;
	s_table[0]->next->next = s_table[0];
	s_table[1] = s_table[0]->next;
	s_table[0] = new_head;
	ft_printf("pb\npb\n");
	return (s_table);
}
