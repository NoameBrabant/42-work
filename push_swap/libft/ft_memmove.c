/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:29:16 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/20 14:29:57 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*bufferdest;
	char	*buffersrc;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	buffersrc = (char *) src;
	bufferdest = (char *) dest;
	if (dest > src)
	{
		i = n;
		while (i-- > 0)
			bufferdest[i] = buffersrc[i];
	}
	else
	{
		i = 0;
		while (i++ < n)
			bufferdest[i - 1] = buffersrc[i - 1];
	}
	return (dest);
}
