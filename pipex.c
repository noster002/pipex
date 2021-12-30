/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:02:28 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/30 16:26:32 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int *fd, t_arg arg, char **argv, char **envp)
{
	int		end[2];
	pid_t	child;
	int		status;

	pipe(end);
	child = fork();
	if (child < 0)
		exit_error("Fork", 0);
	else if (child == 0)
	{
		close_fd(fd[1], end[0]);
		children(argv[arg.cmd], fd[0], end[1], envp);
	}
	close_fd(fd[0], end[1]);
	waitpid(child, &status, 0);
	if (++(arg.cmd) < arg.cmd_max)
	{
		fd[0] = end[0];
		pipex(fd, arg, argv, envp);
	}
	else if (child)
		children(argv[arg.cmd], end[0], fd[1], envp);
}
