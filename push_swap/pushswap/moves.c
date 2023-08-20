/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:34:00 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 17:19:06 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*swap(t_node *head, char stack, int toggle)
{
	t_node	*last;
	t_node	*third;
	t_node	*new_head;

	last = head->previous;
	third = head->next->next;
	new_head = head->next;
	new_head->previous = last;
	new_head->next = head;
	head->next = third;
	head->previous = new_head;
	last->next = new_head;
	third->previous = head;
	if (stack != 'r' && toggle == 1)
		ft_printf("s%c\n", stack);
	return (new_head);
}

t_node	**ss(t_node **s_table, int toggle)
{
	s_table[0] = swap(s_table[0], 'r', toggle);
	s_table[1] = swap(s_table[1], 'r', toggle);
	if (toggle == 1)
		ft_printf("rr\n");
	return (s_table);
}

t_node	**push(t_node **s_table, char s, int t)
{
	t_node	*src_h;
	t_node	*rec_h;

	if (s == 'a')
	{
		src_h = s_table[1];
		rec_h = s_table[0];
	}
	else if (s == 'b')
	{
		rec_h = s_table[1];
		src_h = s_table[0];
	}
	if (s_table[1] == NULL)
		return (push1(src_h, s_table, 'b', t));
	else if (ft_lst_size(s_table[1]) == 1 && s == 'a')
		return (push2(rec_h, s_table, t));
	s_table = push3(rec_h, src_h, s_table);
	if (t == 1)
		ft_printf("p%c\n", s);
	return (s_table);
}

t_node	**rota(t_node **s_table, char stack, int toggle)
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
	if (toggle == 1)
		ft_printf("r%c\n", stack);
	return (s_table);
}

t_node	**rev_rota(t_node **s_table, char stack, int toggle)
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
	if (toggle == 1)
		ft_printf("rr%c\n", stack);
	return (s_table);
}
