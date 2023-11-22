# include "get_next_line_bis.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}

char	*ft_read_line(int fd, char *stash)
{
	int		i;
	char	*str;

	i = 1;
	if (BUFFER_SIZE == 0)
		return (NULL);
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (i > 0)
	{
		i = read(fd, stash, BUFFER_SIZE);
		str[i] = '\0';
		if (i < 0 || ft_strchr(str, '\n'))
			break ;
		i++;
		stash = ft_strjoin(stash, str);
	}
	free(str);
	return (stash);
}

char	get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
}

#include <fcntl.h>

int	main()
{
	int	fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		get_next_line(fd);
	}
	return (0);
}
