/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:39:28 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/02 08:42:05 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	readfile(t_file *file, t_pipex pipex)
{
	file->fd = open(file->filename, O_RDONLY);
	if (file->fd == -1)
	{
		close_pipe(& pipex.info);
		free_pipex(pipex);
		if (errno == 13)
			ft_printf("bash: %s: Permission denied\n", file->filename);
		else
			ft_printf("bash: %s: No such file or directory\n", file->filename);
		exit(1);
	}
	dup2(file->fd, STDIN_FILENO);
	close(file->fd);
}

void	writefile(t_file *file, t_pipex pipex)
{
	if (pipex.info.limiter)
		file->fd = open(file->filename, O_RDWR | O_APPEND | O_CREAT, 0666);
	else
		file->fd = open(file->filename, O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (file->fd == -1)
	{
		close_pipe(& pipex.info);
		free_pipex(pipex);
		if (errno == 13)
			ft_printf("bash: %s: Permission denied\n", file->filename);
		else
			ft_printf("bash: %s: No such file or directory\n", file->filename);
		exit(1);
	}
	dup2(file->fd, STDOUT_FILENO);
	close(file->fd);
}
