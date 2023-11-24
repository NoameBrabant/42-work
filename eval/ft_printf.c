/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:58:22 by nbrabant          #+#    #+#             */
/*   Updated: 2023/11/23 15:15:19 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putstr(char *str, int *lenght)
{
	if (!str)
		str = "(null)";
	while(str)
		*lenght += write(1, str++, 1);
}

void	ft_putnbr(long long int nbr, int base, int *lenght)
{
	char *hexa = "123456789abcdef";

	if (nbr < 0)
	{	
		nbr *= -1;
		*lenght += write(1, "-", 1);
	}
	if (nbr >= base)
		ft_putnbr(nbr / base, base, lenght);
	*lenght += write(1, &hexa[nbr % base], 1);
}
 
int	ft_printf(const char *format, ...)
{
	int		lenght = 0;
	va_list	point;
	va_start(point, format);
	while(*format)
	{
		if ((*format == '%') && (*(format + 1) == 'd' || *(format + 1) == 'x' || *(format + 1) ==  's'))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(point, char *), &lenght);
			else if (*format == 'd')
				ft_putnbr((long long int)va_arg(point, int), 10, &lenght);
			else if (*format == 'x') 
				ft_putnbr((long long int)va_arg(point, unsigned int), 16, &lenght);
		}
		else
			lenght += write(1, format, 1);
		format++;
	}
	return(va_end(point), lenght);
}