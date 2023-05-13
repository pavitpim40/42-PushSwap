/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:46:42 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/13 02:51:31 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}


char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (s);
}

char	*create_buffer(char *buffer)
{
	char	*new_buffer;

	if (buffer != NULL)
		return (buffer);
	new_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (new_buffer != NULL)
		*new_buffer = '\0';
	return (new_buffer);
}

void	move_buffer(char *buffer, char *next)
{
	while (*next != '\0')
	{
		*buffer = *next;
		buffer++;
		next++;
	}
	*buffer = '\0';
}

char	*read_line(char *buffer, int fd)
{
	char	*line;
	char	*next;
	int		n;

	line = NULL;
	if (ft_strlen(buffer) != 0)
	{
		next = ft_strchr(buffer, '\n');
		if (next != NULL)
		{
			*next = '\0';
			line = ft_strjoin(buffer, "\n");
			move_buffer(buffer, next + 1);
			return (line);
		}
		line = ft_strjoin(buffer, "");
		*buffer = '\0';
	}
	n = read(fd, buffer, BUFFER_SIZE);
	if (n >= 0)
		*(buffer + n) = '\0';
	if (n > 0 && line == NULL)
		line = ft_strjoin("", "");
	return (line);
}

char	*free_buffer(void *buffer)
{
	if (buffer != NULL)
		free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*next;

	if (fd < 0)
		return (NULL);
	buffer = create_buffer(buffer);
	if (buffer == NULL)
		return (NULL);
	line = NULL;
	next = read_line(buffer, fd);
	while (next != NULL)
	{
		if (line == NULL)
			line = next;
		else
			line = ft_strjoin_free(line, next);
		if (ft_strchr(line, '\n'))
			return (line);
		next = read_line(buffer, fd);
	}
	buffer = free_buffer(buffer);
	return (line);
}


// 
