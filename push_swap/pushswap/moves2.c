/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:36:19 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 17:53:49 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	**push1(t_node *src_h, t_node **s_table, char s, int t)
{
	src_h->previous->next = src_h->next;
	src_h->next->previous = src_h->previous;
	s_table[1] = s_table[0];
	s_table[0] = src_h->next;
	s_table[1]->previous = s_table[1];
	s_table[1]->next = s_table[1];
	if (t == 1)
		ft_printf("p%c\n", s);
	return (s_table);
}

t_node	**push2(t_node *rec_h, t_node **s_table, int t)
{
	s_table[1]->next = rec_h;
	s_table[1]->previous = rec_h->previous;
	s_table[1]->previous->next = s_table[1];
	rec_h->previous = s_table[1];
	s_table[0] = s_table[1];
	s_table[1] = NULL;
	if (t == 1)
		ft_printf("pa\n");
	return (s_table);
}

t_node	**push3(t_node *rec_h, t_node *src_h, t_node **s_table)
{
	t_node	*temp;
	t_node	*new_head_rec;
	t_node	*new_head_src;

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
	return (s_table);
}
