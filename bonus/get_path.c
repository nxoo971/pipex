/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:58:46 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/05 21:32:51 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*\*/
const char	**set_paths(char **paths, int *size)
{
	const char	**res;
	int			i;

	res = ft_calloc(sizeof(char *), ft_arraylen(paths) + 1);
	if (!res)
		return (0);
	i = 0;
	res[i] = ft_strjoin(paths[i] + 5, "/");
	while (paths[++i])
	{
		res[i] = ft_strjoin(paths[i], "/");
		if (!res[i])
		{
			ft_arrayndel((char **)res, i);
			return (0);
		}
	}
	*size = i;
	return (res);
}

const char	**env_paths_to_string(char **env, int *size)
{
	int			i;
	char		**paths;
	const char	**res;

	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			paths = ft_split(env[i], ':');
			if (!paths)
				break ;
			res = set_paths(paths, size);
			ft_arraydel(paths);
			return (res);
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