/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:01:50 by mservais          #+#    #+#             */
/*   Updated: 2021/06/16 13:23:04 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

size_t	ft_strlen(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s);
char	*ft_strdup_new_line(char const *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_error_check(int fd, char **line);
int		ft_end_of_line(char const *str);
int		ft_find_newline(char const *str);
int		get_next_line(int fd, char **line);

#endif
