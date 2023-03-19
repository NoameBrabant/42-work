/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:31:40 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/08 17:22:54 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <string.h>

int	checkNULL(va_list args, char symbol)
{
	if (symbol == s)
	{
		if (va_arg(args, unsigned long) == NULL)
			return(ft_putstr_fd("(null)", 1)
		return (ft_putstr_fd(va_arg(args, char *), 1));	
	}
	if (symbol == p)
	{
		if (va_arg(args, unsigned long) == NULL)
			return(ft_putstr_fd("(nil)", 1)
		return (ft_putaddress_fd(va_arg(args, unsigned long), 1));	
	}
	return (0);
}

int	conversion(va_list args, const char symbol)
{
	int	len;
	
	len = 0;
	if (symbol == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (symbol == 's')
		len += checkNULL(args, symbol); 
	else if (symbol == 'p')
		len += checkNULL(args, symbol); 
	else if (symbol == 'd' || symbol == 'i')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (symbol == 'u')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (symbol == 'x') 
		len += ft_putnbr_base_fd(va_arg(args, unsigned int),
			"0123456789abcdef", 1);
	else if (symbol == 'X')
		len += ft_putnbr_base_fd(va_arg(args, unsigned int),
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
