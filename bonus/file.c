/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:39:28 by jewancti          #+#    #+#             */
/*   Updated: 2023/02/18 08:16:07 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	readfile(t_pipex pipex, t_file *file)
{
	file->fd = open(file->filename, O_RDONLY);
	if (file->fd == -1)
		print_error_exit(pipex, file->filename);
	dup2(file->fd, STDIN_FILENO);
	close(file->fd);
}

void	writefile(t_pipex pipex, t_file *file)
{
	file->fd = open(file->filename, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (file->fd == -1)
		print_error_exit(pipex, file->filename);
	dup2(file->fd, STDOUT_FILENO);
	close(file->fd);
}
