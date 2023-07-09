/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:08:18 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/27 15:18:34 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[0]);
	while (str[i] != '\0')
	{
		if (c == str[i])
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*new;
	int		i;
	int		j;

	if (!stash)
	{
		stash = (char *)malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(stash) + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stash)
		while (stash[++i] != '\0')
			new[i] = stash[i];
	while (buff[j] != '\0')
			new[i++] = buff[j++];
	new[ft_strlen(buff) + ft_strlen(stash)] = '\0';
	free(stash);
	return (new);
}
