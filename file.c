/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:39:28 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/30 14:12:21 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	readfile(t_file *file)
{
	file->fd = open(file->filename, O_RDONLY);
	if (file->fd == -1)
		print_error_exit(file->filename);
	dup2(file->fd, STDIN_FILENO);
	close(file->fd);
}

void	writefile(t_file *file)
{
	file->fd = open(file->filename, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (file->fd == -1)
		print_error_exit(file->filename);
	dup2(file->fd, STDOUT_FILENO);
	close(file->fd);
}
