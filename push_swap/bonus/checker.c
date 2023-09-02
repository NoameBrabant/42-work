/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:42:21 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/02 12:29:21 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	**makemoves2(char *str, t_node **s_table)
{
	if (ft_strncmp(str, "rb\n", 3) == 0 && s_table[1])
		s_table = rota(s_table, 'b', 0);
	else if (ft_strncmp(str, "rr\n", 3) == 0 && s_table[1])
		s_table = rota(s_table, 'r', 0);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		s_table = rev_rota(s_table, 'a', 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0 && s_table[1])
		s_table = rev_rota(s_table, 'b', 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0 && s_table[1])
		s_table = rev_rota(s_table, 'r', 0);
	else
	{
		free(str);
		ft_free_lst(s_table, 0);
	}
	return (s_table);
}

t_node	**makemoves(char *str, t_node **s_table)
{
	if (ft_strncmp(str, "pa\n", 3) == 0 && s_table[1])
		s_table = push(s_table, 'a', 0);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		s_table = push(s_table, 'b', 0);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		s_table[0] = swap(s_table[0], 'a', 0);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		s_table[1] = swap(s_table[1], 'b', 0);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		s_table = ss(s_table, 0);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		s_table = rota(s_table, 'a', 0);
	else
		s_table = makemoves2(str, s_table);
	free(str);
	return (s_table);
}

t_node	**ft_init_checker(int argc, char **argv)
{
	int		*numbers;
	t_node	**stack_table;
	int		len;

	if (argc == 2)
		len = 1;
	else
		len = argc - 1;
	numbers = ft_create_list_numbers(&len, argv);
	stack_table = ft_calloc(3, sizeof(t_node));
	stack_table[0] = create_linked_list(numbers, len);
	stack_table[1] = NULL;
	return (stack_table);
}

int	main(int argc, char **argv)
{
	char	*current;
	t_node	**stack_table;

	if (argc == 1)
		exit(0);
	stack_table = ft_init_checker(argc, argv);
	current = get_next_line(0);
	while (current)
	{
		stack_table = makemoves(current, stack_table);
		current = get_next_line(0);
	}
	if (stack_table[1] || !ft_issort(stack_table[0]))
	{
		ft_free_lst(stack_table, 42);
		ft_printf("KO");
		return (0);
	}
	ft_free_lst(stack_table, 1);
	ft_printf("OK");
	return (0);
}
