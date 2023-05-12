/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:46:42 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/13 03:31:08 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char *extract_full_line(char *storage)
{
	char *full_line;
	int index;
	int len;

	if(!storage)
		return (NULL);
	len = 0;
	while (storage[len] && storage[len] != '\n')
		len++;
	full_line = malloc(sizeof(char) * len + 2);
	if (!full_line)
		return (NULL);
	index = 0;
	while (index < len)
	{
		full_line[index] = storage[index];
		index++;
	}
	if (storage[index] == '\n')
		full_line[index++] = '\n';
	full_line[index] = '\0';
	return (full_line);
}

static char *truncate_storage(char *storage)
{
	int len;
	int i;
	int index;
	char *new_storage;

	len = ft_strlen(storage);
	index = ft_char_index(storage, '\n');
	if (index == -1 || len == index + 1)
	{
		free(storage);
		return (NULL);
	}
	i = 0;
	new_storage = malloc(sizeof(char) * (len - index));
	if (!new_storage)
		return (NULL);
	while (storage && i < (len - index - 1))
	{
		new_storage[i] = storage[i + index + 1];
		i++;
	}
	new_storage[i] = '\0';
	free(storage);
	return (new_storage);
}

static char *storage_join(char *storage, char *buffer)
{
	char *new_storage;
	size_t i;
	size_t j;

	new_storage = malloc(ft_strlen(storage) + ft_strlen(buffer) + 1);
	if (!new_storage)
		return (NULL);
	i = 0;
	while (storage && storage[i])
	{
		new_storage[i] = storage[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		new_storage[i + j] = buffer[j];
		j++;
	}
	new_storage[i + j] = '\0';
	if (storage)
		free(storage);
	return (new_storage);
}

char *get_next_line(int fd)
{
	char *buffer;
	int read_byte;
	char static *storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_byte = (int)read(fd, buffer, BUFFER_SIZE);
	// printf("read byte = %d\n",read_byte);
	if (read_byte != 0 && read_byte != -1)
	{
		buffer[read_byte] = '\0';
		storage = storage_join(storage, buffer);
	}
	while (read_byte > 0 && ft_char_index(storage, '\n') == -1)
	{
		read_byte = (int)read(fd, buffer, BUFFER_SIZE);
		if (read_byte != 0 && read_byte != -1)
		{
			buffer[read_byte] = '\0';
			storage = storage_join(storage, buffer);
		}
	}
	free(buffer);
	buffer = extract_full_line(storage);
	storage = truncate_storage(storage);
	return (buffer);
}

char *ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	k;
// 	char	*str;

// 	k = 0;
// 	if (s1 == (void *)0 || s2 == (void *)0)
// 		return (NULL);
// 	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (*(s1 + i) != '\0')
// 		*(str + k++) = *(s1 + i++);
// 	i = 0;
// 	while (*(s2 + i) != '\0')
// 		*(str + k++) = *(s2 + i++);
// 	*(str + k) = '\0';
// 	return (str);
// }

// char	*ft_strjoin_free(char *s1, char *s2)
// {
// 	char	*s;

// 	s = ft_strjoin(s1, s2);
// 	if (s1 != NULL)
// 		free(s1);
// 	if (s2 != NULL)
// 		free(s2);
// 	return (s);
// }

// char	*create_buffer(char *buffer)
// {
// 	char	*new_buffer;

// 	if (buffer != NULL)
// 		return (buffer);
// 	new_buffer = (char *)malloc(BUFFER_SIZE + 1);
// 	if (new_buffer != NULL)
// 		*new_buffer = '\0';
// 	return (new_buffer);
// }

// void	move_buffer(char *buffer, char *next)
// {
// 	while (*next != '\0')
// 	{
// 		*buffer = *next;
// 		buffer++;
// 		next++;
// 	}
// 	*buffer = '\0';
// }

// char	*read_line(char *buffer, int fd)
// {
// 	char	*line;
// 	char	*next;
// 	int		n;

// 	line = NULL;
// 	if (ft_strlen(buffer) != 0)
// 	{
// 		next = ft_strchr(buffer, '\n');
// 		if (next != NULL)
// 		{
// 			*next = '\0';
// 			line = ft_strjoin(buffer, "\n");
// 			move_buffer(buffer, next + 1);
// 			return (line);
// 		}
// 		line = ft_strjoin(buffer, "");
// 		*buffer = '\0';
// 	}
// 	n = read(fd, buffer, BUFFER_SIZE);
// 	if (n >= 0)
// 		*(buffer + n) = '\0';
// 	if (n > 0 && line == NULL)
// 		line = ft_strjoin("", "");
// 	return (line);
// }

// char	*free_buffer(void *buffer)
// {
// 	if (buffer != NULL)
// 		free(buffer);
// 	return (NULL);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;
// 	char		*next;

// 	if (fd < 0)
// 		return (NULL);
// 	buffer = create_buffer(buffer);
// 	if (buffer == NULL)
// 		return (NULL);
// 	line = NULL;
// 	next = read_line(buffer, fd);
// 	while (next != NULL)
// 	{
// 		if (line == NULL)
// 			line = next;
// 		else
// 			line = ft_strjoin_free(line, next);
// 		if (ft_strchr(line, '\n'))
// 			return (line);
// 		next = read_line(buffer, fd);
// 	}
// 	buffer = free_buffer(buffer);
// 	return (line);
// }
