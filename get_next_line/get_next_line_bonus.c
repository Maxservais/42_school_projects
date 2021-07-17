/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:00:07 by mservais          #+#    #+#             */
/*   Updated: 2021/07/17 14:48:05 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_return_null(char **line)
{
	free(*line);
	return (NULL);
}

void	ft_cut(char str[], size_t n)
{
	size_t	i;

	i = 0;
	while (n < BUFFER_SIZE)
	{
		str[i] = str[n];
		n++;
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_return(char buffer[], char **line, int byte_read)
{
	if (ft_find_newline(buffer) != ft_strlen(buffer))
	{
		ft_cut(buffer, ft_find_newline(buffer) + 1);
		if (ft_end_of_line(*line) || ft_strlen(*line))
			return (*line);
	}
	else if (ft_find_newline(buffer) == ft_strlen(buffer))
	{
		while (byte_read < BUFFER_SIZE)
		{
			buffer[byte_read] = 0;
			byte_read++;
		}
		if (ft_end_of_line(*line) || ft_strlen(*line))
			return (*line);
	}
	return (ft_return_null(line));
}

char	*get_next_line(int fd)
{
	int			byte_read;
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(NULL, buffer[fd]);
	if (!line)
		return (ft_return_null(&line));
	if (ft_find_newline(buffer[fd]) != ft_strlen(buffer[fd]))
		return (ft_return(buffer[fd], &line, 0));
	byte_read = BUFFER_SIZE;
	while (byte_read == BUFFER_SIZE && !ft_end_of_line(buffer[fd]))
	{
		byte_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (byte_read < 0)
			return (ft_return_null(&line));
		buffer[fd][byte_read] = '\0';
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (ft_return_null(&line));
		if (byte_read == BUFFER_SIZE)
			byte_read = ft_find_newline(buffer[fd]);
	}
	return (ft_return(buffer[fd], &line, 0));
}
