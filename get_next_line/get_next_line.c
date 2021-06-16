/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:32:30 by mservais          #+#    #+#             */
/*   Updated: 2021/06/16 15:50:09 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_error_check(int fd, char **line)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
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

int	ft_find_newline(char const *str)
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

int	ft_return(char **line, char **line_in_memory, char **buffer, int byte_read)
{
	free(*buffer);
	if (ft_end_of_line(*line_in_memory))
		*line = ft_substr(*line_in_memory, 0, ft_find_newline(*line_in_memory));
	else
		*line = ft_substr(*line_in_memory, 0, ft_strlen(*line_in_memory));
	if (!*line)
		return (-1);
	*line_in_memory = ft_strdup_new_line(*line_in_memory);
	if (!*line_in_memory && byte_read != 0)
		return (-1);
	if (byte_read)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			byte_read;
	char		*buffer;
	static char	*line_in_memory;

	buffer = ft_error_check(fd, line);
	if (!buffer)
		return (-1);
	byte_read = 1;
	while (byte_read && !ft_end_of_line(line_in_memory))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free((void *)buffer);
			return (-1);
		}
		buffer[byte_read] = '\0';
		line_in_memory = ft_strjoin(line_in_memory, buffer);
		if (!line_in_memory)
		{
			free((void *)buffer);
			return (-1);
		}
	}
	return (ft_return(line, &line_in_memory, &buffer, byte_read));
}
