/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:18:16 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/19 19:04:17 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char     *stash;
    char            buff[BUFFER_SIZE + 1];
    char            *res;
    char            *truc;
    char            *tmp;
    int             i;
    int             t;
    int             n;
    int             j;
    
    t = BUFFER_SIZE;
    res = malloc(1);
   /* i = 0;
    while (i < 8)
    {
        res[i] ='a' +i;
        i++;
    }*/
    res[0] = '\0';
    printf("On a alloue res\n");
    printf(C_RED"%s\n"C_NOR, res);
    printf(C_BLU"%s\n\n"C_NOR, stash);
    if (!stash)
    {
        //printf("ici");
        stash = malloc(1);
        stash[0] = '\0'; 
        //printf("here");
    }
    printf("On a alloue stash\n");
    printf(C_RED"%s\n"C_NOR, res);
    printf(C_BLU"%s\n\n"C_NOR, stash);
    if (ft_strchr(stash, '\n') == -1)
    {
        tmp = ft_strjoin(res, stash);
        free(res);
        stash[0] = '\0';
        //free(stash);
        //stash = NULL;
        res = tmp;
        printf("On join stash et res\n");
        printf(C_RED"%s\n"C_NOR, res);
        printf(C_BLU"%s\n"C_NOR, stash);
        printf(C_GRE"%s\n\n"C_NOR, tmp);
        tmp[0] = '\0';
        n = ft_strchr(res, '\n');
        while (n == -1 && t == BUFFER_SIZE)
        {
            //printf("oui1");
            t = read(fd, buff, BUFFER_SIZE);
            buff[t] = '\0';
            printf(C_YEL"%d\n"C_NOR, buff);
            tmp = ft_strjoin(res, buff);
            printf(C_YEL"%s\n"C_NOR, tmp);
            free(res);
            res = tmp;
            printf("On est en train de remplir res\n");
            printf(C_RED"%s\n"C_NOR, res);
            printf(C_BLU"%s\n\n"C_NOR, stash);
            //free(tmp);
            n = ft_strchr(res, '\n');
        }
        printf("On est avant de remplir stash\n");
        printf(C_RED"%s\n"C_NOR, res);
        printf(C_BLU"%s\n\n"C_NOR, stash);
        i = 0;
        n = ft_strchr(res, '\n');
        //printf("\nn ===== %d || res ===== %c\n", n, res[n - 1]);
        while (res[n + i + 1] != '\0')
        {
            //printf("oui2");
            stash[i] = res[n + i + 1];
            i++;
        }
        stash[i] = '\0';
       // stash = ft_stash(res, n);
        //printf("\nn ===== %d || res[n] ===== %c\n", n, res[n - 1]);
        printf("On a fini de remplir stash\n");
        printf(C_RED"%s\n"C_NOR, res);
        printf(C_BLU"%s\n\n"C_NOR, stash);
        i = ft_strlen(res);
        while (i > n)
        {
            //printf("oui3");
            res[i] = '\0';
            i--;
        }
        printf("On est a la fin\n");
        printf(C_RED"%s\n"C_NOR, res);
        printf(C_BLU"%s\n\n"C_NOR, stash);
        return (res);
    }
    else
    {
        res = malloc(sizeof(char) * ft_strchr(stash, '\n') + 1);
        i = 0;
        while (stash[i] != '\n')
        {
            printf("oui4");
            res[i] = stash[i];
            i++;
        }
        i = ft_strchr(stash, '\n') + 1;
        j = 0;
        truc = malloc(sizeof(char) * ft_strlen(stash) + 1);
        while (stash[i])
        {
            printf("oui5");
            truc[j] = stash[i];
            j++;
            i++;
        }
        if (stash)
            free(stash);
        stash = malloc(j * sizeof(char) + 1);
        j = 0;
        while(stash[j])
        {
            printf("oui5");
            stash[j] = truc[j];
            j++;
        }
        return (res);  
    }
    return (NULL);    
}
