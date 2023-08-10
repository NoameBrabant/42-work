/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:00:30 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/06 12:54:03 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

node_t	*create_linked_list(int size, int *numbers)
{
	node_t	*head;
	node_t	*current;
	node_t	*temp;
	int 	i;

	i = 0;
	head = NULL;
	current = NULL;
	temp = NULL;

	while(numbers[i])
	{
		ft_printf("ici");
		ft_printf("%d", numbers[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		temp = malloc(sizeof(node_t));
		temp->index = i;
		temp->value = numbers[i++];
		temp->next = NULL; 
		if (head == NULL)
			head = temp;
		else
		{
			current = head;
			while (current->next != NULL)
				current = current->next;
			current->next = temp;
		}
	}
	return (head);	
}
 
void	print_linked_list(node_t *head)
{
	node_t	*current;
	current = head;
	while (current->next != NULL)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("%d ", current->value);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	
	char str[] = "Hello world";
	//int	i;

	//i = 1;
	printf("uwu %s uwu \n", str);
	/*while (argv[0][i])
	{
		ft_printf("%s", argv[0][i]);
		i++;
	}*/
	numbers = create_list_numbers(argc - 1, argv);
	print_linked_list(create_linked_list(argc - 1, numbers));	
}	