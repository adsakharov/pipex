/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:31:22 by arupert           #+#    #+#             */
/*   Updated: 2022/04/04 14:31:06 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fdin;
	int		fdout;
	int		pipefd[2];

	if (argc != 5)
	{
		write(2, "Use program as follows: ./pipex file1 cmd1 cmd2 file2", 55);
		return (1);
	}
	fdin = open_in(argv[1]);
	fdout = open_out(argv[4]);
	if (fdin < 0 || fdout < 0)
		return (-1);
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	if (pipe(pipefd) < 0)
	{	
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	pipe_connect(argv, envp, pipefd);
	parent(argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	return (1);
}
