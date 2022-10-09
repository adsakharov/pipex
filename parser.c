/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:49:00 by arupert           #+#    #+#             */
/*   Updated: 2022/04/04 13:56:07 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	char	**paths;
	int		i;

	paths = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (envp[i])
		paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*final_path(char **envp, char *cmd)
{
	char	**path_lines;
	int		i;
	char	*path;

	path_lines = find_path(envp);
	if (!path_lines)
		return (cmd);
	i = 0;
	while (path_lines[i])
	{
		path = ft_slash_strjoin(path_lines[i], cmd);
		if (access(path, F_OK) == 0)
		{
			path_lines = free_char_array(path_lines);
			return (path);
		}
		free(path);
		i++;
	}
	path_lines = free_char_array(path_lines);
	return (NULL);
}
