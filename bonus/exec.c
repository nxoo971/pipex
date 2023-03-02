/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:39:09 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/02 08:28:05 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_plist *list, t_info *info)
{
	t_plist	*lst;
	int		path_id;
	char	*cmd;

	lst = list;
	path_id = valid_command(lst->command, *info);
	if (path_id == -1)
	{
		if (lst -> command)
			ft_printf("bash: %s: command not found\n", \
						lst->command, info -> status = 127);
		else
			ft_printf("bash: : command not found\n", info -> status = 127);
	}
	else
	{
		cmd = ft_strjoin(info -> env[path_id], lst->command);
		if (cmd)
		{
			execve(cmd, (char **)lst->option, (char **)info -> env);
			ft_memdel((void **)& cmd);
		}
	}
	close_pipe(info);
}

static
void	norm(t_plist *lst, t_pipex *pipex)
{
	close_pipe(& pipex->info);
	exec_cmd(lst, & pipex->info);
	free_pipex(*pipex);
	exit(pipex -> info.status);
}

void	exec(t_plist *lst, t_pipex *pipex, t_file **file, int index)
{
	if (index == 0)
	{
		dup2(pipex->info.fd[1], STDOUT_FILENO);
		if (pipex -> info.limiter != NULL)
		{
			dup2(pipex -> info.heredoc[0], STDIN_FILENO);
			close(pipex -> info.heredoc[0]);
		}
		else
			readfile(*file + IN, *pipex);
	}
	else if (index == pipex->head->length - 1)
	{
		dup2(pipex->info.prev_pipes, STDIN_FILENO);
		close(pipex->info.prev_pipes);
		writefile(*file + OUT, *pipex);
	}
	else
	{
		dup2(pipex->info.prev_pipes, STDIN_FILENO);
		close(pipex->info.prev_pipes);
		dup2(pipex->info.fd[1], STDOUT_FILENO);
	}
	norm(lst, pipex);
}
