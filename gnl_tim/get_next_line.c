/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:38:10 by tremy             #+#    #+#             */
/*   Updated: 2023/06/23 12:00:04 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char *stash)
{
	char	*str;
	int		i;

	if (ft_strchr(stash, '\n') == NULL)
	{
		free(stash);
		return (NULL);
	}
	else
	{
		i = ft_strchr(stash, '\n') - stash;
		str = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	}
	free(stash);
	return (str);
}

char	*ft_fill(char *stash)
{
	char	*str;
	size_t	i;

	if (!stash)
		return (NULL);
	i = ft_strlen(stash);
	if (ft_strchr(stash, '\n') == NULL)
		str = ft_substr(stash, 0, i);
	else
	{
		i = ft_strchr(stash, '\n') - stash;
		str = ft_substr(stash, 0, i + 1);
	}
	return (str);
}

char	*ft_read_line(int fd, char *stash)
{
	int		i;
	char	*buffer;

	i = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			break ;
		buffer[i] = '\0';
		if (ft_strchr(buffer, '\n') != NULL)
			i = 0;
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	line = ft_fill(stash);
	stash = ft_clean(stash);
	if (!stash && line && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
