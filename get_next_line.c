/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:14:30 by bargarci          #+#    #+#             */
/*   Updated: 2023/05/05 16:36:42 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>*/
#include "get_next_line.h"
int		count(char *buffer)
{
	int	i;
	
	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);

}
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_new_line(char *s)
{	
	char *new;
	int	i;

	i = 0;
	if (!s)
		return(0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		new = malloc(sizeof(char) *(i + 2));
	else 
		new = malloc(sizeof(char) *(i + 1));
	if(!new)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	if (new[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free (s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	int			nbyts;
	char 	*new_line;

	nbyts = 1;
	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (!count(rest) && nbyts != 0)
	{
		nbyts = read(fd, buffer, BUFFER_SIZE);
		if (nbyts == -1)
		{
			free (buffer);
			return (0);
		}
		buffer[nbyts] = '\0';
		rest = ft_strjoin(rest, buffer);
		new_line = ft_new_line(rest);
	}
	return (new_line);
	
}

int main(void)
{
	int fd;
	char *line;

	fd = open("read.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free (line);

	}
	close(fd);
}

