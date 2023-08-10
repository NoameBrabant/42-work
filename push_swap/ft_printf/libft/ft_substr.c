/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:50:21 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/22 11:00:58 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	y;

	y = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		new = ft_calloc(1, sizeof(char));
		return (new);
	}
	while (s[start + y] && y < len)
		y++;
	new = ft_calloc(y + 1, sizeof(char));
	if (!new)
		return (NULL);
	y = 0;
	while (s[start + y] && y < len)
	{
		new[y] = s[start + y];
		y++;
	}
	return (new);
}
