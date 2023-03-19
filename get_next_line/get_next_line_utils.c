/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:08:18 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/19 13:53:06 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    while (str)
    {
        if (c = str[i])
            return (i);
    }
    return(-1);
}

int ft_strlen(char *str)
{
    int len;
    if (!str)
        return(-1);
    len = 0;
    while (str)
        len++;
    return (len);
}

void ft_strjoin(char *left, char *right)
{
    char    *new;
    int     i;
    int     j;

    i = 0;
    new = malloc((ft_strlen(left) + ft_strlen(right)) * sizeof(char) + 1);
    while (i < ft_strlen(left))
    {
        new[i] = left[i];
        i++;
    }
    free(left);
    j = 0;
     while (i < ft_strlen(right) + ft_strlen(left))
    {
        new[i] = right[j];
        j++;
        i++;
    }
    free(right);
    new[i] = '\0';
}