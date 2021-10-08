/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:57:37 by mservais          #+#    #+#             */
/*   Updated: 2021/10/05 11:29:48 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include "./libft/libft.h"

# define ERROR_USAGE "Usage: ./pipex infile cmd1 cmd2 outfile\n"
# define READ 0
# define WRITE 1

/* Main program */
int		open_file(char *file_name, int mode);
pid_t	spawn_child1(int fd, int pipefd[], char *cmd, char **envp);
pid_t	spawn_child2(int fd, int pipefd[], char *cmd, char **envp);
int		main(int argc, char **argv, char **envp);

/* Error handling */
int		ft_err_return(char *error);
int		ft_perror(void);

/* Utils */
char	**find_paths(char **envp);
int		exec_cmd(char *cmd, char **envp);

#endif
