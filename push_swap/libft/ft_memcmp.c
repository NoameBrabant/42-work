/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:32:26 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/06 14:47:34 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tab;
	unsigned char	*tab2;
	size_t			i;

	tab = (unsigned char *) s1;
	tab2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (tab[i] != tab2[i])
			return ((int)(tab[i] - tab2[i]));
		i++;
	}
	return (0);
}
