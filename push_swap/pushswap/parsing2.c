/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:02:12 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/04 16:07:33 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_tab(char **tab, int toggle)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	if (toggle == 1)
		ft_error();
}

int	ft_is_zero(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
