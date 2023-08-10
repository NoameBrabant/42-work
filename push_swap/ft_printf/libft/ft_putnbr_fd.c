/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:16:49 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/16 14:34:42 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long long n, int fd)
{
	long long	m;
	int			sign;

	sign = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (ft_nbrlen(n));
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
		sign += 1;
	}
	m = n;
	if (n >= 10)
		ft_putnbr_fd (n / 10, fd);
	m = n % 10 + '0';
	write (fd, &m, 1);
	return (ft_nbrlen(n) + sign);
}
