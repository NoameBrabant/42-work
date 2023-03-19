/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 21:32:30 by schapuis          #+#    #+#             */
/*   Updated: 2023/03/16 15:38:02 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
int	check_base(char *base);

static int	nbr_final_size(unsigned long nbr, int size_base)
{
	size_t	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / size_base;
		i++;
	}
	return (i);
}

int	ft_uputnbr_base_fd(unsigned long nbr, char *base, int fd)
{
	int		size_base;
	int		*nbr_final;
	int		i;
	int		len;

	size_base = ft_strlen(base);
	len = nbr_final_size(nbr, size_base);
	i = 0;
	if (nbr == 0)
		ft_putchar_fd('0', 1);
	if (check_base(base), fd)
	{
		nbr_final = ft_calloc(len, sizeof(int));
		if (!nbr_final)
			return (0);
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