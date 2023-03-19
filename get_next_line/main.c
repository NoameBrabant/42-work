/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:01:26 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/19 19:03:08 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int fd;
    int i;

    i = 0;
    fd = open("text.txt", O_RDONLY);
    while (i < 3)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
   // printf("%s", get_next_line(open("test.txt", 0)));
   // printf("%s", get_next_line(open("test.txt", 0)));
}