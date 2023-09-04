/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:18:16 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/04 12:02:47 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readnextline(int fd, char *stash)
{
	char	*buff;
	int		nbr;

	buff = malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!buff)
		return (NULL);
	nbr = 1;
	while (!ft_strchr_gnl(stash, '\n') && nbr != 0)
	{
		nbr = read(fd, buff, BUFFER_SIZE);
		if (nbr == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbr] = '\0';
		stash = ft_strjoin_gnl(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*putnextline(char *stash)
{
	char	*new;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	new = (char *)malloc((i + 2) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		new[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		new[i] = stash[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*restnextline(char *stash)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen_gnl(stash) - i + 1));
	if (!new)
		return (NULL);
	j = 0;
	i++;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(BUFFER_SIZE);
		stash[0] = '\0';
	}
	stash = readnextline(fd, stash);
	if (!stash)
		return (NULL);
	res = putnextline(stash);
	stash = restnextline(stash);
	return (res);
}
