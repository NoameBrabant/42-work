/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:29:11 by nbrabant          #+#    #+#             */
/*   Updated: 2023/06/22 10:33:58 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddress_fd(unsigned long nbr, int fd)
{
	ft_putstr_fd("0x", fd);
	return (ft_uputnbr_base_fd(nbr, "0123456789abcdef", 1) + 2);
}
