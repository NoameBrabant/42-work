/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:34:00 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/16 14:11:06 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

node_t	*swap(node_t *head, char stack)
{
	node_t	*last;
	node_t	*third;
	node_t	*new_head;

	last = head->previous;
	third = head->next->next;
	new_head = head->next;
	new_head->previous = last;
	new_head->next = head;
	head->next = third;
	head->previous = new_head;
	last->next =new_head;
	third->previous = head;
	if (stack != 'r')
		ft_printf("s%c\n", stack);
	return (new_head);
}

node_t	**ss(node_t **s_table)
{
	s_table[0] = swap(s_table[0], 'r');
	s_table[1] = swap(s_table[1], 'r');
	ft_printf("rr\n");
	return (s_table);
}

node_t	**push(node_t *src_h, node_t *rec_h, node_t **s_table, char stack)
{
	node_t	*temp;
	node_t 	*new_head_src;
	node_t 	*new_head_rec;

	if (ft_lst_size(s_table[1]) == 1)
	{
		s_table[1]->next = rec_h;
		s_table[1]->previous = rec_h->previous;
		s_table[1]->previous->next = s_table[1];
		rec_h->previous = s_table[1];
		s_table[0] = s_table[1];
		s_table[1] = NULL;
		ft_printf("pa\n");
		return (s_table);
	}
	temp = rec_h->previous;
	src_h->previous->next = src_h->next;
	src_h->next->previous = src_h->previous;
	new_head_src = src_h->next;
	rec_h->previous->next = src_h;
	rec_h->previous = src_h;
	src_h->next = rec_h;
	src_h->previous = temp;
	new_head_rec = src_h;
	if (src_h == s_table[1])	
	{	
		s_table[1] = new_head_src;
		s_table[0] = new_head_rec;
	}
	else
	{	
		s_table[0] = new_head_src;
		s_table[1] = new_head_rec;
	}
	ft_printf("p%c\n", stack);
	return (s_table);
}

node_t	**rota(node_t **s_table, char stack)
{
	if (stack == 'a')
		s_table[0] = s_table[0]->next;
	else if (stack == 'b')
		s_table[1] = s_table[1]->next;
	else if (stack == 'r')
	{
		s_table[0] = s_table[0]->next;
		s_table[1] = s_table[1]->next;	
	}
	ft_printf("r%c\n", stack);
	return (s_table);
}

node_t	**rev_rota(node_t **s_table, char stack)
{
	if (stack == 'a')
		s_table[0] = s_table[0]->previous;
	else if (stack == 'b')
		s_table[1] = s_table[1]->previous;
	else if (stack == 'r')
	{
		s_table[0] = s_table[0]->previous;
		s_table[1] = s_table[1]->previous;
	}
	ft_printf("rr%c\n", stack);
	return (s_table);
}