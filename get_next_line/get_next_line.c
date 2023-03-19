/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:18:16 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/19 13:42:58 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char     *stash;
    char            buff[BUFFER_SIZE];
    char            *res;
    char            *truc;
    int             i;
    int             t;
    int             n;
    int             j;
    
    res = malloc(0);
    if (!stash)
        stash = malloc(0);
    if (ft_strchr(stash, '\n') == -1)
    {
        ft_strjoin(res, stash);
        n = ft_strchr(res, '\n');
        while (n == -1 && t != BUFFER_SIZE)
        {
            t = read(fd, buff, BUFFER_SIZE);
            ft_strjoin(res, buff);
        }
        i = 0;
        n = ft_strchr(res, '\n');
        while (res[n] != -1 && res[n + i])
        {
            stash[i] = res[ft_strchr(res, '\n') + i];
            i++;
        }
        i = ft_strlen(res);
        while (i >= n)
        {
            res[i] = '\0';
            i--;
        }
        return (res);
    }
    else
    {
        res = malloc(sizeof(char) * ft_strchr(stash, '\n') + 1);
        i = 0;
        while (stash[i] != '\n')
        {
            res[i] = stash[i];
            i++;
        }
        i = ft_strchr(stash, '\n') + 1;
        j = 0;
        truc = malloc(sizeof(char) * ft_strlen(stash) + 1);
        while (stash[i])
        {
            truc[j] = stash[i];
            j++;
            i++;
        }
        free(stash);
        stash = malloc(j * sizeof(char) + 1);
        j = 0;
        while(stash[j])
        {
            stash[j] = truc[j];
            j++;
        }
        return (res);  
    }
    return (NULL);    
}