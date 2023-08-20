/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:08:18 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/20 18:29:37 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *str, char c)
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

int	ft_strlen_gnl(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *s, char *buff)
{
	char	*new;
	int		i;
	int		j;

	if (!s)
	{
		s = (char *)malloc(sizeof(char) * 1);
		s[0] = '\0';
	}
	if (!s || !buff)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen_gnl(buff) + ft_strlen_gnl(s) + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			new[i] = s[i];
	while (buff[j] != '\0')
		new[i++] = buff[j++];
	new[ft_strlen_gnl(buff) + ft_strlen_gnl(s)] = '\0';
	free(s);
	return (new);
}
