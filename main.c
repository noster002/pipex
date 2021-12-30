/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:51:47 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/30 13:23:32 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc != 5)
		exit(EXIT_FAILURE);
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd[1] < 0)
		return (-1);
	if (fd[0] < 0)
		exit_error("bash: ", argv[1]);
	pipex(fd, argv, envp);
	return (0);
}
