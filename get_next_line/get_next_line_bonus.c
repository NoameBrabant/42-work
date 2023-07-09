/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:18:16 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/27 16:15:59 by nbrabant         ###   ########.fr       */
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
	while (!ft_strchr(stash, '\n') && nbr != 0)
	{
		nbr = read(fd, buff, BUFFER_SIZE);
		if (nbr == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbr] = '\0';
		stash = ft_strjoin(stash, buff);
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
	new = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
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
	static char	*stash[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(BUFFER_SIZE);
		stash[fd][0] = '\0';
	}
	stash[fd] = readnextline(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	res = putnextline(stash[fd]);
	stash[fd] = restnextline(stash[fd]);
	return (res);
}
