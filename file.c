/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:39:28 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/02 07:33:19 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	readfile(t_file *file, t_pipex pipex)
{
	file->fd = open(file->filename, O_RDONLY);
	if (file->fd == -1)
	{
		if (errno == 13)
			ft_printf("bash: %s: Permission denied\n", file->filename);
		close_pipe(& pipex.info);
		free_pipex(pipex);
		print_error_exit(file->filename);
	}
	dup2(file->fd, STDIN_FILENO);
	close(file->fd);
}

void	writefile(t_file *file, t_pipex pipex)
{
	file->fd = open(file->filename, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (file->fd == -1)
	{
		if (errno == 13)
			ft_printf("bash: %s: Permission denied\n", file->filename);
		close_pipe(& pipex.info);
		free_pipex(pipex);
		print_error_exit(file->filename);
	}
	dup2(file->fd, STDOUT_FILENO);
	close(file->fd);
}
