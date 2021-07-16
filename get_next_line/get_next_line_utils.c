/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:00:36 by mservais          #+#    #+#             */
/*   Updated: 2021/07/16 18:51:37 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s && *(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (!s2)
		return (NULL);
	if (ft_end_of_line((char *)s2))
		len = ft_strlen(s1) + ft_find_newline(s2) + 1;
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(str + i + j) = *(s2 + j);
		if (*(s2 + j) == '\n')
		{
			j++;
			break ;
		}
		j++;
	}
	*(str + i + j) = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_strdup(char const *s)
{
	char	*dst;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (s && *(s + i) != '\0')
	{
		*(dst + i) = *(s + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

char	*ft_strdup_new_line(char const *s)
{
	int		i;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	while (s && *(s + i) != '\0')
	{
		if (*(s + i) == '\n')
		{
			dst = ft_strdup((char *) s + i + 1);
			free((void *)s);
			return (dst);
		}
		i++;
	}
	dst = ft_strdup((char *) s + i);
	free((void *)s);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub_str = malloc(sizeof(char const) * (len + 1));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (*(s + start + i) != '\0' && i < len)
	{
		*(sub_str + i) = *(s + start + i);
		i++;
	}
	*(sub_str + i) = '\0';
	return (sub_str);
}
