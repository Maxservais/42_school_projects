/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:59:23 by mservais          #+#    #+#             */
/*   Updated: 2021/07/16 13:13:39 by mservais         ###   ########.fr       */
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
char	*ft_strdup(char const *s);
char	*ft_strdup_new_line(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_error_check(int fd);
int		ft_end_of_line(char *str);
size_t	ft_find_newline(char const *str);
char	*ft_return(char **line_in_memory, char **buffer);
char	*get_next_line(int fd);

#endif
