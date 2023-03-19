/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:29:11 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/08 15:03:22 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_putaddress_fd(t_nb nbr, int fd)
{
	ft_putstr_fd("0x", fd);
	return (ft_putnbr_base_fd(nbr, "0123456789abcdef", 1) + 2);
}
