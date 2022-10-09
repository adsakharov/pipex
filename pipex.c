/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:52:40 by arupert           #+#    #+#             */
/*   Updated: 2022/04/04 14:11:49 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message_exit(void)
{
	if (errno)
		perror(NULL);
	else
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	open_in(char *arg1)
{
	if (access(arg1, F_OK) == 0)
	{
		return (open(arg1, O_RDONLY));
	}
	else
		error_message_exit();
	return (0);
}

int	open_out(char *arg4)
{
	int	fdout;

	fdout = open(arg4, O_CREAT | O_WRONLY | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fdout < 0)
		error_message_exit();
	return (fdout);
}

void	pipe_connect(char **argv, char **envp, int *pipefd)
{
	pid_t	pid;
	char	**exe_args;
	char	*path;

	pid = fork();
	if (pid < 0)
		return (perror("Fork"));
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		exe_args = ft_split(argv[2], ' ');
		path = final_path(envp, exe_args[0]);
		if (path && exe_args[0])
			execve(path, exe_args, envp);
		write(2, "Command not found\n", 19);
		exit(127);
	}
	else
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		waitpid(pid, NULL, 0);
	}
}

void	parent(char **argv, char **envp)
{
	char	**exe_args;
	char	*path;

	exe_args = ft_split(argv[3], ' ');
	path = final_path(envp, exe_args[0]);
	if (path && exe_args[0])
		execve(path, exe_args, envp);
	write(2, "Command not found\n", 19);
	exit(127);
}
