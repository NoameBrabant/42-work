/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:09:30 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/20 12:37:19 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == ((unsigned char) c))
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)s[i] == ((unsigned char) c))
		return ((char *)s + i);
	return (0);
}
