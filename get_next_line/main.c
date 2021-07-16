/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:43:17 by mservais          #+#    #+#             */
/*   Updated: 2021/07/13 14:25:10 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	// int		fd2;
	// int		fd3;

	fd1 = open("test3.txt", O_RDONLY);
	// fd2 = open("test2.txt", O_RDONLY);
	// fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		i++;
	}
	close(fd1);
	// close(fd2);
	// close(fd3);
	return (0);
}


// #include <fcntl.h>
// #include <stdio.h>
// #include "get_next_line.h"

// int main(int ac, char **av)
// {
//     int        fd;
//     char    *line;
//     int        ct;
//     int        i = 0;

//     ct = 100;
//     if (ac == 0)
//         return (0);
//     fd = open(av[1], O_WRONLY);
//     while (ct > 0)
//     {
//         line = get_next_line(fd);
//         printf("line %02i : |%s|\n%p\n", i, line, line);
//         if (line)
//         {
//             free(line);
//             line = NULL;
//         }
//         else
//             break;
//         i++;
//         ct--;
//     }
//     return (1);
// }
