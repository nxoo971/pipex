/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:54:56 by jewancti          #+#    #+#             */
/*   Updated: 2023/03/01 02:05:55 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipex(t_pipex pipex)
{
	t_plist	*tmp;
	t_plist	*lst;

	lst = pipex.head->first;
	if (pipex.info.limiter)
		close(pipex.info.heredoc[0]);
	ft_arraydel((char **)pipex.info.env);
	while (lst)
	{
		tmp = lst->prev;
		ft_arraydel((char **)lst->option);
		ft_memdel((void **)& lst);
		lst = tmp;
	}
	ft_memdel((void **)& pipex.head);
}
