/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 21:32:30 by schapuis          #+#    #+#             */
/*   Updated: 2023/08/20 18:26:49 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

long long	check_neg(long long nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		return (-nbr);
	}
	return (nbr);
}

static int	nbr_final_size(long long nbr, int size_base)
{
	size_t	i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / size_base;
		i++;
	}
	return (i);
}

int	ft_putnbr_base_fd(long long nbr, char *base, int fd)
{
	int		size_base;
	int		*nbr_final;
	int		i;
	int		len;

	size_base = ft_strlen(base);
	len = nbr_final_size(nbr, size_base);
	i = 0;
	if (check_base(base), fd)
	{
		nbr_final = ft_calloc(len, sizeof(int));
		if (!nbr_final)
			return (0);
		nbr = check_neg(nbr, fd);
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar_fd(base[nbr_final[i]], fd);
		free(nbr_final);
	}
	return (len);
}
