/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:49:16 by nbrabant          #+#    #+#             */
/*   Updated: 2023/03/27 14:52:49 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define C_NOR "\x1b[m"
# define C_BLA "\x1b[30m"
# define C_RED "\x1b[31m"
# define C_GRE "\x1b[32m"
# define C_YEL "\x1b[33m"
# define C_BLU "\x1b[34m"
# define C_MAG "\x1b[35m"
# define C_CYA "\x1b[36m"
# define C_WHI "\x1b[37m"

char	*ft_strchr(char *str, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *left, char *right);
char	*readnextline(int fd, char *stash);
char	*restnextline(char* stash);
char	*putnextline(char *stash);
char	*get_next_line(int fd);

# endif
