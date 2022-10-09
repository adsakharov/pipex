/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:36:10 by arupert           #+#    #+#             */
/*   Updated: 2022/04/04 13:59:57 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <errno.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_slash_strjoin(char const *s1, char const *s2);
char	**find_path(char **envp);
char	*final_path(char **envp, char *cmd);
char	**free_char_array(char **char_array);
char	**ft_split(char const *s, char c);
void	error_message_exit(void);
int		open_in(char *arg1);
int		open_out(char *arg4);
void	pipe_connect(char **argv, char **envp, int *pipefd);
void	parent(char **argv, char **envp);

#endif