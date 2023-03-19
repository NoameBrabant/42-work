/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:26:44 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/20 11:49:09 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;
	size_t	z;

	i = 0;
	y = ft_strlen(src);
	z = 0;
	if (size == 0)
		return (y);
	while (dst[z] != 0 && z < size)
		z++;
	while (z + i < size - 1 && src[i] != 0 && size > 1)
	{
		dst[z + i] = src[i];
		i++;
	}
	if (z + i < size)
		dst[i + z] = 0;
	return (y + z);
}
