/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:49:02 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/30 13:16:03 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	free_double_ptr(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

void	exit_error(char *err, char *arg)
{
	write(2, err, ft_strlen(err));
	perror(arg);
	exit(EXIT_FAILURE);
}
