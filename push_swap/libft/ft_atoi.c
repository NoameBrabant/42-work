/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:21:12 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/01 19:33:53 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	res;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		if ((sign == 1 && (res * 10 + nptr[i] - '0') > INT_MAX) 
			|| (sign == -1 
				&& ((res * 10 + nptr[i] - '0') * (-1)) < INT_MIN))
			return ('\0');
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
