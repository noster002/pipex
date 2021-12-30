/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:51:47 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/30 16:32:48 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	t_arg	arg;

	if (argc < 4)
		exit(EXIT_FAILURE);
	arg = (t_arg){argc - 2, 2, 1, argc - 1};
	fd[0] = open(argv[arg.file_in], O_RDONLY);
	fd[1] = open(argv[arg.file_out], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd[1] < 0)
		return (-1);
	if (fd[0] < 0)
		exit_error("bash: ", argv[arg.file_in]);
	if (argc == 4)
		children(argv[arg.cmd], fd[0], fd[1], envp);
	pipex(fd, arg, argv, envp);
	return (0);
}
