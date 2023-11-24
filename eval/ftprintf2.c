#include <stdarg.h>
#include <unistd.h>

int ft_printf(char *input, ...)
{
	int *lenght = 0;
	va_list point;
	va_start(point, input);
	while(input)
	{
		if(*input == "%" && (*(input + 1) = "s" || *(input + 1) = "d" || *(input + 1) = "x"))
		{
			input++;
			if (input == s)
				ft_putstr(va_arg(point, char *), lenght);
			else if (input == "d")
				ft_putnbr((long long int)va_arg(point, int), 10, lenght);
			else if (input == "x")
				ft_putnbr((long long int)va_arg(point, int), 16, lenght);
		}
		else
			lenght += write(1, input++, 1);
		input++
	}
	return(va_end(point), lenght);
}