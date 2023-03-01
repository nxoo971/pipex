/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:37:05 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/01 00:06:22 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe(t_info *info)
{
	close(info->fd[0]);
	close(info->fd[1]);
}

int	loop(t_pipex pipex, t_file file[2])
{
	int	index_pid;

	index_pid = 0;
	while (pipex.plist && index_pid < 1024)
	{
		if (pipe(pipex.info.fd) == -1)
			return (ft_printf("Pipe failed\n"));
		pipex.info.pids[index_pid] = fork();
		if (pipex.info.pids[index_pid] == -1)
		{
			ft_printf("Can't fork pid %d\n", index_pid);
			exit(EXIT_FAILURE);
		}
		if (pipex.info.pids[index_pid] == 0)
			exec(pipex.plist, & pipex, & file, index_pid);
		if (pipex.info.prev_pipes != -1)
			close(pipex.info.prev_pipes);
		pipex.info.prev_pipes = pipex.info.fd[0];
		close(pipex.info.fd[1]);
		index_pid++;
		pipex.plist = pipex.plist->prev;
	}
	close(pipex.info.fd[1]);
	close(pipex.info.prev_pipes);
	return (index_pid);
}

int	main(int ac, char **av, char **env)
{
	static t_pipex	pipex = {0};
	static t_info	info = {0, .prev_pipes = -1};
	static t_file	file[2] = {0};
	int				index_pid;
	int status = 0;

	if (!env || !*env || ac < 5)
		return (0);
	info.env = env_paths_to_string(env, & info.env_size);
	if (!info.env)
		return (0);
	parse_av(ac, av, & pipex, file);
	pipex.info = info;
	pipex.info.status = 0;
	index_pid = loop(pipex, file);
	while (--index_pid >= 0)
		waitpid(info.pids[index_pid], & status, 0);
	if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	free_pipex(pipex);
	exit (status);
}
