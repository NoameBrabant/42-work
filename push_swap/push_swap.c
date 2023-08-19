
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:00:30 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/12 16:45:23 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	node_t	**stack_table;

	if (argc == 1)
		ft_error();
	numbers = ft_create_list_numbers(argc, argv);
	stack_table = ft_calloc(3, sizeof(node_t));
	stack_table[0] = create_linked_list(numbers);
	if (ft_check_init(stack_table))
	{
		ft_free_lst(stack_table, 1);
		return (0);
	}
	stack_table = lst_init_b(stack_table);
	stack_table = ft_fill_b(stack_table);
	stack_table = ft_fill_a(stack_table);
	/* ft_print_linked_list(stack_table[0]); */
	ft_free_lst(stack_table, 1);
	return (0);
}

