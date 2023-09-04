/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:05:21 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/04 14:00:29 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcounter(char const *s, char c)
{
	int	i;
	int	trigger;
	int	word;

	word = 0;
	i = 0;
	trigger = 1;
	while (s[i])
	{
		if (s[i] == c && trigger == 0)
			trigger = 1;
		if (s[i] != c && trigger == 1)
		{
			word++;
			trigger = 0;
		}
		i++;
	}
	return (word);
}

static char	**ft_loop(unsigned int i, char const *s, char c, char **tab)
{
	unsigned int	y;
	unsigned int	pos;

	y = 0;
	while (s[i])
	{
		pos = i;
		while (s[i] != c && s[i])
			i++;
		if (pos != i)
		{
			tab[y] = ft_substr(s, pos, i - pos);
			if (!tab[y])
			{
				i = 0;
				while (i++ < y)
					free (tab[i]);
				return (NULL);
			}
			y++;
		}
		if (s[i])
			i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c, int *len)
{
	char			**tab;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	*len = wordcounter(s, c);
	tab = (char **)ft_calloc(*len + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab = ft_loop(i, s, c, tab);
	return (tab);
}
