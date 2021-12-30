/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:02:28 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/30 13:17:06 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int *fd, char **argv, char **envp)
{
	int		end[2];
	pid_t	child[2];
	int		status;

	pipe(end);
	child[0] = fork();
	if (child[0] < 0)
		exit_error("Fork1", 0);
	else if (child[0] == 0)
	{
		close_fd(fd[1], end[0]);
		children(argv[2], fd[0], end[1], envp);
	}
	child[1] = fork();
	if (child[1] < 0)
		exit_error("Fork2", 0);
	else if (child[1] == 0)
	{
		close_fd(fd[0], end[1]);
		children(argv[3], end[0], fd[1], envp);
	}
	close_fd(fd[0], fd[1]);
	close_fd(end[0], end[1]);
	waitpid(child[0], &status, 0);
	waitpid(child[1], &status, 0);
}
