/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:29:16 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/20 12:33:42 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*bufferdest;
	char	*buffersrc;
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	buffersrc = (char *) src;
	bufferdest = (char *) dest;
	while (i < n)
	{
		bufferdest[i] = buffersrc[i];
		i++;
	}
	return (dest);
}
