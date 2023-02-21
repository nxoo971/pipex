/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 06:40:16 by jewancti          #+#    #+#             */
/*   Updated: 2023/02/18 08:30:21 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_to_pipe(t_pipex *pipex)
{
	char	*str;
	char	*tmp;

	tmp = ft_strjoin(pipex -> info.limiter, "\n");
	while (1)
	{
		str = get_next_line(0, 0);
		if (ft_strcmp(str, tmp) == 0)
			break ;
		ft_putstr_fd(str, pipex -> info.heredoc[1]);
		ft_memdel((void **)& str);
	}
	dup2(pipex -> info.heredoc[1], STDIN_FILENO);
	close(pipex -> info.heredoc[0]);
	close(pipex -> info.heredoc[1]);
	ft_memdel((void **)& tmp);
	get_next_line(0, 1);
}

int	is_heredoc(char **av, t_pipex *pipex)
{
	pid_t	pid;

	if (ft_strcmp(av[1], "here_doc"))
		return (EXIT_FAILURE);
	pipex -> info.limiter = av[2];
	pid = fork();	
	if (pid == -1)
		return (ft_printf("Can't fork pid"));
	if (pid == 0)
	{
		if (pipe(pipex -> info.heredoc) == -1)
			exit(EXIT_FAILURE);
		write_to_pipe(pipex);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, 0, 0);
	return (EXIT_SUCCESS);
}

void	parse_av(int ac, char **av, t_pipex *pipex, t_file file[2])
{
	char	**split;
	int		i;

	i = 2;
	pipex -> info.limiter = 0;
	if (is_heredoc(av, pipex) == EXIT_SUCCESS)
		i = 3;
	file[IN].filename = av[1];
	file[OUT].filename = av[ac - 1];
	while (i < ac - 1)
	{
		split = ft_split(av[i], ' ');
		if (!split)
		{
			ft_arraydel((char **)split);
			return ;
		}
		add_elem(& pipex->head, & pipex->plist, split[0], (const char **)split);
		ft_arraydel((char **)split);
		i++;
	}
}
