/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:31:40 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/10 22:14:29 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	checksnull(char *str)
{
	if (str == NULL)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}

int	checkpnull(unsigned long nbr)
{
	if (nbr == 0)
		return (ft_putstr_fd("(nil)", 1));
	return (ft_putaddress_fd(nbr, 1));
}

int	conversion(va_list args, const char symbol)
{
	int	len;

	len = 0;
	if (symbol == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (symbol == 's')
		len += checksnull(va_arg(args, char *));
	else if (symbol == 'p')
		len += checkpnull(va_arg(args, unsigned long));
	else if (symbol == 'd' || symbol == 'i')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (symbol == 'u')
		len += ft_uputnbr_fd(va_arg(args, unsigned int), 1);
	else if (symbol == 'x')
		len += ft_uputnbr_base_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 1);
	else if (symbol == 'X')
		len += ft_uputnbr_base_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1);
	else if (symbol == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += conversion(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
