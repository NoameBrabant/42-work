/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:31:40 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/16 15:38:51 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>


int	checksNULL(char *str)
{
	if (str == NULL)
		return(ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}

int	checkpNULL(unsigned long nbr)
{
	if (nbr == 0)
		return(ft_putstr_fd("(nil)", 1));
	return (ft_putaddress_fd(nbr, 1));
}

int	conversion(va_list args, const char symbol)
{
	int	len;
	
	len = 0;
	if (symbol == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (symbol == 's')
		len += checksNULL(va_arg(args, char *)); 
	else if (symbol == 'p')
		len += checkpNULL(va_arg(args, unsigned long)); 
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

/*int main()
{
	printf("%d\n", printf("%x\n", 0));
	printf("%d\n", ft_printf("%x\n", 0));
}*/