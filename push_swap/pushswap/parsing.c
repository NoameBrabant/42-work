/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:53:38 by nbrabant          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/04 15:40:59 by nbrabant         ###   ########.fr       */
=======
/*   Updated: 2023/09/04 15:57:06 by tremy            ###   ########.fr       */
>>>>>>> 2b74ec77d1135ff8d7a073c4ab977ccb897b7b64
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	ft_get_length(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*ft_splitnumbers(char *input, int *len)
{
	char	**temp;
	int		*output;
	int		i;

	i = 0;
	temp = ft_split(input, ' ', len);
	i = 0;
	output = ft_calloc(ft_get_length(temp) + 1, sizeof(int));
	while (temp[i])
	{
		if (ft_isnum(temp[i]) == 0)
		{
			free(output);
			ft_free_tab(temp, 1);
		}
		output[i] = ft_atoi(temp[i]);
		if (output[i] == '\0' && !ft_is_zero(temp[i], (int)ft_strlen(temp[i])))
		{
			free(output);
			ft_free_tab(temp, 1);
		}
		i++;
	}
	ft_free_tab(temp, 0);
	return (output);
}

void	ft_istwin(int *tab, int len)
{
	int	i;
	int	y;

	y = 0;
	while (y < len)
	{
		i = y + 1;
		while (i < len)
		{
			if (tab[y] == tab[i])
			{
				free(tab);
				ft_error();
			}
			i++;
		}
		y++;
	}
}

int	*ft_create_list_numbers(int *len, char **input, int i)
{
	int		*output;

	if (*len == 1)
		output = ft_splitnumbers(input[1], len);
	else
	{
		output = ft_calloc(*len + 1, sizeof(int));
		while (i + 1 <= *len)
		{
			if (ft_isnum(input[i + 1]) == 0)
				free(output);
			if (ft_isnum(input[i + 1]) == 0)
				ft_error();
			output[i] = ft_atoi(input[i + 1]);
			if (ft_atoi(input[i + 1]) == '\0' 
				&& !ft_is_zero(input[i + 1], ft_strlen(input[i + 1])))
				free(output);
			if (ft_atoi(input[i + 1]) == '\0' 
				&& !ft_is_zero(input[i + 1], ft_strlen(input[i + 1])))
				ft_error();
			i++;
		}
	}
	ft_istwin(output, *len);
	return (output);
}
