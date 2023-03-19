/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:08:18 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/19 18:38:48 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        //printf("here4, %d", i);
        if (c == str[i])
            return (i);
        i++;
    }
    return(-1);
}

int ft_strlen(char *str)
{
    int len;
    if (!str)
        return(-1);
    len = 0;
    while (str[len])
        len++;
    return (len);
}

char *ft_strjoin(char *left, char *right)
{
    char    *new;
    int     i;
    int     j;

    i = 0;
    new = malloc((ft_strlen(left) + ft_strlen(right)) * sizeof(char) + 1);
    while (left[i])
    {
        //printf("here2");
        new[i] = left[i];
        i++;
    }
    j = 0;
    while (right[j])
    {
        //printf("here3");
        new[i] = right[j];
        j++;
        i++;
    }
    new[i] = '\0';
    return(new);
}