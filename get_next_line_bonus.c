/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:43:29 by bargarci          #+#    #+#             */
/*   Updated: 2023/05/18 17:29:45 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *s)
{
	char	*new;
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		new = malloc(sizeof(char) * (i + 2));
	else
		new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (0);
	i = -1;
	while (s[++i] != '\n' && s[i] != '\0')
		new[i] = s[i];
	if (s[i] == '\n')
	{
		new[i++] = '\n';
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1 && s2)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*buffer;
	int			nbyts;
	char		*new_line;

	nbyts = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (!ft_count(rest[fd]) && nbyts != 0)
	{
		nbyts = read(fd, buffer, BUFFER_SIZE);
		if (nbyts == -1)
			return (free(buffer), free(rest[fd]), rest[fd] = NULL, NULL);
		buffer[nbyts] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buffer);
	}
	free (buffer);
	if (rest[fd] && rest[fd][0] == '\0')
		return (free(rest[fd]), rest[fd] = NULL, NULL);
		new_line = ft_new_line(rest[fd]);
	return (rest[fd] = garbage(rest[fd]), new_line);
}
/*void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line1;
	char	*line2;
	char	*line3;

	// atexit(leaks);
	
	fd1 = open("null", O_RDONLY);
	fd2 = open("read.txt", O_RDONLY);
	fd3 = open("que.txt", O_RDONLY);
	
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));

	while ((line1 = get_next_line(fd1)) 
	|| (line2 = get_next_line(fd2)) || (line3 = get_next_line(fd3)))
	{
		// line = get_next_line(fd);
		if (line1 == NULL && line2 == NULL && line3 == NULL)
			break ;
		printf("%s", line1);
		printf("%s", line2);
		printf("%s", line3);
		free(line1);
		free(line2);
		free(line3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
}*/