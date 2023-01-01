/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 06:40:16 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/30 17:28:32 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_av(int ac, char **av, t_pipex *pipex, t_file file[2])
{
	char	**split;
	int		i;

	i = 2;
	file[IN].filename = av[1];
	file[OUT].filename = av[ac - 1];
	while (i < ac - 1)
	{
		split = ft_split(av[i], ' ');
		if (!split)
		{
			ft_arraydel((void **)split);
			return ;
		}
		add_elem(& pipex->head, & pipex->plist, split[0], (const char **)split);
		i++;
	}
}
