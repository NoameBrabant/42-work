/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:49:16 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/19 13:53:01 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 6
# include <unistd.h>
# include <stdlib.h>

int     ft_strchr(char *str, char c);
int     ft_strlen(char *str);
void    ft_strjoin(char *left, char *right);
char    *get_next_line(int fd);
# endif
