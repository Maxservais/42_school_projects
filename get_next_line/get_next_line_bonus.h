/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:01:50 by mservais          #+#    #+#             */
/*   Updated: 2021/07/12 18:30:07 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

size_t	ft_strlen(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s);
char	*ft_strdup_new_line(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_error_check(int fd);
int		ft_end_of_line(char const *str);
size_t	ft_find_newline(char const *str);
char	*ft_return(char **line_in_memory, char **buffer);
char	*get_next_line(int fd);

#endif
