/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:00:46 by mservais          #+#    #+#             */
/*   Updated: 2021/07/15 19:40:43 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_end_of_line(char *str)
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
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

// char	*ft_return(char **line_in_memory, char **buffer)
// {
// 	size_t	pos_newline;
// 	char	*line;

// 	free(*buffer);
// 	if (ft_end_of_line(*line_in_memory))
// 	{
// 		pos_newline = ft_find_newline(*line_in_memory) + 1;
// 		line = ft_substr(*line_in_memory, 0, pos_newline);
// 	}
// 	else
// 		line = ft_substr(*line_in_memory, 0, ft_strlen(*line_in_memory));
// 	if (!line)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	*line_in_memory = ft_strdup_new_line(*line_in_memory);
// 	if (!*line_in_memory)
// 		return (NULL);
// 	if (line)
// 		return (line);
// 	return (NULL);
// }

void	ft_cut(char str[], size_t n)
{
	size_t	i;

	i = 0;
	while(n < BUFFER_SIZE)
	{
		str[i] = str[n];
		n++;
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		str[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	int			byte_read;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

 	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strjoin(NULL, buffer);
	if (ft_find_newline(buffer) != ft_strlen(buffer))
	{
		ft_cut(buffer, ft_find_newline(buffer) + 1);
		return (line);
	}
	byte_read = 1;
	while (byte_read && !ft_end_of_line(buffer))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		buffer[byte_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	if (ft_find_newline(buffer) == ft_strlen(buffer))
	{
		byte_read = 0;
		while (byte_read < BUFFER_SIZE)
		{
			buffer[byte_read] = '\0';
			byte_read++;
		}
		return (line);
	}
	ft_cut(buffer, ft_find_newline(buffer) + 1);
	if (line)
		return (line);
	return (NULL);
}
