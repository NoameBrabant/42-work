/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:00:30 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/04 15:57:26 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	int		len;
	t_node	**stack_table;

	if (argc == 1)
		exit(0);
	else if (argc == 2)
		len = 1;
	else
		len = argc - 1;
	numbers = ft_create_list_numbers(&len, argv, 0);
	if (len == 1)
		exit(0);
	stack_table = ft_calloc(3, sizeof(t_node));
	stack_table[0] = create_linked_list(numbers, len);
	if (ft_check_init(stack_table))
	{
		ft_free_lst(stack_table, 1);
		return (0);
	}
	stack_table = lst_init_b(stack_table);
	stack_table = ft_fill_b(stack_table);
	stack_table = ft_fill_a(stack_table);
	ft_free_lst(stack_table, 1);
	return (0);
}
