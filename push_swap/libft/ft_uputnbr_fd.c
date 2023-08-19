/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:16:49 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/15 18:09:21 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uputnbr_fd(unsigned long n, int fd)
{
	unsigned long	m;

	m = n;
	if (n >= 10)
	{
		ft_uputnbr_fd (n / 10, fd);
	}
	m = n % 10 + '0';
	write (fd, &m, 1);
	return (ft_nbrlen(n));
}
