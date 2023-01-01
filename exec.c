/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:39:09 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/30 19:19:26 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_plist *list, t_info info)
{
	t_plist	*lst;
	int		path_id;
	char	*cmd;

	lst = list;
	path_id = valid_command(lst->command, info);
	if (path_id == -1)
		ft_printf("%s: command not found\n", lst->command);
	else
	{
		cmd = ft_strjoin(info.env[path_id], lst->command);
		if (cmd)
		{
			execve(cmd, (char **)lst->option, (char **)info.env);
			ft_memdel((void **)& cmd);
		}
	}
}

void	exec(t_plist *lst, t_pipex *pipex, t_file (*file[2]), int index)
{
	if (index == 0)
	{
		readfile(*file + IN);
		dup2(pipex->info.fd[1], STDOUT_FILENO);
		close_pipe(& pipex->info);
		exec_cmd(lst, pipex->info);
		close_pipe(& pipex->info);
		ft_arraydel((void **)pipex->info.env);
		free_pipex(*pipex);
		exit(EXIT_FAILURE);
	}
	if (index == pipex->head->length - 1)
	{
		dup2(pipex->info.prev_pipes, STDIN_FILENO);
		close(pipex->info.prev_pipes);
		writefile(*file + OUT);
		close_pipe(& pipex->info);
		exec_cmd(lst, pipex->info);
		close_pipe(& pipex->info);
		ft_arraydel((void **)pipex->info.env);
		free_pipex(*pipex);
		exit(EXIT_FAILURE);
	}
	dup2(pipex->info.prev_pipes, STDIN_FILENO);
	close(pipex->info.prev_pipes);
	dup2(pipex->info.fd[1], STDOUT_FILENO);
	close_pipe(& pipex->info);
	exec_cmd(lst, pipex->info);
	ft_arraydel((void **)pipex->info.env);
	free_pipex(*pipex);
	exit(EXIT_FAILURE);
}
