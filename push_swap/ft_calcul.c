/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:31:23 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/16 14:50:49 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_both_up(int pos_a, int pos_b)
{
	if (pos_a == pos_b && pos_a == 1)
		return (0);
	else if (pos_a >= pos_b)
		return (pos_a);
	else
		return (pos_b);
}

int	ft_both_down(int pos_a, int pos_b, node_t **s_table)
{
	pos_b = ft_lst_size(s_table[1]) - pos_b + 2;
	pos_a = ft_lst_size(s_table[0]) - pos_a + 2;
	if (pos_a >= pos_b)
		return (pos_a);
	else
		return (pos_b);
}

int	ft_up_a(int a, int b, node_t **s_table)
{
	int	cc;
	int b_size;

	b_size = ft_lst_size(s_table[1]); 
	cc = a + b_size - b + 1;
	return (cc);
}

int	ft_up_b(int a, int b, node_t **s_table)
{
	int	cc;
	int	a_size;

	a_size = ft_lst_size(s_table[0]);
	cc = b + a_size - a + 1;
	return (cc);
}