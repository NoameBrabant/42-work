/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:15:09 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/16 19:26:06 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

node_t	*create_linked_list(int *numbers)
{
	node_t	*head;
	node_t	*current;
	node_t	*temp;
	int 	i;

	i = 1;
	current = NULL;
	temp = NULL;
	head = lst_init(numbers[0]);
	while (numbers[i])
	{
		current = malloc(sizeof(node_t));
		current->value = numbers[i++];
		if (head->next == NULL)
			temp = head;
		temp->next = current;
		current->previous = temp;
		temp = current;
	}
	if (head->next != NULL)
	{	
		head->previous = current;
		current->next = head;
	}
	free(numbers);
	return (head);
}

node_t	*lst_init(int first_value)
{
	node_t	*head;

	head = malloc(sizeof(node_t));
	head->value = first_value;
	head->next = NULL;
	head->previous = NULL;
	return (head);
}

node_t	**lst_init_b(node_t **s_table)
{
	node_t	*new_head;

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

