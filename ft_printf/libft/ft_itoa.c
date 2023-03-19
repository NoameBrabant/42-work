/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:12:56 by nbrabant          #+#    #+#             */
/*   Updated: 2023/02/11 18:38:39 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	lenght(int n)
{
	int				l;
	unsigned int	num;

	l = 0;
	if (n < 0)
	{
		num = -n;
		l++;
	}
	else
		num = n;
	while (num >= 10)
	{
		l++;
		num = num / 10;
	}
	return (l + 1);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	int				i;
	unsigned int	num;

	i = lenght(n);
	nbr = ft_calloc(i + 1, sizeof(char));
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (num >= 10)
	{
		nbr[i - 1] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	nbr[i - 1] = num + '0';
	return (nbr);
}
