/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:09:46 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/02 15:22:28 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*buffer;

	i = 0;
	buffer = (char *) s;
	while (i < n)
	{
		buffer[i] = c;
		i++;
	}
	return (s);
}
