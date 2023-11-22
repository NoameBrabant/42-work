/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:24:24 by tremy             #+#    #+#             */
/*   Updated: 2023/06/22 18:08:12 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	l;

	if (!s)
		return (NULL);
	l = 0;
	while (s[l])
	{
		if (s[l] == c)
			return ((char *) &s[l]);
		l++;
	}
	if (c == 0)
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	length;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (ft_strlen(s) < start || len == 0)
	{
		tab = malloc(1 * sizeof(char));
		tab[0] = '\0';
		return (tab);
	}
	while (s[start + i] && i < len)
		i++;
	tab = malloc(sizeof(char) * i + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
