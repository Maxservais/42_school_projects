/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:32:30 by mservais          #+#    #+#             */
/*   Updated: 2021/07/12 13:53:14 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_error_check(int fd)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	return (buffer);
}

int	ft_end_of_line(char const *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_find_newline(char const *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_return(char **line_in_memory, char **buffer)
{
	size_t	pos_newline;
	char	*line;

	free(*buffer);
	if (ft_end_of_line(*line_in_memory))
	{
		pos_newline = ft_find_newline(*line_in_memory) + 1;
		line = ft_substr(*line_in_memory, 0, pos_newline);
	}
	else
		line = ft_substr(*line_in_memory, 0, ft_strlen(*line_in_memory));
	if (!line || *line == '\0')
		return (NULL);
	*line_in_memory = ft_strdup_new_line(*line_in_memory);
	if (!*line_in_memory)
		return (NULL);
	if (line)
		return (line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			byte_read;
	char		*buffer;
	static char	*line_in_memory;

	buffer = ft_error_check(fd);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read && !ft_end_of_line(line_in_memory))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free((void *)buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		line_in_memory = ft_strjoin(line_in_memory, buffer);
		if (!line_in_memory)
		{
			free((void *)buffer);
			return (NULL);
		}
	}
	return (ft_return(&line_in_memory, &buffer));
}
