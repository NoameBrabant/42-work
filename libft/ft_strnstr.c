/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:44:08 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/20 14:30:34 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (little[0] == 0)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		y = 0;
		while (big[i + y] == little[y] && (i + y) < len)
		{
			if (little[y + 1] == 0)
				return ((char *)(big + i));
			y++;
		}
		i++;
	}
	return (NULL);
}
