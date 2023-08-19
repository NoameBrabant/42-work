/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:45:36 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/07 14:07:26 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	tmp;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tmp = nmemb * size;
	if (tmp / size != nmemb)
		return (NULL);
	tab = malloc(tmp);
	if (!tab)
		return (NULL);
	ft_bzero(tab, tmp);
	return (tab);
}
