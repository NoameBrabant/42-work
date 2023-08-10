/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:35:24 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/20 12:32:58 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	int		trigger;

	if (!lst)
		return ;
	trigger = 0;
	while (*lst)
	{
		tmp = (*lst)->next;
		if (trigger == 0)
		{
			trigger = 1;
			(*lst)->next = NULL;
		}
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
