/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:53:38 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/06 09:28:07 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft/libft.h"

int	get_length(char **str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		while (str[i][y])
			y++;
		y++;
		i++;
	}
	return (i);
}

int *addnumbers(char *input)
{
	char	**temp;
	int		*output;
	int		i;

	i = 0;
	temp = ft_split(input, ' ');
	output = ft_calloc(get_length(temp), sizeof(int));
	while (temp[i])
		output[i] = ft_atoi(temp[i]);
	return (output);
}

int	*create_list_numbers(int size_input, char **input)
{
	int		*output;
	char	*jointemp;
	char	**temp;
	int		i;

	if (size_input == 1)
		output = addnumbers(input[1]);
	else
	{
		//temp = malloc(sizeof(input) - sizeof(input[0]));
		temp = ft_calloc(get_length(input) + 1, sizeof(char *));
		while (i < size_input)
		{
			temp[i] = input[i + 1];
			i++;
		}
		jointemp = ft_calloc(get_length(temp) + 1, sizeof(char));
		i = 0;
		while (temp[i])
		{
			ft_strlcat(jointemp, temp[i], ft_strlen(temp[i] - 1));
			i++;
		}
		output = addnumbers(jointemp);
	}
	return (output);
}