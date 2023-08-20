/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:00:30 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 18:10:13 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	t_node	**stack_table;

	if (argc == 1)
		ft_error();
	numbers = ft_create_list_numbers(argc, argv);
	stack_table = ft_calloc(3, sizeof(t_node));
	stack_table[0] = create_linked_list(numbers);
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
