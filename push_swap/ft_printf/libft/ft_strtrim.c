/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:19:53 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/20 12:38:38 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	y;
	char			*new;

	y = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(NULL));
	i = ft_strlen(s1);
	while (ft_strrchr(set, s1[i]) && i > y)
		i--;
	if (i == y)
		return (ft_calloc(1, sizeof(char)));
	while (ft_strchr(set, s1[y]) && s1[y])
		y++;
	new = ft_calloc(i - y + 2, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1 + y, i - y + 2);
	return (new);
}
