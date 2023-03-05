/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:58:46 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/05 21:32:35 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*\*/
const char	**set_paths(char **paths, int *size)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strjoin(paths[++i] + 5, "/");
	if (!tmp)
		return (0);
	ft_memdel((void **)& paths[i]);
	paths[i] = tmp;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (0);
		ft_memdel((void **)& paths[i]);
		paths[i] = tmp;
	}
	*size = i;
	return ((const char **)paths);
}

const char	**env_paths_to_string(char **env, int *size)
{
	int		i;
	char	**paths;

	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			paths = ft_split(env[i], ':');
			if (!paths)
				break ;
			return (set_paths(paths, size));
		}
	}
	return (0);
}

int	valid_command(const char *cmd, t_info info)
{
	int			i;
	static char	*joined;

	i = -1;
	joined = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) != 0)
			ft_printf("bash: %s: command not found\n", cmd);
		return (-2);
	}
	while (cmd && info.env[++i])
	{
		joined = ft_strjoin(info.env[i], cmd);
		if (access(joined, X_OK) == 0)
		{
			ft_memdel((void **)& joined);
			return (i);
		}
		ft_memdel((void **)& joined);
	}
	if (cmd)
		ft_printf("bash: %s: command not found\n", cmd);
	else
		ft_printf("bash: : command not found\n");
	return (-1);
}
/**/