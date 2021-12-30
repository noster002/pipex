/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:22:38 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/30 13:17:44 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (&envp[i][5]);
	}
	return (0);
}

static void	cmderr(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, ": command not found\n", 20);
}

static void	cmdexe(char **path, char **cmdarg, char **envp)
{
	char	*cmdpath;
	int		i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		cmdpath = ft_strjoin(path[i], cmdarg[0]);
		free(path[i++]);
		if (access(cmdpath, X_OK) == 0)
			break ;
	}
	free(path);
	if (access(cmdpath, X_OK) == 0)
		execve(cmdpath, cmdarg, envp);
	cmderr(cmdarg[0]);
	free(cmdpath);
	free_double_ptr(cmdarg);
	exit(EXIT_FAILURE);
}

void	children(char *cmd, int fd_in, int fd_out, char **envp)
{
	char	*path_envp;
	char	**path;
	char	**cmdarg;

	if (dup2(fd_in, 0) < 0 || dup2(fd_out, 1) < 0)
		exit_error("Dup2", 0);
	close_fd(fd_in, fd_out);
	path_envp = get_path(envp);
	path = ft_split(path_envp, ':');
	cmdarg = ft_split(cmd, ' ');
	cmdexe(path, cmdarg, envp);
}
