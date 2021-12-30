/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:03:25 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/30 13:18:25 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

int		main(int argc, char **argv, char **envp);
void	pipex(int *fd, char **argv, char **envp);
void	children(char *cmd, int fd_in, int fd_out, char **envp);
void	close_fd(int fd1, int fd2);
void	free_double_ptr(char **ptr);
void	exit_error(char *err, char *arg);

#endif