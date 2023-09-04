/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:53:38 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/04 12:36:23 by tremy            ###   ########.fr       */
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
		if (output[i] == '\0' && temp[i][0] != '0')
		{
			free(output);
			ft_free_tab(temp, 1);
		}
		i++;
	}
	ft_free_tab(temp, 0);
	return (output);
}

void	ft_istwin(int *tab)
{
	int	i;
	int	y;

	y = 0;
	while (tab[y])
	{
		i = y + 1;
		while (tab[i])
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

int	*ft_create_list_numbers(int *len, char **input)
{
	int		*output;
	int		i;

	i = 0;
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
			if (ft_atoi(input[i + 1]) == '\0' && input[i + 1][0] != '0')
				free(output);
			if (ft_atoi(input[i + 1]) == '\0' && input[i + 1][0] != '0')
				ft_error();
			i++;
		}
	}
	ft_istwin(output);
	return (output);
}
