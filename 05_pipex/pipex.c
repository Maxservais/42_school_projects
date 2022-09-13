/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:06:57 by mservais          #+#    #+#             */
/*   Updated: 2021/10/05 11:26:46 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file_name, int mode)
{
	int	fd;

	if (mode == 0)
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
			return (-1);
	}
	else
	{
		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			return (-1);
	}
	return (fd);
}

pid_t	spawn_child1(int fd, int pipefd[], char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid > 0)
		return (pid);
	else
	{
		if (dup2(fd, STDIN_FILENO) == -1 || close(pipefd[READ]) == -1)
			return (-1);
		if (dup2(pipefd[WRITE], STDOUT_FILENO) == -1)
			return (-1);
		if (exec_cmd(cmd, envp) == -1)
			return (-1);
	}
	return (0);
}

pid_t	spawn_child2(int fd, int pipefd[], char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid > 0)
		return (pid);
	else
	{
		if (close(pipefd[WRITE]) == -1)
			return (-1);
		if (dup2(fd, STDOUT_FILENO) == -1)
			return (-1);
		if (dup2(pipefd[READ], STDIN_FILENO) == -1)
			return (-1);
		if (exec_cmd(cmd, envp) == -1)
			return (-1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	status;
	int	pipefd[2];

	if (argc != 5)
		return (ft_err_return(ERROR_USAGE));
	fd1 = open_file(argv[1], 0);
	fd2 = open_file(argv[4], 1);
	if (fd1 == -1 || fd2 == -1)
		perror("Error");
	if (pipe(pipefd) == -1)
		return (ft_perror());
	if (spawn_child1(fd1, pipefd, argv[2], envp) == -1)
		return (ft_perror());
	close(fd1);
	if (spawn_child2(fd2, pipefd, argv[3], envp) == -1)
		return (ft_perror());
	close(pipefd[READ]);
	close(pipefd[WRITE]);
	if (waitpid(-1, &status, 0) == -1)
		return (ft_perror());
	close(fd2);
	return (EXIT_SUCCESS);
}
