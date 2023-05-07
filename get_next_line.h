/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:15:59 by bargarci          #+#    #+#             */
/*   Updated: 2023/05/04 18:19:28 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 5
#endif
char	*get_next_line(int fd);
int		new_line(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(const char *s);
char	*ft_new_line(char *s);
#endif
