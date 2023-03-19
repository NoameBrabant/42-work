/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:37:22 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/06 13:32:37 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tab;
	size_t	i;

	tab = (char *) s;
	i = 0;
	while (i < n)
	{
		if (tab[i] == (char) c)
			return ((void *) s + i);
		i++;
	}
	return (NULL);
}
